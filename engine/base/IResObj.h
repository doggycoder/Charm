//
// Created by wuwang on 19-9-1.
//

#pragma once

#include "IContext.h"

class IResObj{
protected:
    IContext* context{nullptr};
    std::string name;
public:
    virtual void init(IContext* context){
        this->context = context;
        if(name.empty()){
            name = std::to_string(*(uint64_t *)(void *)this);
        }
    }

    virtual void onLoad() = 0;

    virtual const char * getName(){ return name.c_str();}
};

template <typename T>
class ResPtr{
public:
    template <typename A>
    class RPtr{
    private:
        friend class SPtr<A>;
        A * t;
        int count;

        explicit RPtr(A * t):t(t),count(1){}
        ~RPtr(){delete t;}
    };
private:
    T * t{nullptr};
public:
    ResPtr(T * t){
        this->t = t;
    }

    ResPtr<T>&operator=(T * t){

    }
};