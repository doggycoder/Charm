#include <utility>

#include <utility>

#include <memory>

//
// Created by wuwang on 18-12-26.
//

#include "Drawer.h"
#include "Cube.h"
#include "opengl/GlTool.h"
#include "opengl/Shader.h"

//todo 透视投影及正交投影正确，view矩阵暂时不正确
Drawer::Drawer() {
    cube = std::make_shared<Cube>(1.0f);
//    cube->setPosition(-1,1,-10);
//    matrix = Matrix::createPerspectiveCamera(45,368/640.0f,1.0f,500.0f);
    matrix = Matrix::createOrthogonalCamera(-1,1,1*640/368.0f,-1*640/368.0f,1,500);
//    model.translate(0.5f,0.5f,-8);
    model.scale(1.0f);
    model.rotate(45,0,135);
}

void Drawer::init() {
    programId = GlTool::compile(ssVertexColorAndMatrix,ssFragColor);
    glVert = glGetAttribLocation(programId,"aPosition");
    glColor = glGetAttribLocation(programId,"aColor");
    glMatrix = glGetUniformLocation(programId,"uPosMatrix");

}

void Drawer::draw() {
    angle += M_PI /90;
    Matrix view = Matrix::createViewMatrix(5 * sinf(angle),0,5 * cosf(angle),0,0,0,0,1,0);

    glUseProgram(programId);
    glUniformMatrix4fv(glMatrix,1,GL_FALSE,(matrix * view * model).transpose().data());
    glEnableVertexAttribArray(glVert);
    glVertexAttribPointer(glVert,3,GL_FLOAT,GL_FALSE,0,cube->vertex);
    glEnableVertexAttribArray(glColor);
    glVertexAttribPointer(glColor,4,GL_FLOAT,GL_FALSE,0,cube->colors);
    glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_SHORT,cube->index);
}