//
// Created by wuwang on 19-8-29.
//

#include "Material.h"

void Material::setShader(SPtr<Shader>& shader) {
    this->shader = shader;
}

void Material::init(IContext *context) {
    if(shader){
        shader->init(context);
    }
}

void Material::onLoad() {
    if(shader){
        shader->onLoad();
    }
}

void Material::setParam(MParam &param, float t) {
    paramFloat[param] = t;
}

void Material::setParam(MParam &param, Vec2f &value) {
    paramVec2f[param] = value;
}

void Material::setParam(MParam &param, Vec3f &value) {
    paramVec3f[param] = value;
}

void Material::setParam(MParam &param, Vec4f &value) {
    paramVec4f[param] = value;
}

void Material::setParam(MParam &param, float *value, uint32_t unitCount, uint32_t unitSize) {
    paramNxNf[param] = std::make_tuple(value, unitCount, unitSize);
}

void Material::setParam(MParam &param, Matrix &mat) {
    paramMatrix[param] = mat;
}

void Material::setParam(MParam &param, ResPtr<Texture> texture) {
    paramTexture[param] = texture;
}

bool Material::apply() {
    for(auto param : paramFloat){
        shader->setParam((MParam&)param.first, param.second);
    }
    for(auto param : paramVec2f){
        shader->setParam((MParam&)param.first, param.second);
    }
    for(auto param : paramVec3f){
        shader->setParam((MParam&)param.first, param.second);
    }
    for(auto param : paramVec4f){
        shader->setParam((MParam&)param.first, param.second);
    }
    for(auto param : paramMatrix){
        shader->setParam((MParam&)param.first, param.second);
    }
    for(auto param : paramNxNf){
        shader->setParam((MParam&)param.first, std::get<0>(param.second),
                std::get<1>(param.second), std::get<2>(param.second));
    }
    for(auto param : paramTexture){
        shader->setParam((MParam&)param.first, param.second);
    }
    return true;
}
