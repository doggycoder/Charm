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

Render render;
Drawer * drawer;

using namespace std;

int main() {

    Cube cube(1.0f);
    drawer = new Drawer();

    std::cout<<"Cube Size:"<< sizeof(Cube) <<std::endl;
    GlfwWindow window;
    window.setGlInitCallback([](int w, int h){
        glewExperimental = GL_TRUE;
        glewInit();
        drawer->init();
    });
    window.setGlDrawCallback([](){
        drawer->draw();
    });
    window.setSize(368,640);
    window.startLoop();
    delete drawer;
    return EXIT_SUCCESS;
}