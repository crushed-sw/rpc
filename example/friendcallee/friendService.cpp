#include "../friend.pb.h"
#include "../../include/rpcApplication.hpp"
#include "../../include/rpcProvider.hpp"
#include "../../include/logger.hpp"

#include <iostream>
#include <vector>

class FriendService : public rpc::FriendService {
public:
    std::vector<std::string> getFriendList(int userid) {
        std::vector<std::string> ans;
        if(userid == -1) {
            ans.emplace_back("zhangsan");
            ans.emplace_back("lisi");
            ans.emplace_back("wangwu");
            ans.emplace_back("zhaoliu");
        } else {
            ans.emplace_back("zhangsan");
        }

        return ans;
    }

    void getFriendList(::google::protobuf::RpcController* controller,
                       const ::rpc::FriendRequest* request,
                       ::rpc::FriendResponse* response,
                       ::google::protobuf::Closure* done) {
    
        uint32_t userid = request->userid();
        std::vector<std::string> friends = getFriendList(userid);

        rpc::ResultCode* result = response->mutable_result();
        result->set_errcode(0);
        result->set_errmsg("");
        
        for(const std::string& str : friends) {
            std::string* fd = response->add_friends();
            *fd = str;
        }

        done->Run();
    }
};

int main(int argc, char** argv) {
    LogInfo("log info message");
    LogInfo("%s_%s_%d", __FILE__, __FUNCTION__, __LINE__);

    RpcApplication::init(argc, argv);

    RpcProvider rpcProvider;
    rpcProvider.notifyService(new FriendService());

    rpcProvider.run();
}
