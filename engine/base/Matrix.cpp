//
// Created by wuwang on 19-1-1.
//

#include <iostream>
#include <cstring>
#include "Matrix.h"
#include "Vec.h"
#include "cmath"
#include <stdarg.h>

Matrix Matrix::createPerspectiveCamera(float fov, float aspect, float near, float far) {
    Matrix mat;
    mat[M00] = 1/(aspect*tanf(fov/2));
    mat[M11] = 1/tanf(fov/2);
    mat[M22] = - (far + near) / (far - near);
    mat[M32] = - 2 * far * near / (far - near);
    mat[M23] = -1.0f;
    mat[M33] = 0.0f;
    return mat;
}

Matrix Matrix::createOrthogonalCamera(float left, float right, float top, float bottom, float near, float far) {
    Matrix mat;
    mat[M00] = 2/(right-left);
    mat[M11] = 2/(top - bottom);
    mat[M22] = - 2/(far-near);
    mat[M03] = - (left + right)/(right - left);
    mat[M13] = - (top + bottom)/(top - bottom);
    mat[M23] = - (near + far)/(far - near);
    return mat;
}

Matrix Matrix::createViewMatrix(float posX, float posY, float posZ, float targetX, float targetY, float targetZ,
                                float upX, float upY, float upZ) {
    Vec3f position(posX,posY,posZ);
    Vec3f target(targetX,targetY,targetZ);
    Vec3f up(upX,upY,upZ);

    Vec3f N = (target - position).normalize();
    Vec3f U = N.copy().cross(up).normalize();
    Vec3f V = U.copy().cross(N).normalize();

    N = -N;

    Matrix mat;
    mat[M00] = U.x;
    mat[M01] = U.y;
    mat[M02] = U.z;

    mat[M10] = V.x;
    mat[M11] = V.y;
    mat[M12] = V.z;

    mat[M20] = N.x;
    mat[M21] = N.y;
    mat[M22] = N.z;

    mat[M03] =  -U.dot(position);
    mat[M13] =  -V.dot(position);
    mat[M23] =  -N.dot(position);
    return mat;
}

Matrix Matrix::createImageMatrix(float imgWidth, float imgHeight, float viewWidth, float viewHeight, ScaleType type) {
    Matrix mat;
    float imgRate = imgWidth / imgHeight;
    float viewRate = viewWidth / viewHeight;
    if(imgRate > viewRate){
        if(type == CENTER_CROP){
            mat << imgRate/viewRate, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
        }else{
            mat<< 1, 0, 0, 0, 0, viewRate/imgRate, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
        }
    }else if(imgRate < viewRate){
        if(type == CENTER_CROP){
            mat << 1, 0, 0, 0, 0, (viewRate/imgRate), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
        }else{
            mat << imgRate/viewRate, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
        }
    }
    return mat;
}

float& Matrix::operator[](int i) {
    return value[i];
}

Matrix& Matrix::operator=(Matrix mat) {
    memcpy(value,mat.value, sizeof(float) * 16);
    return *this;
}

Matrix& Matrix::operator*=(Matrix &mat) {
    Matrix tmp = *this * mat;
    *this = tmp;
    return *this;
}

Matrix Matrix::operator*(Matrix &mat) {
    Matrix temp;
    temp[M00] = value[M00]*mat[M00] + value[M10]*mat[M01] + value[M20]*mat[M02] + value[M30]*mat[M03];
    temp[M01] = value[M01]*mat[M00] + value[M11]*mat[M01] + value[M21]*mat[M02] + value[M31]*mat[M03];
    temp[M02] = value[M02]*mat[M00] + value[M12]*mat[M01] + value[M22]*mat[M02] + value[M32]*mat[M03];
    temp[M03] = value[M03]*mat[M00] + value[M13]*mat[M01] + value[M23]*mat[M02] + value[M33]*mat[M03];

    temp[M10] = value[M00]*mat[M10] + value[M10]*mat[M11] + value[M20]*mat[M12] + value[M30]*mat[M13];
    temp[M11] = value[M01]*mat[M10] + value[M11]*mat[M11] + value[M21]*mat[M12] + value[M31]*mat[M13];
    temp[M12] = value[M02]*mat[M10] + value[M12]*mat[M11] + value[M22]*mat[M12] + value[M32]*mat[M13];
    temp[M13] = value[M03]*mat[M10] + value[M13]*mat[M11] + value[M23]*mat[M12] + value[M33]*mat[M13];

    temp[M20] = value[M00]*mat[M20] + value[M10]*mat[M21] + value[M20]*mat[M22] + value[M30]*mat[M23];
    temp[M21] = value[M01]*mat[M20] + value[M11]*mat[M21] + value[M21]*mat[M22] + value[M31]*mat[M23];
    temp[M22] = value[M02]*mat[M20] + value[M12]*mat[M21] + value[M22]*mat[M22] + value[M32]*mat[M23];
    temp[M23] = value[M03]*mat[M20] + value[M13]*mat[M21] + value[M23]*mat[M22] + value[M33]*mat[M23];

    temp[M30] = value[M00]*mat[M30] + value[M10]*mat[M31] + value[M20]*mat[M32] + value[M30]*mat[M33];
    temp[M31] = value[M01]*mat[M30] + value[M11]*mat[M31] + value[M21]*mat[M32] + value[M31]*mat[M33];
    temp[M32] = value[M02]*mat[M30] + value[M12]*mat[M31] + value[M22]*mat[M32] + value[M32]*mat[M33];
    temp[M33] = value[M03]*mat[M30] + value[M13]*mat[M31] + value[M23]*mat[M32] + value[M33]*mat[M33];
    return temp;
}

Matrix& Matrix::scale(float x, float y, float z) {
    Matrix temp;
    temp[M00] = x;
    temp[M11] = y;
    temp[M22] = z;
    *this *= temp;
    return *this;
}

Matrix& Matrix::scale(float scale) {
    return this->scale(scale,scale,scale);
}

Matrix& Matrix::translate(float x, float y, float z) {
    Matrix temp;
    temp[M03] = x;
    temp[M13] = y;
    temp[M23] = z;
    *this *= temp;
    return *this;
}

Matrix& Matrix::rotate(float x, float y, float z) {
    Matrix temp;
    auto M_PI_180 = (float) (M_PI / 180.0f);
    x *= M_PI_180;
    y *= M_PI_180;
    z *= M_PI_180;
    float cx = cosf(x);
    float sx = sinf(x);
    float cy = cosf(y);
    float sy = sinf(y);
    float cz = cosf(z);
    float sz = sinf(z);
    float cx_sy = cx * sy;
    float sx_sy = sx * sy;

    temp[M00]  =   cy * cz;
    temp[M10]  =  -cy * sz;
    temp[M20]  =   sy;

    temp[M01]  =  sx_sy * cz + cx * sz;
    temp[M11]  = -sx_sy * sz + cx * cz;
    temp[M21]  =  -sx * cy;

    temp[M02]  = -cx_sy * cz + sx * sz;
    temp[M12]  =  cx_sy * sz + sx * cz;
    temp[M22] =  cx * cy;

    *this *= temp;
    return *this;
}

Matrix& Matrix::rotateEuler(float yaw, float pitch, float roll) {
    Matrix temp;
    auto M_PI_180 = M_PI / 180.0f;
    yaw   *= M_PI_180;
    pitch *= M_PI_180;
    roll  *= M_PI_180;
    float cx = cosf(pitch);
    float sx = sinf(pitch);
    float cy = cosf(yaw);
    float sy = sinf(yaw);
    float cz = cosf(roll);
    float sz = sinf(roll);
    float sx_sy = sx * sy;
    float sy_cz = sy * cz;
    float cy_sz = cy * sz;

    temp[M00]  =   cy * cz + sx_sy * sz;
    temp[M10]  =   cx * sz;
    temp[M20]  =   sx * cy_sz - sy_cz;

    temp[M01]  =  sx_sy * cz - cy_sz;
    temp[M11]  =  cx * cz;
    temp[M21]  =  sx * cy * cz + sy * sz;

    temp[M02]  =  sy_cz;
    temp[M12]  =  -sx;
    temp[M22]  =  cy * cz;

    *this *= temp;
    return *this;
}

Matrix& Matrix::transpose() {
    std::swap(value[M01],value[M10]);
    std::swap(value[M02],value[M20]);
    std::swap(value[M03],value[M30]);
    std::swap(value[M12],value[M21]);
    std::swap(value[M13],value[M31]);
    std::swap(value[M23],value[M32]);
    return *this;
}

Matrix Matrix::copy() {
    Matrix temp = *this;
    return temp;
}

Matrix Matrix::operator<<(float a) {
    currentPos = 0;
    value[currentPos++] = a;
    return *this;
}

Matrix Matrix::operator,(float a) {
    value[currentPos++] = a;
    return *this;
}
