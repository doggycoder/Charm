//
// Created by wuwang on 19-9-1.
//

#pragma once

#include <sstream>
#include <functional>

enum LoggerType{
    eLT_INFO,
    eLT_DEBUG,
    eLT_WARMING,
    eLT_ERROR,
    eLT_REPORT
};

class LoggerOutType{
public:
    LoggerType type{eLT_INFO};
    int key{0};
    void * extra{nullptr};
    LoggerOutType(LoggerType type,  int key, void * extra = nullptr):
    type(type), key(key), extra(extra){}
};

using LoggerFunction = std::function<void(LoggerType, int, const char *, void *)>;

class Logger {
private:
    class InnerLogger{

    private:
        std::stringstream temp;
        LoggerFunction output;
    public:

        virtual void log(LoggerType type, int key, const char * info, void * extra);
        virtual void log(LoggerType type, int key, const char * info){
            log(type, key, info, nullptr);
        }

        void setLoggerFunction(LoggerFunction function){
            output = std::move(function);
        };

        template <typename T>
        InnerLogger& operator<<(T t){
            temp << t;
            return *this;
        };

        virtual void log(LoggerType type, int key, void * extra){
            log(type, key, temp.str().c_str(), extra);
            temp.clear();
        }

        virtual void log(LoggerType type, int key){
            log(type, key, (void *)nullptr);
        }

    };

public:

    static InnerLogger out;

    static LoggerOutType End(LoggerType type = eLT_INFO, int key = 0, void * extra = nullptr){
        return  {type, key, extra};
    }

    static LoggerOutType Err(int key = 0, void * extra = nullptr){
        return End(eLT_ERROR, key, extra);
    }

    static void setLoggerFunction(LoggerFunction func){
        out.setLoggerFunction(std::move(func));
    }

};

