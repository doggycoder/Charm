//
// Created by wuwang on 19-3-17.
//

#ifndef _CHARM_GL_BASE_H_
#define _CHARM_GL_BASE_H_

#include <GLES2/gl2.h>
#include <string>
#include <vector>

class GlObj{
public:
    virtual void glResume(){};
    virtual void dispose() = 0;
};


class GlAttrName{
public:
    static const char * POSITION;
    static const char * COLOR;
    static const char * COORD;
};

typedef GLint (* GlParamType)(GLuint,const char *);

class GlParam:public GlObj{
public:
    static const GlParamType UNIFORM;
    static const GlParamType ATTRIBUTE;
private:
    std::string key;
    int glId{-1};
    GlParamType type;
    friend class GlProgram;
public:
    explicit GlParam(std::string key,GlParamType type = UNIFORM);
    void dispose() override{glId = -1;}

};

enum GlAttrDataType{
    eglFloat = GL_FLOAT,
    eglInt = GL_INT,
};

class GlAttrInfo{
private:
    GlParam param;
    int offset;
    int size{0};
    const char * name;
    bool normalize{false};
public:
    GlAttrInfo(int size,int offset, const char * name = GlAttrName::POSITION, bool normalize = false);
    inline int gOffset(){ return offset;}
    inline int gSize(){ return size;}
    inline bool gNormalize(){ return normalize;}
    inline const char * gName(){ return name;};
    inline GlParam& gParam(){ return param;}
};

class GlAttrData{
public:
    void * data{nullptr};
    int stride{0};
    GlAttrDataType datType{eglFloat};
    std::vector<GlAttrInfo> infos;

    void addGlAttrInfo(GlAttrInfo &info){
        infos.push_back(info);
    }

    void addGlAttrInfo(int size,int offset,const char * name,bool normalize = false);
};




#endif //_CHARM_GL_BASE_H_
