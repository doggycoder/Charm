//
// Created by wuwang on 19-3-12.
//

#include "QtCameraDrawer.h"
#include <opencv2/opencv.hpp>
#include <engine/opengl/GlTool.h>
#include <engine/opengl/Shader.h>

QtCameraDrawer::QtCameraDrawer(int index):
coord{
    1.0f,1.0f,1.0f,1.0f,
    1.0f,-1.0f,1.0f,0.0f,
    -1.0f,1.0f,0.0f,1.0f,
    -1.0f,-1.0f,0.0f,0.0f
}{
    capture.open(index);
    attrData.data = coord;
    attrData.stride = 16;
    attrData.addGlAttrInfo(2,0,GlAttrName::POSITION);
    attrData.addGlAttrInfo(2,2*sizeof(float),GlAttrName::COORD);
}

QtCameraDrawer::QtCameraDrawer(std::string &path):
coord{
1.0f,1.0f,1.0f,1.0f,
1.0f,-1.0f,1.0f,0.0f,
-1.0f,1.0f,0.0f,1.0f,
-1.0f,-1.0f,0.0f,0.0f
} {
    capture.open(path);
    attrData.data = coord;
    attrData.stride = 16;
    attrData.addGlAttrInfo(2,0,GlAttrName::POSITION);
    attrData.addGlAttrInfo(2,2,GlAttrName::COORD);
}

void QtCameraDrawer::glInit() {
    program = manager.getProgram(ssVertexImageMatrix,ssFragImage);
    program->setAttrData(attrData);
    textureId = GlTool::createTexture();
}

void QtCameraDrawer::glSizeChange(int width, int height) {
    this->width = width;
    this->height = height;
}

void QtCameraDrawer::glDraw() {
    if(capture.isOpened()){
        cv::Mat frame;
        cv::Mat temp;
        capture>>frame;
        cv::cvtColor(frame,temp,cv::COLOR_BGR2RGB);
        cv::flip(temp,frame,-1);
        std::cout<<"info :"<<frame.rows<<","<<frame.cols<<"::"<<int(frame.data[300])<<std::endl;
        glClearColor(0.7f,0.3f,0.2f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        mat = Matrix::createImageMatrix(frame.cols,frame.rows,width,height);

        program->prepare();
        program->setTexture2D(hGlTexture,textureId,frame.cols,frame.rows,frame.data);
        program->setParam(hGlMatrix,mat);
        program->render();
    }
}

void QtCameraDrawer::glDestroy() {
    manager.delProgram(&program);
}