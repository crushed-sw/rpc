#ifndef __RPC_CONFIG_HPP
#define __RPC_CONFIG_HPP

#include <unordered_map>
#include <string>

class RpcConfig {
public:
    void LoadConfigFile(const char* file);
    std::string getValue(const std::string& str);

private:
    void trim(std::string& str);

    std::unordered_map<std::string, std::string> map_;
};

#endif //__RPC_CONFIG_HPP
