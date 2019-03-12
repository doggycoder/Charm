//
// Created by wuwang on 19-3-5.
//

#include "GlWidget.h"
#include <chrono>

GlWidget::GlWidget(QWidget *parent, Qt::WindowFlags f):
QOpenGLWidget(parent, f)
{

}

GlWidget::~GlWidget() {
    threadFlag = false;
    delete func;
}

void GlWidget::setGlFunction(GlWidgetFunction * func) {
    this->func = func;
}

void GlWidget::initializeGL() {
    if(func){
        func->glInit();
    }
    threadFlag = true;
    thread = std::thread([&](){
        do{
            update();
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
        }while (threadFlag);
    });
    thread.detach();
}

void GlWidget::resizeGL(int w, int h) {
    if(func){
        func->glSizeChange(w,h);
    }
}

void GlWidget::paintGL() {
    if(func){
        func->glDraw();
    }
}