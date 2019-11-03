//
// Created by wuwang on 19-9-1.
//

#include <cstring>
#include "Mesh.h"

Mesh::Mesh(std::initializer_list<AttributeType> v, bool useVbo, bool useIbo) {
    uint32_t offset = 0;
    this->useVbo = useVbo;
    this->useIbo = useIbo;
    for (auto& item : v) {
        attributes.push_back(item);
        attributes.back().offset = offset;
        offset += item.size;
        MParam param(item.name.c_str());
        param.type = useVbo?MParam::Type::eMPT_AttributeWithBo : MParam::Type::eMPT_Attribute;
        paramAttr[param.name] = param;
    }
    this->stride = offset * sizeof(float);
}

SPtr<Mesh> Mesh::createQuad() {
    SPtr<Mesh> ret;
    ret = SPtr<Mesh>(new Mesh({{2, aVertexCoName}, {2, aTextureCoName}}));
    ret->drawType = eDT_Array_TriangleFan;
    ret->vertexes = {
            -1.0f,  1.0f, 0.0f, 0.0f,
            -1.0f, -1.0f, 0.0f, 1.0f,
             1.0f, -1.0f, 1.0f, 1.0f,
             1.0f,  1.0f, 1.0f, 0.0f};
    ret->useIbo = false;
    return ret;
}

void Mesh::updateVertexes(float *data, uint32_t offset, uint32_t length, bool resizeIfNeeded) {
    uint32_t dataLength = length;
    if(vertexes.size() < offset + length){
        if(resizeIfNeeded){
            vertexes.resize(offset + length);
        }else{
            dataLength = static_cast<uint32_t>(vertexes.size() - offset);
        }
    }
    if(dataLength > 0){
        memcpy(&vertexes[offset], data, dataLength * sizeof(float));
        isVertexChanged = true;
    }
}

void Mesh::updateIndexes(uint32_t *index, uint32_t offset, uint32_t length, bool resizeIfNeeded) {
    uint32_t dataLength = length;
    if(indexes.size() < offset + length){
        if(resizeIfNeeded){
            indexes.resize(offset + length);
        }else{
            dataLength = static_cast<uint32_t>(indexes.size() - offset);
        }
    }
    if(dataLength > 0){
        memcpy(&indexes[offset], index, dataLength * sizeof(uint32_t));
        isIndexChanged = true;
    }
}

void Mesh::render(IContext* context, uint64_t programId) {
    //更新vbo
    for (auto& attr : attributes) {
        context->getRenderDevice()->setVertexes(programId, paramAttr[attr.name], attr, stride, &vertexes[attr.offset],
                                                static_cast<uint32_t>(vertexes.size() * sizeof(float)), 0);
    }
    if(useIbo){
        pointCount = static_cast<uint32_t>(indexes.size());
        context->getRenderDevice()->setIndexes(iboId, &indexes[0],
                                               static_cast<uint32_t>(indexes.size() * sizeof(uint32_t)), 0, isIndexChanged);
    }else{
        pointCount = static_cast<uint32_t>(vertexes.size() * sizeof(float) / stride );
    }
    context->getRenderDevice()->render(programId, drawType, pointCount);
}
