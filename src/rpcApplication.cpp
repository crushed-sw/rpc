#include "../include/rpcApplication.hpp"

#include <iostream>
#include <unistd.h>

RpcConfig RpcApplication::config_;

void showHelp() {
    std::cout << "format: command -i <configfile>" << std::endl;
}

RpcApplication::RpcApplication() {}

void RpcApplication::init(int argc, char** argv) {
    if(argc < 2) {
        showHelp();
        exit(EXIT_FAILURE);
    }

    int c = 0;
    std::string configFile;
    while((c = getopt(argc, argv, "i:")) != -1) {
        switch(c) {
            case 'i':
                configFile = optarg;
                break;
            case '?':
            case ':':
            default:
                showHelp();
                exit(EXIT_FAILURE);
                break;
        }
    }

    config_.LoadConfigFile(configFile.c_str());
}

RpcApplication& RpcApplication::getInstance() {
    static RpcApplication app;
    return app;
}

RpcConfig& RpcApplication::getConfig() {
    return config_;
}
