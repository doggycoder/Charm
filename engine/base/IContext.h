//
// Created by wuwang on 19-9-1.
//

#pragma once

#include "IRenderDevice.h"
#include "Logger.h"

class IContext{
public:
    virtual IRenderDevice*          getRenderDevice() = 0;
};