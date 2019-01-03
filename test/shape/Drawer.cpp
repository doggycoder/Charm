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
//    cube->setPosition(0,0,-10);
//    matrix = Matrix::createPerspectiveCamera(45,368/640.0f,1.0f,500.0f);
    matrix = Matrix::createOrthogonalCamera(-1,1,1*640/368.0f,-1*640/368.0f,1,500);
    Matrix view = Matrix::createViewMatrix(-5,10,-10,0,0,0,0,5,0);
    view *= matrix;
    matrix = view;
}

void Drawer::init() {
    programId = GlTool::compile(ssVertexColorAndMatrix,ssFragColor);
    glVert = glGetAttribLocation(programId,"aPosition");
    glColor = glGetAttribLocation(programId,"aColor");
    glMatrix = glGetUniformLocation(programId,"uPosMatrix");

}

void Drawer::draw() {
    glUseProgram(programId);
    glUniformMatrix4fv(glMatrix,1,GL_FALSE,matrix.data());
    glEnableVertexAttribArray(glVert);
    glVertexAttribPointer(glVert,3,GL_FLOAT,GL_FALSE,0,cube->vertex);
    glEnableVertexAttribArray(glColor);
    glVertexAttribPointer(glColor,4,GL_FLOAT,GL_FALSE,0,cube->colors);
    glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_SHORT,cube->index);
}