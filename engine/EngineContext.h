//
// Created by wuwang on 19-10-7.
//

#pragma once

#include <base/IContext.h>

class IRenderDevice;

class EngineContext : public IContext {
private:
    IRenderDevice*          device{nullptr};
    Renderer*               renderer{nullptr};
public:
    ~EngineContext() override;
    void                    init() override;
    Renderer*               getRenderer() override;
    IRenderDevice*          getRenderDevice() override;
};


