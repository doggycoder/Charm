//
// Created by wuwang on 19-9-1.
//

#pragma once

#include "IRenderDevice.h"
#include "Logger.h"

class Renderer;

class IContext{
public:
    virtual ~IContext() = default;
    virtual void                    init() = 0;
    virtual IRenderDevice*          getRenderDevice() = 0;
    virtual Renderer*               getRenderer() = 0;
};