#include "../include/rpcProvider.hpp"

void RpcProvider::notifyService(google::protobuf::Service* service) {
    ServerInfo info;

    const google::protobuf::ServiceDescriptor* serverDesc = service->GetDescriptor();
    std::string serverName = serverDesc->name();
    int methodCount = serverDesc->method_count();

    info.server_ = service;
    for(int i = 0; i != methodCount; ++i) {
        const google::protobuf::MethodDescriptor* methodDesc = serverDesc->method(i);
        std::string methodName = methodDesc->name();
        info.methodMap_.insert({methodName, methodDesc});
    }

    serverMap_.insert({serverName, info});
}

void RpcProvider::run() {
    std::string ip = RpcApplication::getConfig().getValue("rpcserverip");
    int port = std::atoi(RpcApplication::getConfig().getValue("rpcserverport").c_str());
    muduo::net::InetAddress address(ip, port);

    muduo::net::TcpServer tcpServer(&eventLoop_, address, "RpcProvider");
    tcpServer.setConnectionCallback(std::bind(&RpcProvider::onConntion, this, std::placeholders::_1));
    tcpServer.setMessageCallback(std::bind(&RpcProvider::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    tcpServer.setThreadNum(std::thread::hardware_concurrency());

    LogInfo("rpcProvider start service at %s:%d", ip.c_str(), port);

    tcpServer.start();
    eventLoop_.loop();
}

void RpcProvider::onConntion(const muduo::net::TcpConnectionPtr& conn) {
    if(!conn->connected()) {
        conn->shutdown();
    }
}

void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf, muduo::Timestamp time) {
    std::string str = buf->retrieveAllAsString();
    uint32_t headerSize = 0;
    str.copy((char*)&headerSize, 4, 0);

    std::string headerStr = str.substr(4, headerSize);
    rpc::RpcHeader rpcHeader;

    std::string serviceName;
    std::string methodName;
    uint32_t argsSize;

    if(rpcHeader.ParseFromString(headerStr)) {
        serviceName = rpcHeader.servicename();
        methodName = rpcHeader.methodname();
        argsSize = rpcHeader.argssize();
    } else {
        LogError("rpcHeader: %s error!", headerStr.c_str());
        return;
    }

    std::string argsStr = str.substr(4 + headerSize, argsSize);

    auto iter = serverMap_.find(serviceName);
    if(iter == serverMap_.end()) {
        LogError("serviceName: %s not excited!", serviceName.c_str());
        return;
    }

    google::protobuf::Service* service = iter->second.server_;

    auto methodIter = iter->second.methodMap_.find(methodName);
    if(methodIter == iter->second.methodMap_.end()) {
        LogError("methodName: %s not excited!", methodName.c_str());
        return;
    }

    const google::protobuf::MethodDescriptor* methodDesc = methodIter->second;

    google::protobuf::Message* request = service->GetRequestPrototype(methodDesc).New();
    if(!request->ParseFromString(argsStr)) {
        LogError("request parse \"%s\" error", argsStr.c_str());
        return;
    }

    google::protobuf::Message* response = service->GetResponsePrototype(methodDesc).New();

    google::protobuf::Closure* done = google::protobuf::NewCallback<RpcProvider, const muduo::net::TcpConnectionPtr&, google::protobuf::Message*>
                                                                    (this, &RpcProvider::sendRpcResponse, conn, response);

    service->CallMethod(methodDesc, nullptr, request, response, done);
}

void RpcProvider::sendRpcResponse(const muduo::net::TcpConnectionPtr& conn, google::protobuf::Message* message) {
    std::string sendStr;
    if(message->SerializeToString(&sendStr)) {
        conn->send(sendStr);
    } else {
        LogError("serialize response error");
    }
    conn->shutdown();
}
