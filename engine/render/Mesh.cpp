//
// Created by wuwang on 19-9-1.
//

#include <cstring>
#include "Mesh.h"

Mesh::Mesh(std::initializer_list<AttributeType> v) {
    for (auto& item : v) {
        attributes.push_back(item);
    }
}

SPtr<Mesh> Mesh::createQuad() {
    SPtr<Mesh> ret;
    ret = SPtr<Mesh>(new Mesh({{2, aVertexCoName}, {2, aTextureCoName}}));
    ret->drawType = eDT_TriangleStrip;
    ret->vertexes = {
            -1.0f,  1.0f, 0.0f, 0.0f,
            -1.0f, -1.0f, 0.0f, 1.0f,
             1.0f, -1.0f, 1.0f, 1.0f,
             1.0f,  1.0f, 1.0f, 0.0f};
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