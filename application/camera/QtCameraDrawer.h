//
// Created by wuwang on 19-3-12.
//

#ifndef _CHARM_QT_CAMERA_DRAWER_H_
#define _CHARM_QT_CAMERA_DRAWER_H_

#include <opencv2/opencv.hpp>
#include <engine/base/Matrix.h>
#include "qt/glwidget/GlWidget.h"
#include "base/Base.h"

class QtCameraDrawer : public GlWidgetFunction {
private:
    cv::VideoCapture capture;
    GLuint programHandler;
    GLint textureHandler;
    GLint vertexHandler;
    GLint coordHandler;
    GLint matrixHandler;
    GLuint textureId;
    float coord[16];
    Matrix mat;
    int width;
    int height;
public:
    explicit QtCameraDrawer(int index = 0);

    explicit QtCameraDrawer(std::string &path);

    void glInit() override;
    void glSizeChange(int width,int height) override;
    void glDraw() override;
    void glDestroy() override;
};


#endif //CHARM_QTCAMERADRAWER_H
