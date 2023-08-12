#include "../include/rpcChannel.hpp"

void RpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method, 
                            google::protobuf::RpcController* controller, 
                            const google::protobuf::Message* request, 
                            google::protobuf::Message* response, 
                            google::protobuf::Closure* done) {

    const google::protobuf::ServiceDescriptor* serviceDesc = method->service();
    std::string serviceName = serviceDesc->name();
    std::string methodName = method->name();

    uint32_t argSize = 0;
    std::string argsList;
    if(request->SerializeToString(&argsList)) {
        argSize = argsList.size();
    } else {
        std::string errmsg = "request serialize error";
        LogError("%s", errmsg.c_str());
        controller->SetFailed(errmsg);
        return;
    }

    rpc::RpcHeader header;
    header.set_servicename(serviceName);
    header.set_methodname(methodName);
    header.set_argssize(argSize);

    uint32_t headerSize = 0;
    std::string headerStr;
    if(header.SerializeToString(&headerStr)) {
        headerSize = headerStr.size();
    } else {
        std::string errmsg = "headerStr serialize error";
        LogError("%s", errmsg.c_str());
        controller->SetFailed(errmsg);
        return;
    }

    std::string sendRpcStr;
    sendRpcStr.insert(0, std::string((char*)&headerSize, 4));
    sendRpcStr += headerStr;
    sendRpcStr += argsList;

    std::string ip = RpcApplication::getConfig().getValue("rpcserverip");
    int port = std::atoi(RpcApplication::getConfig().getValue("rpcserverport").c_str());
    muduo::net::InetAddress address(ip, port);

    muduo::net::EventLoop loop;
    muduo::net::TcpClient client(&loop, address, "RpcConstmer");
    client.setConnectionCallback(std::bind(&RpcChannel::onConntion, this, std::placeholders::_1, sendRpcStr));
    client.setMessageCallback(std::bind(&RpcChannel::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, response, &loop, controller));

    client.connect();
    loop.loop();
}

void RpcChannel::onConntion(const muduo::net::TcpConnectionPtr& conn, const std::string& str) {
    if(!conn->connected()) {
        conn->shutdown();
        return;
    }

    conn->send(str);
}

void RpcChannel::onMessage(const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf, muduo::Timestamp time, 
                           google::protobuf::Message*& response, muduo::net::EventLoop* loop, google::protobuf::RpcController* controller) {
    std::string str = buf->retrieveAllAsString();
    if(!response->ParseFromString(str)) {
        std::string errmsg = "parse error";
        LogError("%s", errmsg.c_str());
        controller->SetFailed(errmsg);
    }

    loop->quit();
}
