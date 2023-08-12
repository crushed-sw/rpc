#ifndef __RPC__PROVIDER_HPP
#define __RPC__PROVIDER_HPP

#include "rpcApplication.hpp"
#include "rpcHeader.pb.h"
#include "logger.hpp"

#include "google/protobuf/service.h"
#include "google/protobuf/descriptor.h"

#include <thread>
#include <unordered_map>

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>

class RpcProvider {
public:
    void notifyService(google::protobuf::Service* service);
    void run();

private:
    void onConntion(const muduo::net::TcpConnectionPtr& conn);
    void onMessage(const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf, muduo::Timestamp time);
    void sendRpcResponse(const muduo::net::TcpConnectionPtr& conn, google::protobuf::Message* message);

    muduo::net::EventLoop eventLoop_;

    struct ServerInfo {
        google::protobuf::Service* server_;
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor*> methodMap_;
    };
    std::unordered_map<std::string, ServerInfo> serverMap_;
};

#endif //__RPC__PROVIDER_HPP
