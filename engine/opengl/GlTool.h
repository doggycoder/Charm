//
// Created by wuwang on 18-12-31.
//

#ifndef _ENGINE_OPENGL_GL_TOOL_H_
#define _ENGINE_OPENGL_GL_TOOL_H_

#include <string>
#include "GlBase.h"
#include "GLES2/gl2.h"

#define TYPE_VERTEX GL_VERTEX_SHADER
#define TYPE_FRAGMENT GL_FRAGMENT_SHADER

class GlTool {
public:
    static GLuint loadShader(GLuint type,const char * shader);
    static GLuint compile(const char * vert, const char * frag);
    static GLuint linkProgram(GLuint vert,GLuint frag);
    static GLint getUniformLocation(GLuint programId, const char * name);
    static GLint getAttribLocation(GLuint programId,const char * name);
    static GLint createTexture();
};


#endif
