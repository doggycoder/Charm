//
// Created by wuwang on 19-8-30.
//

#include "OpenGLDevice.h"
#include <GLES2/gl2.h>
#include <functional>
#include <cstring>
#include "base/Logger.h"

const char * OpenGLDevice::vsCodeHeader = "#define CODE_TYPE_VS";
const char * OpenGLDevice::psCodeHeader = "#define CODE_TYPE_PS";

void OpenGLDevice::open() {

}

void OpenGLDevice::close() {

}

uint64_t OpenGLDevice::compile(const char *code) {
    if(!code){
        return 0;
    }
    auto compileFunc = [](GLenum type, const char * code)->GLuint {
        GLuint shaderId = glCreateShader(type);
        if(shaderId > 0){
            const GLchar * sourceCode[1] = {};
            sourceCode[0] = code;
            glShaderSource(shaderId, 1, sourceCode, nullptr);
            glCompileShader(shaderId);
            GLint compileRet;
            glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compileRet);
            if(!compileRet){
                GLchar infoLog[1024];
                glGetShaderInfoLog(shaderId, 1024, nullptr, infoLog);
                Logger::out<<"shaderType:"<<glGetString(shaderId)<<":" <<infoLog<<Logger::Err;
                glDeleteShader(shaderId);
                shaderId = 0;
            }
        }
        return shaderId;
    };
    std::string vsCode = std::string(vsCodeHeader) + code;
    std::string psCode = std::string(psCodeHeader) + code;
    GLuint vertexShaderId = compileFunc(GL_VERTEX_SHADER, vsCode.c_str());
    if(vertexShaderId == 0){
        return 0;
    }
    GLuint fragmentShaderId = compileFunc(GL_FRAGMENT_SHADER, psCode.c_str());
    if(fragmentShaderId == 0){
        glDeleteShader(vertexShaderId);
        return 0;
    }
    GLuint programId = glCreateProgram();
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);
    GLint linkRet;
    glGetProgramiv(programId, GL_LINK_STATUS, &linkRet);
    if(!linkRet){
        GLchar infoLog[1024];
        glGetProgramInfoLog(programId, 1024, nullptr, infoLog);
        Logger::out<<"program link error : "<<infoLog<<Logger::Err;
        programId = 0;
    }
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
    return programId;
}

void OpenGLDevice::setParam(uint64_t program, MParam& key, float t) {
    if(checkParam(program, key)){
        glUniform1f(static_cast<GLint>(key.key), t);
    }
}

void OpenGLDevice::setParam(uint64_t program, MParam& key, Vec2f &t) {
    if(checkParam(program, key)){
        glUniform2f(static_cast<GLint>(key.key), t.x, t.y);
    }
}

void OpenGLDevice::setParam(uint64_t program, MParam& key, Vec3f &t) {
    if(checkParam(program, key)){
        glUniform3f(static_cast<GLint>(key.key), t.x, t.y, t.z);
    }
}

void OpenGLDevice::setParam(uint64_t program, MParam& key, Vec4f &t) {
    if(checkParam(program, key)){
        glUniform4f(static_cast<GLint>(key.key), t.x, t.y, t.z, t.w);
    }
}

void OpenGLDevice::setParam(uint64_t program, MParam& key, float *value, uint32_t unitCount, uint32_t unitSize) {
    if(checkParam(program, key)){
        void (*pFunction[4])(GLint, GLsizei, const GLfloat *) = {
                glUniform1fv, glUniform2fv, glUniform3fv, glUniform4fv
        };
        if(unitSize >= 1 && unitSize <= 4){
            pFunction[unitSize - 1](static_cast<GLint>(key.key), unitCount, value);
        }
    }
}

void OpenGLDevice::setParam(uint64_t program, MParam& key, Matrix &mat) {
    if(checkParam(program, key)){
        glUniformMatrix4fv(static_cast<GLint>(key.key), 1, GL_FALSE, mat.data());
    }
}

bool OpenGLDevice::checkParam(uint64_t program,MParam &key) {
    if(key.state == MParam::State::eMPS_OK){
        return true;
    } else if(key.state == MParam::State::eMPS_UNINIT){
        GLint keyId = glGetUniformLocation(static_cast<GLuint>(program), key.name.c_str());
        if(keyId == -1){
            key.state = MParam::State::eMPS_ERROR;
            return false;
        }else{
            key.state = MParam::State::eMPS_OK;
            key.key = static_cast<uint64_t>(keyId);
            return true;
        }
    }
    return false;
}
