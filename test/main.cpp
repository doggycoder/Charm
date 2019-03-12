//
// Created by wuwang on 19-1-18.
//
#include "basics/VectorTest.h"
#include "base/Random.h"

int main(){
    VectorTest test;
    test.test();
    Color4f color(0,0.6,0.7,0.2);
    Color4f d = random(color);
    std::cout<<"dt:"<<d.x<<","<<d.y<<","<<d.z<<","<<d.w<<std::endl;
    return 0;
}