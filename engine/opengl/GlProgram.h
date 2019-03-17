//
// Created by wuwang on 19-3-17.
//

#ifndef _CHARM_GL_PROGRAM_MANAGER_H_
#define _CHARM_GL_PROGRAM_MANAGER_H_

#include <map>
#include <vector>
#include "GlBase.h"
#include "GlTool.h"

class Matrix;


class GlShaderInfo:public GlObj{
private:
    int useCount{0};
public:
    const char * content{nullptr};
    GLuint glId{0};
    void glResume() override{
        if(content != nullptr){
            glId = GlTool::loadShader(TYPE_VERTEX,content);
        }
    }
    void dispose() override{
        if(glId){
            glDeleteShader(glId);
            glId = 0;
        }
    }
    inline void addRef(){
        useCount++;
    }

    inline void delRef(){
        useCount--;
    }
};

class GlProgram:public GlObj{
protected:
    //为管理而定义
    friend class GlProgramManager;
    GlProgram() = default;
    ~GlProgram() = default;
    int useCount{0};
    inline void addRef(){useCount++;}
    inline void delRef(){useCount--;}
    inline bool shouldDel(){ return useCount <= 0;};

    //为执行而定义
    GLuint currentTextureDeviceIndex{0};
    GlAttrData attrData;
public:
    GLuint glId{0};
    GlShaderInfo * vertShader{nullptr};
    GlShaderInfo * fragShader{nullptr};

    void dispose() override;

    void glResume() override;

    bool checkGlParam(GlParam &param);

    void prepare();
    void setTexture2D(GlParam &param,GLuint textureId);
    void setTexture2D(GlParam &param,GLuint textureId,GLsizei width,GLsizei height,void * data);
    void setParam(GlParam &param,Matrix &matrix);
    void setAttrData(GlAttrData &data);
    void render();
};

class GlProgramManager:public GlObj{
private:
    typedef std::map<const char *,GlShaderInfo*> ShaderMap;
    typedef std::vector<GlProgram*> ProgramVec;
    ShaderMap shaders;
    ProgramVec programs;
public:
    GlProgram * getProgram(const char * vert,const char * frag);
    void delProgram(GlProgram ** program);
    void glResume() override;
    void dispose() override;

};


#endif //_CHARM_GL_PROGRAM_MANAGER_H_
