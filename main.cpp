#include <iostream>
#include <base/Vec.h>
#include <fstream>
#include <codecvt>
#include <sstream>
#include <cstring>
#include "base/Base.h"
#include "window/GlfwWindow.h"
#include "shape/Cube.h"
#include "render/Render.h"
#include "GL/glew.h"
#include "locale"
#include "opengl/GlTool.h"
#include "opengl/Shader.h"
#include "shape/Drawer.h"
#include "particle/Base.h"

Render render;
Drawer * drawer;
BaseEmitter * emitter;

using namespace std;

int main() {

    Cube cube(1.0f);
    drawer = new Drawer();
    emitter = new BaseEmitter();

    std::cout<<"Cube Size:"<< sizeof(Cube) <<std::endl;
    GlfwWindow window;
    window.setGlInitCallback([](int w, int h){
        glewExperimental = GL_TRUE;
        glewInit();
        drawer->init();

        RateVec pos(Vec3f(0,0,0),Vec3f(0,0,0));
        emitter->setPosition(pos);
        emitter->setAtomMaxNum(1000);
        RateI speed(100,40);
        emitter->setEmitSpeed(speed);
        RateF period(1,0.1f);
        emitter->setEmitPeriod(period);
        RateF time(0.1f,0);
        emitter->setEmitTime(time);
    });
    window.setGlDrawCallback([](){
        drawer->draw();
        emitter->update(0.05);
    });
    window.setSize(368,640);
    window.startLoop();
    delete drawer;
    return EXIT_SUCCESS;
}