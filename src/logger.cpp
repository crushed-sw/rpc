#include "../include/logger.hpp"

#include <fstream>
#include <iostream>

Logger::Logger() {
    std::thread t(&Logger::writeTask, this);
    t.detach();
}

Logger& Logger::getInstance() {
    static Logger logger;
    return logger;
}

void Logger::setLevel(LogLevel level) {
    level_ = level;
}

void Logger::log(const std::string& str) {
    queue_.push(str);
}

void Logger::writeTask() {
    while(true) {
        time_t now = time(nullptr);
        tm* nowtm = localtime(&now);
        timeval time = {};
        gettimeofday(&time, nullptr);
        int million = time.tv_usec;

        char dataBuf[11] = {};
        sprintf(dataBuf, "%04d_%02d_%02d", nowtm->tm_year + 1900, nowtm->tm_mon + 1, nowtm->tm_mday);

        char timeBuf[16] = {};
        sprintf(timeBuf, "%02d:%02d:%02d.%06d", nowtm->tm_hour, nowtm->tm_min, nowtm->tm_sec, million);
        
        char fileName[128] = {};
        sprintf(fileName, "log/%s.log", dataBuf);

        std::fstream fs(fileName, std::ios::app);
        if(!fs.is_open()) {
            std::cout << fileName << " open error!" << std::endl;
            exit(EXIT_FAILURE);
        }

        std::string str = queue_.pop();
        fs << dataBuf << " " << timeBuf << getLevelString(level_) << str << std::endl;

        fs.close();
    }
}

std::string Logger::getLevelString(LogLevel level) {
    if(level == LogLevel::Info) {
        return " [info ] ";
    } else if(level == LogLevel::Error) {
        return " [error] ";
    } else if(level == LogLevel::Warn) {
        return " [warn ] ";
    } else if(level == LogLevel::Debug) {
        return " [debug] ";
    }
    return "";
}
