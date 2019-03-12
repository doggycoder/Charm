//
// Created by wuwang on 18-12-31.
//
#include <string>
#include <cassert>
#include <iostream>
#include "GlTool.h"

GLuint GlTool::loadShader(GLuint type, std::string shader) {
    GLuint ret = glCreateShader(type);
    const char * shaderData = shader.c_str();
    glShaderSource(ret, 1, &shaderData, nullptr);
    glCompileShader(ret);
    GLint compileRet{0};
    glGetShaderiv(ret,GL_COMPILE_STATUS,&compileRet);
    if(compileRet != GL_TRUE){
        GLchar info[100];
        GLsizei lsizei;
        glGetShaderInfoLog(ret,100,&lsizei,info);
        std::cout << "shader compile error:"<< shader << "\ntype = " <<type <<"\ninfo = "<< info <<std::endl;
        glDeleteShader(ret);
        assert(false);
        return 0;
    }
    return ret;
}

GLuint GlTool::compile(std::string vert, std::string frag) {
    GLuint vertShaderId = loadShader(GL_VERTEX_SHADER, std::move(vert));
    GLuint fragShaderId = loadShader(GL_FRAGMENT_SHADER, std::move(frag));
    GLuint program = glCreateProgram();
    glAttachShader(program, fragShaderId);
    glAttachShader(program, vertShaderId);
    glLinkProgram(program);
    GLint linkRet{0};
    glGetProgramiv(program,GL_LINK_STATUS,&linkRet);
    if(linkRet != GL_TRUE){
        GLchar info[100];
        GLsizei lsizei{0};
        glGetProgramInfoLog(program,100,&lsizei,info);
        std::cout << "gl program link error:"<<lsizei<<","<<info<<std::endl;
        glDeleteProgram(program);
        assert(false);
        return 0;
    }
    return program;
}

GLint GlTool::getUniformLocation(GLuint programId, const char * name) {
    return glGetUniformLocation(programId,name);
}

GLint GlTool::getAttribLocation(GLuint programId, const char *name) {
    return glGetAttribLocation(programId,name);
}

GLint GlTool::createTexture() {
    GLuint textureId = 0;
    glGenTextures(1,&textureId);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,textureId);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    return textureId;
}
