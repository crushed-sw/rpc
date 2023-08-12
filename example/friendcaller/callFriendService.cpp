#include "../friend.pb.h"
#include "../../include/rpcApplication.hpp"
#include "../../include/rpcChannel.hpp"
#include "../../include/rpcController.hpp"

int main(int argc, char** argv) {
    RpcApplication::init(argc, argv);

    rpc::FriendService_Stub stub(new RpcChannel());
    RpcContoller controller;

    rpc::FriendRequest request;
    request.set_userid(-1);

    rpc::FriendResponse response;

    stub.getFriendList(&controller, &request, &response, nullptr);

    if(!controller.Failed()) {
        int size = response.friends_size();
        for(int i = 0; i != size; ++i) {
            std::string str = response.friends(i);
            std::cout << str << std::endl;
        }
    } else {
        std::cout << "error code: " << response.result().errcode() << std::endl;
        std::cout << "error message: " << response.result().errmsg() << std::endl;
    }

    return 0;
}
