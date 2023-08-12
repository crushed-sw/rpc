#include "../user.pb.h"
#include "../../include/rpcApplication.hpp"
#include "../../include/rpcChannel.hpp"
#include "../../include/rpcController.hpp"

int main(int argc, char** argv) {
    RpcApplication::init(argc, argv);

    rpc::UserServiceRpc_Stub stub(new RpcChannel());
    RpcContoller controller;
    
    rpc::RegisterRequest registerRequest;
    registerRequest.set_username("crushed");
    registerRequest.set_password("123456");

    rpc::RegisterResponse registerResponse;

    stub.Register(&controller, &registerRequest, &registerResponse, nullptr);

    if(!controller.Failed()) {
        std::cout << "register success " << registerResponse.success() << std::endl;
        std::cout << registerResponse.result().errcode() << std::endl;
        std::cout << registerResponse.result().errmsg() << std::endl;
    } else {
        std::cout << "register error " << registerResponse.result().errcode() << std::endl;
    }

    rpc::LoginRequest loginRequest;
    loginRequest.set_username("crushed");
    loginRequest.set_password("123456");

    rpc::LoginResponse loginResponse;

    stub.Login(nullptr, &loginRequest, &loginResponse, nullptr);

    if(!controller.Failed()) {
        std::cout << "login success " << loginResponse.success() << std::endl;
        std::cout << loginResponse.result().errcode() << std::endl;
        std::cout << loginResponse.result().errmsg() << std::endl;
    } else {
        std::cout << "login error " << loginResponse.result().errcode() << std::endl;
    }

    return 0;
}
