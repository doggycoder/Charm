//
// Created by wuwang on 19-8-29.
//
#pragma once

#include "Shader.h"
#include <string>
#include <base/Vec.h>
#include <base/Matrix.h>
#include "base/MParam.h"
#include "Texture.h"
#include <typeinfo>
#include <map>

class Material : public IResObj {
private:
    using NxNf = std::tuple<float *, uint32_t, uint32_t>;
    std::map<MParam, float> paramFloat;
    std::map<MParam, Vec2f> paramVec2f;
    std::map<MParam, Vec3f> paramVec3f;
    std::map<MParam, Vec4f> paramVec4f;
    std::map<MParam, Matrix> paramMatrix;
    std::map<MParam, NxNf> paramNxNf;
    std::map<MParam, ResPtr<Texture>> paramTexture;

    SPtr<Shader>    shader;

public:
    virtual void setShader(SPtr<Shader> shader);

    virtual void setParam(MParam& param, float value);

    virtual void setParam(MParam& param, Vec2f &value);

    virtual void setParam(MParam& param, Vec3f &value);

    virtual void setParam(MParam& param, Vec4f &value);

    virtual void setParam(MParam& param, float *value, uint32_t unitCount, uint32_t unitSize);

    virtual void setParam(MParam& param, Matrix &mat);

    virtual void setParam(MParam& param, ResPtr<Texture> texture);

    virtual bool apply();

};