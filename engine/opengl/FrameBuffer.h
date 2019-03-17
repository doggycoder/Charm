//
// Created by wuwang on 19-3-15.
//

#ifndef _CHARM_FRAMEBUFFER_H_
#define _CHARM_FRAMEBUFFER_H_

#include "GLES2/gl2.h"

class FrameBuffer {
private:
    int width;
    int height;
    bool useRenderBuffer;
    bool autoDeleteCacheTex;
    GLuint fboId{0};
    GLuint texId{0};
    GLint lastFboId{0};
    GLuint rboId{0};
public:
    FrameBuffer(int width,int height,bool useRenderBuffer = false,bool autoDeleteCacheTex = true);
    ~FrameBuffer();

    int bind();

    void unBind();

    int cacheTexId(){ return texId;}

};


#endif //_CHARM_FRAMEBUFFER_H_
