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
    eDT_Array_Points = eDT_Points | eDT_Array,
    eDT_Array_Lines,
    eDT_Array_LineLoop,
    eDT_Array_LineStrip,
    eDT_Array_Triangles,
    eDT_Array_TriangleFan,
    eDT_Array_TriangleStrip,
};

class AttributeType{
public:
    AttributeType(uint8_t size,std::string name)
            :size(size),name(std::move(name)){}

    uint8_t size{3};
    std::string name;
    uint32_t offset{0};
};

class IRenderDevice {
public:
    virtual ~IRenderDevice() = default;

    virtual void open() = 0;

    virtual void close() = 0;

    virtual uint64_t compile(const char * code) = 0;

    virtual void clear(Color4f c) = 0;

    virtual void setParam(uint64_t program, MParam& key, float value) = 0;

    virtual void setParam(uint64_t program, MParam& key, Vec2f &value) = 0;

    virtual void setParam(uint64_t program, MParam& key, Vec3f &value) = 0;

    virtual void setParam(uint64_t program, MParam& key, Vec4f &value) = 0;

    virtual void setParam(uint64_t program, MParam& key, float *value, uint32_t unitCount, uint32_t unitSize) = 0;

    virtual void setParam(uint64_t program, MParam& key, Matrix &mat) = 0;

    virtual bool checkParam(uint64_t programId, MParam& key) = 0;

    virtual void setVertexes(uint64_t program, MParam& key, AttributeType &type, uint32_t stride,
                            float * data, uint32_t dataLength, uint32_t updateOffset) = 0;

    virtual void setIndexes(uint64_t& ibo, uint32_t* data, uint32_t dataLength, uint32_t updateOffset, bool update) = 0;

    virtual void render(uint64_t program, DrawType type, uint32_t count) = 0;
};
