//
// Created by wuwang on 19-3-17.
//

#include "GlProgram.h"
#include "base/Matrix.h"

void GlProgram::glResume(){
    if(!glId){
        glId = GlTool::linkProgram(vertShader->glId,fragShader->glId);
    }
}

void GlProgram::dispose() {
    if(glId){
        glDeleteProgram(glId);
        glId = 0;
    }
}


bool GlProgram::checkGlParam(GlParam &param) {
    if(param.glId == -1){
        if(glId == 0){
            return false;
        }
        param.glId = param.type(static_cast<GLuint>(glId),param.key.data());
        if(param.glId == -1){
            return false;
        }
    }
    return true;
}

void GlProgram::prepare() {
    glResume();
    glUseProgram(glId);
}

void GlProgram::setTexture2D(GlParam &param, GLuint textureId) {
    if(checkGlParam(param)){
        glActiveTexture(GL_TEXTURE0 + currentTextureDeviceIndex);
        glBindTexture(GL_TEXTURE_2D,textureId);
        glUniform1i(param.glId,currentTextureDeviceIndex);
        currentTextureDeviceIndex++;
    }
}

void GlProgram::setTexture2D(GlParam &param, GLuint textureId, GLsizei width, GLsizei height, void *data) {
    if(checkGlParam(param)){
        glActiveTexture(GL_TEXTURE0 + currentTextureDeviceIndex);
        glBindTexture(GL_TEXTURE_2D,textureId);
        glUniform1i(param.glId,currentTextureDeviceIndex);
        currentTextureDeviceIndex++;
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
    }
}

void GlProgram::setParam(GlParam &param, Matrix &matrix) {
    if(checkGlParam(param)){
        glUniformMatrix4fv(param.glId,1, GL_FALSE,matrix.data());
    }
}

void GlProgram::setAttrData(GlAttrData &data) {
    attrData = data;
}

void GlProgram::render() {
    for (auto &d : attrData.infos) {
        GlParam param = d.gParam();
        checkGlParam(param);
        glEnableVertexAttribArray(static_cast<GLuint>(param.glId));
        glVertexAttribPointer(static_cast<GLuint>(param.glId), d.gSize(),
                              attrData.datType,static_cast<GLboolean>(d.gNormalize()),
                              attrData.stride,(unsigned char *)(attrData.data) + d.gOffset());
    }
    //todo 根据attrData中的参数判断，区分调用glDrawElements
    glDrawArrays(GL_TRIANGLE_STRIP,0,4);
    for (auto &d : attrData.infos) {
        glDisableVertexAttribArray(static_cast<GLuint>(d.gParam().glId));
    }
}

GlProgram* GlProgramManager::getProgram(const char *vert, const char *frag){
    bool needFind = true;
    if(shaders.find(vert) == shaders.end()){
        auto * vertShader = new GlShaderInfo();
        vertShader->content = vert;
        vertShader->glId = GlTool::loadShader(TYPE_VERTEX,vert);
        shaders[vert] = vertShader;
        needFind = false;
    }
    if(shaders.find(frag) == shaders.end()){
        auto * fragShader = new GlShaderInfo();
        fragShader->content = frag;
        fragShader->glId = GlTool::loadShader(TYPE_FRAGMENT,frag);
        shaders[frag] = fragShader;
        needFind = false;
    }

    if(needFind){
        for (auto &program : programs) {
            if(program->vertShader == shaders[vert] && program->fragShader == shaders[frag]){
                program->addRef();
                return program;
            }
        }
    }
    auto * programInfo = new GlProgram();
    programInfo->glId = GlTool::linkProgram(shaders[vert]->glId,shaders[frag]->glId);
    if(programInfo->glId != 0){
        shaders[vert]->addRef();
        shaders[frag]->addRef();
        programInfo->vertShader = shaders[vert];
        programInfo->fragShader = shaders[frag];
        programInfo->addRef();
        programs.push_back(programInfo);
        return programs.back();
    }
    return nullptr;
}

void GlProgramManager::delProgram(GlProgram ** program) {
    if(*program){
        (*program)->vertShader->delRef();
        (*program)->fragShader->delRef();
        (*program)->delRef();
        if((*program)->shouldDel()){
            (*program)->dispose();
            delete *program;
            *program = nullptr;
        }
    }
}

void GlProgramManager::glResume() {
    ShaderMap::iterator it;
    for(it = shaders.begin(); it != shaders.end(); it++){
        it->second->glResume();
    }
}

void GlProgramManager::dispose() {
    ShaderMap::iterator it;
    for(it = shaders.begin(); it != shaders.end(); it++){
        it->second->dispose();
    }
    for (auto &program : programs) {
        program->glResume();
    }
}