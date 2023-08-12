#include <iostream>

#include "../user.pb.h"
#include "../../include/rpcApplication.hpp"
#include "../../include/rpcProvider.hpp"

class UserService : public rpc::UserServiceRpc {
public:
    bool Login(const std::string& username, const std::string& password) {
        std::cout << "login success" << std::endl;
        return true;
    }

    bool Register(const std::string& username, const std::string& password) {
        std::cout << "register success" << std::endl;
        return true;
    }

    void Login(::google::protobuf::RpcController* controller,
               const ::rpc::LoginRequest* request,
               ::rpc::LoginResponse* response,
               ::google::protobuf::Closure* done) {

        std::string username = request->username();
        std::string password = request->password();
        
        bool login_result = Login(username, password);

        response->set_success(login_result);
        rpc::ResultCode* result = response->mutable_result();

        if(login_result) {
            result->set_errcode(0);
            result->set_errmsg("");
        } else {
            result->set_errcode(1);
            result->set_errmsg("login error");
        }

        done->Run();
    }

    void Register(::google::protobuf::RpcController* controller,
                  const ::rpc::RegisterRequest* request,
                  ::rpc::RegisterResponse* response,
                  ::google::protobuf::Closure* done) {

        std::string username = request->username();
        std::string password = request->password();

        bool register_result = Register(username, password);

        response->set_success(register_result);
        rpc::ResultCode* result = response->mutable_result();

        if(register_result) {
            result->set_errcode(0);
            result->set_errmsg("");
        } else {
            result->set_errcode(1);
            result->set_errmsg("register error");
        }

        done->Run();
    }
};

int main(int argc, char** argv) {
    RpcApplication::init(argc, argv);

    RpcProvider provider;
    provider.notifyService(new UserService());

    provider.run();
}
