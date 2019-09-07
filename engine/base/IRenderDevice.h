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

enum DrawType{
    eDT_Element = 0x0000,
    eDT_Points = 0x0001,
    eDT_Lines,
    eDT_LineLoop,
    eDT_LineStrip,
    eDT_Triangles,
    eDT_TriangleFan,
    eDT_TriangleStrip,
    eDT_Array = 0x1000,
};

class AttributeType{
public:
    AttributeType(uint8_t size,std::string name)
            :size(size),name(std::move(name)){}

    uint8_t size{3};
    std::string name;
};

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
