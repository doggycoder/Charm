//
// Created by wuwang on 19-3-5.
//

#ifndef QTFACERESEARCH_GLWIDGET_H
#define QTFACERESEARCH_GLWIDGET_H

#include <QtWidgets/QOpenGLWidget>
#include <thread>

class GlWidgetFunction{
public:
    GlWidgetFunction() = default;
    virtual void glInit(){};
    virtual void glSizeChange(int width,int height){};
    virtual void glDraw(){};
    virtual void glDestroy(){};
};

class GlWidget : public QOpenGLWidget{
private:
    int width{0};
    int height{0};
    GlWidgetFunction * func{nullptr};
    std::thread thread;
    bool threadFlag{false};

public:
    explicit GlWidget(QWidget* parent = nullptr, Qt::WindowFlags f = nullptr);

    ~GlWidget() override;

    void setGlFunction(GlWidgetFunction * func);

    void initializeGL() override;

    void resizeGL(int w, int h) override;

    void paintGL() override;
};


#endif
