//
// Created by wuwang on 18-12-24.
//

#include "Cube.h"

Cube::Cube(float size):halfSize(size*0.5f),vertex{
        {halfSize,halfSize,halfSize},{-halfSize,halfSize,halfSize},
        {halfSize,-halfSize,halfSize},{-halfSize,-halfSize,halfSize},
        {halfSize,halfSize,-halfSize},{-halfSize,halfSize,-halfSize},
        {halfSize,-halfSize,-halfSize},{-halfSize,-halfSize,-halfSize}
}
,colors{
                {1.0f,0.0f,0.0f},{1.0f,1.0f,1.0f},
                {1.0f,1.0f,1.0f},{1.0f,1.0f,1.0f},
                {1.0f,1.0f,1.0f},{1.0f,1.0f,1.0f},
                {1.0f,1.0f,1.0f},{0.0f,1.0f,0.0f}
    }
,index{
        0,1,3,0,3,2, //前面
        1,5,7,1,7,3, //左边
        4,0,6,0,2,6, //右边
        4,5,0,5,1,0, //上面
        2,3,7,2,7,6, //下面
        5,4,7,4,6,7, //后面
}
{

}

void Cube::setPosition(float x, float y, float z) {
    for (auto &i : vertex) {
        i.x += x;
        i.y += y;
        i.z += z;
    }
}