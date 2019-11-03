//
// Created by wuwang on 19-1-4.
//

#ifndef _CHARM_CAMERA_H_
#define _CHARM_CAMERA_H_

#include "base/Vec.h"
#include "base/Matrix.h"
#include "base/Rect.h"

class Camera {
private:
    Matrix projection;
    Matrix view;

    Matrix projectViewMatrix;

    RectF  rect;
public:
    void setViewPort(float x,float y,float width,float height);
    Vec2f worldToScreen(Vec3f& point);
};


#endif
