#ifndef __RPC_APPLICATION_HPP
#define __RPC_APPLICATION_HPP

#include "../include/rpcConfig.hpp"

class RpcApplication {
public:
    static void init(int argc, char** argv);
    static RpcApplication& getInstance();
    static RpcConfig& getConfig();

private:
    RpcApplication();

    RpcApplication(const RpcApplication&) = delete;
    RpcApplication(RpcApplication&&) = delete;
    RpcApplication operator=(const RpcApplication&) = delete;
    RpcApplication operator=(RpcApplication&&) = delete;

    static RpcConfig config_;
};

#endif //__RPC_APPLICATION_HPP
