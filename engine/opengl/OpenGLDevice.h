//
// Created by wuwang on 19-8-30.
//

#pragma once

#include "base/IRenderDevice.h"
#include <map>
#include "base/MParam.h"

class OpenGLDevice : public IRenderDevice {
private:
    const static char * vsCodeHeader;
    const static char * psCodeHeader;
private:
public:
    void        open() override;
    void        close() override;

    uint64_t    compile(const char * code) override;

    void        setParam(uint64_t program, MParam& key, float t) override;
    void        setParam(uint64_t program, MParam& key, Vec2f& t) override;
    void        setParam(uint64_t program, MParam& key, Vec3f& t) override;
    void        setParam(uint64_t program, MParam& key, Vec4f& t) override;
    void        setParam(uint64_t program, MParam& key, float * value, uint32_t unitCount, uint32_t unitSize) override;
    void        setParam(uint64_t program, MParam& key, Matrix& mat) override;
    void        setAttribute(uint64_t program, MParam& key, AttributeType &type, uint32_t stride,
                         float * data, uint32_t dataLength, uint32_t updateOffset = 0);
    bool        checkParam(uint64_t programId, MParam& key) override;
};


