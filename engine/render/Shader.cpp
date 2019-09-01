//
// Created by wuwang on 19-8-29.
//

#include "Shader.h"


Shader::~Shader() {

}

void Shader::init(IContext *context) {
    IResObj::init(context);
    device = context->getRenderDevice();
}

void Shader::onLoad() {
    programId = context->getRenderDevice()->compile(code);
    isLoaded = true;
}

void Shader::setParam(MParam &param, float value) {
    device->setParam(programId, param, value);
}

void Shader::setParam(MParam &param, Vec2f &value) {
    device->setParam(programId, param, value);
}

void Shader::setParam(MParam &param, Vec3f &value) {
    device->setParam(programId, param, value);
}

void Shader::setParam(MParam &param, Vec4f &value) {
    device->setParam(programId, param, value);
}

void Shader::setParam(MParam &param, float *value, uint32_t unitCount, uint32_t unitSize) {
    device->setParam(programId, param, value, unitCount, unitSize);
}

void Shader::setParam(MParam &param, Matrix &mat) {
    device->setParam(programId, param, mat);
}

void Shader::setParam(MParam &param, ResPtr<Texture> texture) {
//    device->setParam(programId, param, texture);
}