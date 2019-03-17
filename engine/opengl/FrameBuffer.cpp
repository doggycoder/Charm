//
// Created by wuwang on 19-3-15.
//

#include "FrameBuffer.h"
#include "GlTool.h"

FrameBuffer::FrameBuffer(int width,int height,bool useRenderBuffer, bool autoDeleteCacheTex):
width(width),
height(height),
useRenderBuffer(useRenderBuffer),
autoDeleteCacheTex(autoDeleteCacheTex)
{
    glGenFramebuffers(1,&fboId);
    texId = static_cast<GLuint>(GlTool::createTexture());
    GLint fboTemp{0};
    glGetIntegerv(GL_FRAMEBUFFER_BINDING,&fboTemp);
    glBindFramebuffer(GL_FRAMEBUFFER,fboId);
    glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,texId,0);
    if(useRenderBuffer){
        GLint rboTemp;
        glGetIntegerv(GL_RENDERBUFFER_BINDING,&rboTemp);
        glGenRenderbuffers(1,&rboId);
        glBindRenderbuffer(GL_RENDERBUFFER,rboId);
        glRenderbufferStorage(GL_RENDERBUFFER,GL_DEPTH_COMPONENT16,width,height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER,GL_DEPTH_ATTACHMENT,GL_RENDERBUFFER,rboId);
        glBindRenderbuffer(GL_RENDERBUFFER, static_cast<GLuint>(rboTemp));
    }
    glBindFramebuffer(GL_FRAMEBUFFER, static_cast<GLuint>(fboTemp));
}

FrameBuffer::~FrameBuffer() {
    if(autoDeleteCacheTex){
        glDeleteTextures(1,&texId);
    }
    glDeleteFramebuffers(1,&fboId);
    if(useRenderBuffer){
        glDeleteRenderbuffers(1,&rboId);
    }
}

int FrameBuffer::bind() {
    glGetIntegerv(GL_FRAMEBUFFER_BINDING,&lastFboId);
    glBindFramebuffer(GL_FRAMEBUFFER,fboId);
    return lastFboId;
}

void FrameBuffer::unBind() {
    glBindFramebuffer(GL_FRAMEBUFFER, static_cast<GLuint>(lastFboId));
}