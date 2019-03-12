//
// Created by wuwang on 19-3-10.
//

#ifndef _CHARM_QTGLDRAWTEST_H_
#define _CHARM_QTGLDRAWTEST_H_

#include "qt/glwidget/GlWidget.h"
#include "GL/gl.h"
#include "Drawer.h"

class QtGlDrawTest : public GlWidgetFunction{
private:
    Drawer drawer;
public:
    void glInit() override {
        glEnable(GL_DEPTH_TEST);
        glClearColor(1.0f,1.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        drawer.init();
    };
    void glSizeChange(int width,int height) override{

    };
    void glDraw() override{
        glClearColor(1.0f,1.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        drawer.draw();
    };
};

#endif //_CHARM_QTGLDRAWTEST_H_
