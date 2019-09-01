//
// Created by wuwang on 19-8-29.
//
#pragma once

#include <cstdint>
#include "base/Base.h"
#include "base/Vec.h"
#include "base/Matrix.h"
#include "MParam.h"
#include <string>

class IRenderDevice {
public:

    virtual void open() = 0;

    virtual void close() = 0;

    virtual uint64_t compile(const char * code) = 0;

    virtual void setParam(uint64_t program, MParam& key, float value) = 0;

    virtual void setParam(uint64_t program, MParam& key, Vec2f &value) = 0;

    virtual void setParam(uint64_t program, MParam& key, Vec3f &value) = 0;

    virtual void setParam(uint64_t program, MParam& key, Vec4f &value) = 0;

    virtual void setParam(uint64_t program, MParam& key, float *value, uint32_t unitCount, uint32_t unitSize) = 0;

    virtual void setParam(uint64_t program, MParam& key, Matrix &mat) = 0;

    virtual bool checkParam(uint64_t programId, MParam& key) = 0;
};
