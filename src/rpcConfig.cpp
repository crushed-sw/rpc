#include "../include/rpcConfig.hpp"

#include <iostream>
#include <fstream>

void RpcConfig::LoadConfigFile(const char* file) {
    std::fstream fs(file);
    if(!fs.is_open()) {
        std::cout << file << " is not exist!" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string str;
    while(std::getline(fs, str)) {
        trim(str);

        if(str.empty() || str[0] == '#') {
            continue;
        }

        int index = str.find('=');
        if(index == -1) {
            continue;
        }

        std::string key = str.substr(0, index);
        trim(key);
        std::string value = str.substr(index + 1, str.size() - index);
        trim(value);

        map_.insert({key, value});
    }
}

std::string RpcConfig::getValue(const std::string& str) {
    auto iter = map_.find(str);
    if(iter == map_.end()) {
        return "";
    }
    return iter->second;
}

void RpcConfig::trim(std::string& str) {
    int index = str.find_first_not_of(' ');
    if(index != -1) {
        str = str.substr(index, str.size() - index);
    }

    index = str.find_last_not_of(' ');
    if(index != -1) {
        str = str.substr(0, index + 1);
    }
}
