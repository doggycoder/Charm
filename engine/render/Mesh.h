//
// Created by wuwang on 19-9-1.
//

#pragma once


#include <base/Vec.h>
#include <vector>
#include "RenderName.h"
#include "Material.h"


class Mesh {
public:
    std::vector<AttributeType> attributes;
    std::vector<uint32_t> indexes;
    bool isIndexChanged{true};
    std::vector<float>  vertexes;
    bool isVertexChanged{true};
    MeshType drawType{eDT_Points};
    bool useVbo{true};
    bool useIbo{true};

    Mesh(std::initializer_list<AttributeType> v);
    static SPtr<Mesh> createQuad();

    void updateVertexes(float * data,uint32_t offset, uint32_t length, bool resizeIfNeeded = false);
    void updateIndexes(uint32_t * index, uint32_t offset, uint32_t length, bool resizeIfNeeded = false);

};


