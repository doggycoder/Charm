//
// Created by wuwang on 18-12-31.
//

#ifndef _ENGINE_OPENGL_GL_TOOL_H_
#define _ENGINE_OPENGL_GL_TOOL_H_

#include "GLES2/gl2.h"

class GlTool {
public:
    static GLuint loadShader(GLuint type,std::string shader);
    static GLuint compile(std::string vert,std::string frag);
    static GLint getUniformLocation(GLuint programId, const char * name);
    static GLint getAttribLocation(GLuint programId,const char * name);
    static GLint createTexture();
};


#endif
