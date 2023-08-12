#include "../include/rpcController.hpp"

RpcContoller::RpcContoller() : failed_(false), errorMessage_("") {}

void RpcContoller::Reset() {
    failed_ = false;
    errorMessage_ = "";
}

bool RpcContoller::Failed() const {
    return failed_;
}

std::string RpcContoller::ErrorText() const {
    return errorMessage_;
}

void RpcContoller::SetFailed(const std::string& reason) {
    failed_ = true;
    errorMessage_ = reason;
}


void RpcContoller::StartCancel() {}
bool RpcContoller::IsCanceled() const { return false; }
void RpcContoller::NotifyOnCancel(google::protobuf::Closure* callback) {}
