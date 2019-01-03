//
// Created by wuwang on 18-12-26.
//

#ifndef CHARM_DRAWER_H
#define CHARM_DRAWER_H

#include "base/Base.h"
#include "base/Matrix.h"

class Cube;
class Matrix;

class Drawer {
public:
    Drawer();
    void init();
    void draw();

private:
    SPtr<Cube> cube;
    int programId;
    int glVert;
    int glColor;
    int glMatrix;

    Matrix matrix;
};


#endif //CHARM_DRAWER_H
