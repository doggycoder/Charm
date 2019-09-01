//
// Created by wuwang on 19-9-1.
//

#pragma once

#include "IContext.h"

class IResObj{
protected:
    IContext* context{nullptr};
public:
    virtual void init(IContext* context){
        this->context = context;
    }

    virtual void onLoad() = 0;
};

template <typename T>
class ResPtr{
private:
    T * t;
public:
    ResPtr(T * t){
        this->t = t;
    }
};