//
// Created by wuwang on 18-12-31.
//

#ifndef _ENGINE_OPENGL_GL_TOOL_H_
#define _ENGINE_OPENGL_GL_TOOL_H_

#define GLEW_STATIC
#include "GL/glew.h"
#include "GL/glut.h"

class GlTool {
public:
    static GLuint loadShader(GLuint type,std::string shader);
    static GLuint compile(std::string vert,std::string frag);
};


#endif