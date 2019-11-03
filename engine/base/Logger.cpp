//
// Created by wuwang on 19-9-1.
//

#include "Logger.h"

Logger::InnerLogger Logger::out; // NOLINT

void Logger::InnerLogger::log(LoggerType type, int key, const char *info, void *extra) {
    if(output){
        output(type, key, info, extra);
    }
}

template <>
Logger::InnerLogger& Logger::InnerLogger::operator<<(LoggerOutType t){
    log(t.type, t.key, t.extra);
    return *this;
}