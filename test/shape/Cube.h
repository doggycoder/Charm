//
// Created by wuwang on 18-12-24.
//

#ifndef CHARM_CUBE_H
#define CHARM_CUBE_H

#include "base/Vec.h"

class Cube {
private:
    float halfSize;
public:
    Vec3f vertex[8];
    Color4f colors[8];
    unsigned short index[36];

    Cube(float size = 1.0f);

    void setPosition(float x,float y,float z);
};


#endif //CHARM_CUBE_H
