//
// Created by wuwang on 19-1-4.
//

#include "Camera.h"

void Camera::setViewPort(float x, float y, float width, float height) {
    rect.x = x;
    rect.y = y;
    rect.width = width;
    rect.height = height;
}

//返回三维点在二维屏幕上的投影点
//osg::Vec3d WorldToScreen(osgViewer::View* view,osg::Vec3 worldpoint)
//{
//    double in[4],out[4];
//
//    in[0] = worldpoint._v[0];
//    in[1] = worldpoint._v[1];
//    in[2] = worldpoint._v[2];
//    in[3] = 1.0;
//    //获得当前的投影矩阵和模型视图矩阵
//    osg::Matrix projectMatrix = view->getCamera()->getProjectionMatrix();
//    osg::Matrix viewMatrix = view->getCamera()->getViewMatrix();
//    //变换模型视图矩阵
//    double modelViewMatrix[16];
//    memcpy(modelViewMatrix,viewprojectMatrix.ptr(),sizeof(GLdouble)*16);
//    Transform_Point(out,modelViewMatrix,in);
//
//    //变换投影矩阵
//    double myprojectMatrix[16];
//    memcpy(myprojectMatrix,projectMatrix.ptr(),sizeof(GLdouble)*16);
//    Transform_Point(out,myprojectMatrix,in);
//
//    //变换视口变换矩阵
//    if(in[3] == 0.0)
//        return osg::Vec3d(0,0,0);
//
//    in[0]/=in[3];
//    in[1]/=in[3];
//    in[2]/=in[3];
//
//    int viewPort[4];
//    osg::Viewport* myviewport = view->getCamera()->getViewport();
//    viewPort[0] = myviewport->x();
//    viewPort[1] = myviewport->y();
//    viewPort[2] = myviewport->width();
//    viewPort[3] = myviewport->height();
//
//    //计算二维屏幕投影点
//    osg::Vec3d screenPoint;
//    screenPoint._v[0] = (int)(viewPort[0] + (1+in[0])*viewPort[2]/2+0.5);
//    screenPoint._v[0] = (int)(viewPort[1] + (1+in[1])*viewPort[3]/2+0.5);
//    screenPoint._v[2] = 0;
//
//    return screenPoint;
//}

Vec2f Camera::worldToScreen(Vec3f &point) {
    Vec2f vec;
    vec.x = point.x;
    Vec4f wPoint(point);
    return vec;
}