#ifndef __RPC_CONTROLLER_HPP
#define __RPC_CONTROLLER_HPP

#include <google/protobuf/service.h>

class RpcContoller : public google::protobuf::RpcController {
public:
    RpcContoller();
    void Reset();
    bool Failed() const;
    std::string ErrorText() const;
    void SetFailed(const std::string& reason);

    void StartCancel();
    bool IsCanceled() const;
    void NotifyOnCancel(google::protobuf::Closure* callback);
private:
    bool failed_;
    std::string errorMessage_;
};

#endif //__RPC_CONTROLLER_HPP
