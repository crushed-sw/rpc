#ifndef __RPC_CHANNEL_HPP
#define __RPC_CHANNEL_HPP

#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

#include <muduo/net/TcpClient.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>

#include <string>

#include "rpcHeader.pb.h"
#include "rpcApplication.hpp"
#include "logger.hpp"

class RpcChannel : public google::protobuf::RpcChannel {
public:
    void CallMethod(const google::protobuf::MethodDescriptor* method, 
                    google::protobuf::RpcController* controller, 
                    const google::protobuf::Message* request, 
                    google::protobuf::Message* response, 
                    google::protobuf::Closure* done);

private:
    void onConntion(const muduo::net::TcpConnectionPtr& conn, const std::string& str);
    void onMessage(const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf, 
                   muduo::Timestamp time, google::protobuf::Message*& response, 
                   muduo::net::EventLoop* loop, google::protobuf::RpcController* controller);
};

#endif //__RPC_CHANNEL_HPP
