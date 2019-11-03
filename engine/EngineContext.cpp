//
// Created by wuwang on 19-10-7.
//

#include "EngineContext.h"
#include "opengl/OpenGLDevice.h"
#include "render/Renderer.h"

EngineContext::~EngineContext() {
    delete device;
    delete renderer;
}

void EngineContext::init() {
    device = new OpenGLDevice();
    renderer = new Renderer();
    renderer->init(this);
}

IRenderDevice* EngineContext::getRenderDevice() {
    return device;
}

Renderer* EngineContext::getRenderer() {
    return renderer;
}