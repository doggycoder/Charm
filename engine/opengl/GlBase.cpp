//
// Created by wuwang on 19-3-17.
//
#include "GlBase.h"
#include "GlProgram.h"

GlAttrInfo::GlAttrInfo(int offset, int size,const char * name, bool normalize):
offset(offset),
size(size),
name(name),
normalize(normalize),
param(name,GlParam::ATTRIBUTE){
}

void GlAttrData::addGlAttrInfo(int size, int offset, const char * name, bool normalize){
    infos.emplace_back(GlAttrInfo(offset, size,name,normalize));
};


GlParam::GlParam(std::string key, GlParamType type)
        :key(std::move(key)),
         type(type){
}

const char * GlAttrName::POSITION = "aPosition";
const char * GlAttrName::COLOR = "aColor";
const char * GlAttrName::COORD = "aCoord";

const GlParamType GlParam::UNIFORM = glGetUniformLocation;
const GlParamType GlParam::ATTRIBUTE = glGetAttribLocation;

