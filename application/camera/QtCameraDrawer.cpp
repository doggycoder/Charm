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
}

QtCameraDrawer::QtCameraDrawer(std::string &path):
coord{
1.0f,1.0f,1.0f,1.0f,
1.0f,-1.0f,1.0f,0.0f,
-1.0f,1.0f,0.0f,1.0f,
-1.0f,-1.0f,0.0f,0.0f
} {
    capture.open(path);
}

void QtCameraDrawer::glInit() {
    programHandler = GlTool::compile(ssVertexImageMatrix,ssFragImage);
    textureHandler = GlTool::getUniformLocation(programHandler,"uTexture");
    vertexHandler = GlTool::getAttribLocation(programHandler,"aPosition");
    coordHandler = GlTool::getAttribLocation(programHandler,"aCoord");
    matrixHandler = GlTool::getUniformLocation(programHandler,"uMatrix");
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

        glUseProgram(programHandler);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,frame.cols,frame.rows,0,GL_RGB,GL_UNSIGNED_BYTE,frame.data);
        glUniform1i(textureHandler,0);

        glUniformMatrix4fv(matrixHandler,1,GL_FALSE,mat.data());

        glEnableVertexAttribArray(static_cast<GLuint>(vertexHandler));
        glVertexAttribPointer(static_cast<GLuint>(vertexHandler), 2, GL_FLOAT, GL_FALSE, 16, &coord[0]);
        glEnableVertexAttribArray(static_cast<GLuint>(coordHandler));
        glVertexAttribPointer(static_cast<GLuint>(coordHandler), 2, GL_FLOAT, GL_FALSE, 16, &coord[2]);
        glDrawArrays(GL_TRIANGLE_STRIP,0,4);
        glDisableVertexAttribArray(static_cast<GLuint>(vertexHandler));
        glDisableVertexAttribArray(static_cast<GLuint>(coordHandler));
    }
}

void QtCameraDrawer::glDestroy() {

}