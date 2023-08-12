#ifndef __LOGGER_HPP
#define __LOGGER_HPP

#include "lockQueue.hpp"

#include <thread>
#include <sys/time.h>

enum class LogLevel {
    Info,
    Warn,
    Error,
    Debug
};

class Logger {
public:
    static Logger& getInstance();

    void setLevel(LogLevel level);
    void log(const std::string& str);

private:
    Logger();

    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger operator=(const Logger&) = delete;
    Logger operator=(Logger&&) = delete;

    void writeTask();
    std::string getLevelString(LogLevel level);

    LogLevel level_;
    LockQueue<std::string> queue_;
};

#define LogInfo(logmsgformat, ...)                            \
        do {                                                  \
            Logger& logger = Logger::getInstance();           \
            logger.setLevel(LogLevel::Info);                  \
            char buf[1024];                                   \
            snprintf(buf, 1024, logmsgformat, ##__VA_ARGS__); \
            logger.log(buf);                                  \
        } while(0);

#define LogError(logmsgformat, ...)                           \
        do {                                                  \
            Logger& logger = Logger::getInstance();           \
            logger.setLevel(LogLevel::Error);                 \
            char buf[1024];                                   \
            snprintf(buf, 1024, logmsgformat, ##__VA_ARGS__); \
            logger.log(buf);                                  \
        } while(0);

#define LogWarn(logmsgformat, ...)                            \
        do {                                                  \
            Logger& logger = Logger::getInstance();           \
            logger.setLevel(LogLevel::Warn);                  \
            char buf[1024];                                   \
            snprintf(buf, 1024, logmsgformat, ##__VA_ARGS__); \
            logger.log(buf);                                  \
        } while(0);

#define LogDebug(logmsgformat, ...)                           \
        do {                                                  \
            Logger& logger = Logger::getInstance();           \
            logger.setLevel(LogLevel::Debug);                 \
            char buf[1024];                                   \
            snprintf(buf, 1024, logmsgformat, ##__VA_ARGS__); \
            logger.log(buf);                                  \
        } while(0);
#endif //__LOGGER_HPP
