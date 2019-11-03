//
// Created by wuwang on 19-10-7.
//

#include <iostream>
#include "EffectRenderer.h"
#include "EngineContext.h"
#include "render/Mesh.h"
#include "render/Renderer.h"

EffectRenderer::EffectRenderer() {
    context = new EngineContext();
    mesh = Mesh::createQuad();
}

void EffectRenderer::onInit() {
    context->init();
}

void EffectRenderer::onSizeChanged(int width, int height) {
    if(this->width != width || this->height != height){
        this->width = width;
        this->height = height;
    }
}

void EffectRenderer::onDrawFrame() {
    context->getRenderDevice()->clear(Color4f(0.3f, 0.5f, 0.2f, 1.0f));
    context->getRenderer()->renderMesh(mesh.get());
}