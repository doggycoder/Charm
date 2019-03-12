//
// Created by wuwang on 19-1-6.
//

#ifndef CHARM_RECT_H
#define CHARM_RECT_H


#include "base/Vec.h"

class Rect {
private:
    float halfSize;
public:
    Vec3f vertex[4];
    Color4f colors[4];
    unsigned short index[6];

    explicit Rect(float size = 1.0f):
    halfSize(size/2),
    vertex{
            {-halfSize,halfSize,0},{halfSize,halfSize,0},
            {-halfSize,-halfSize,0},{halfSize,-halfSize,0}
    },
    index{0,1,3,0,3,2},
    colors{
            {1,0,0,1},{0,1,0,1},{0,0,1,1},{1,1,1,1}
    }
    {};
};


#endif //CHARM_RECT_H
