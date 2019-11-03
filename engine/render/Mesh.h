//
// Created by wuwang on 19-9-1.
//

#pragma once


#include <base/Vec.h>
#include <vector>
#include "RenderName.h"
#include "Material.h"


class Mesh {
private:
    std::map<std::string, MParam> paramAttr;
    uint64_t iboId{0};
    uint32_t stride{0};
    uint32_t pointCount{0};
public:
    std::vector<AttributeType> attributes;
    std::vector<uint32_t> indexes;
    bool isIndexChanged{true};
    std::vector<float>  vertexes;
    bool isVertexChanged{true};
    DrawType drawType{eDT_Points};
    bool useVbo{true};
    bool useIbo{true};

    Matrix worldMat;

    Mesh(std::initializer_list<AttributeType> v, bool useVbo = true, bool useIbo = true);
    static SPtr<Mesh> createQuad();

    void updateVertexes(float * data,uint32_t offset, uint32_t length, bool resizeIfNeeded = false);
    void updateIndexes(uint32_t * index, uint32_t offset, uint32_t length, bool resizeIfNeeded = false);

    void render(IContext* context,uint64_t programId);
};


