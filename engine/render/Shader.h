//
// Created by wuwang on 19-8-29.
//
#pragma once

#include <string>
#include "base/IResObj.h"
#include <base/IRenderDevice.h>
#include "base/MParam.h"
#include "Texture.h"

class Shader : public IResObj {
private:
    char * code;
    uint64_t programId{0};
    bool isLoaded{false};
    IRenderDevice * device{nullptr};
public:
    explicit Shader(char * code):code(code){};
    ~Shader();

    void    init(IContext * context) override;

    void    onLoad() override;

    virtual void setParam(MParam& param, float value);

    virtual void setParam(MParam& param, Vec2f &value);

    virtual void setParam(MParam& param, Vec3f &value);

    virtual void setParam(MParam& param, Vec4f &value);

    virtual void setParam(MParam& param, float *value, uint32_t unitCount, uint32_t unitSize);

    virtual void setParam(MParam& param, Matrix &mat);

    virtual void setParam(MParam& param, ResPtr<Texture> texture);
};
