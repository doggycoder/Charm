//
// Created by wuwang on 19-1-1.
//

#include <iostream>
#include <cstring>
#include "Matrix.h"
#include "Vec.h"
#include "cmath"

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
    mat[M22] = -2/(far-near);
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
    Vec3f U = up.copy().cross(N).normalize();
    Vec3f V = N.copy().cross(U).normalize();

    Matrix mat;
    mat[M00] = U.x;
    mat[M10] = U.y;
    mat[M20] = U.z;

    mat[M01] = V.x;
    mat[M11] = V.y;
    mat[M21] = V.z;

    mat[M02] = N.x;
    mat[M12] = N.y;
    mat[M22] = N.z;

    mat[M03] = U.dot(position);
    mat[M13] = V.dot(position);
    mat[M23] = N.dot(position);
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
    temp[M00] = value[M00]*mat[M00] + value[M01]*mat[M10] + value[M02]*mat[M20] + value[M03]*mat[M30];
    temp[M10] = value[M10]*mat[M00] + value[M11]*mat[M10] + value[M12]*mat[M20] + value[M13]*mat[M30];
    temp[M20] = value[M20]*mat[M00] + value[M21]*mat[M10] + value[M22]*mat[M20] + value[M23]*mat[M30];
    temp[M30] = value[M30]*mat[M00] + value[M31]*mat[M10] + value[M32]*mat[M20] + value[M33]*mat[M30];

    temp[M01] = value[M00]*mat[M01] + value[M01]*mat[M11] + value[M02]*mat[M21] + value[M03]*mat[M31];
    temp[M11] = value[M10]*mat[M01] + value[M11]*mat[M11] + value[M12]*mat[M21] + value[M13]*mat[M31];
    temp[M21] = value[M20]*mat[M01] + value[M21]*mat[M11] + value[M22]*mat[M21] + value[M23]*mat[M31];
    temp[M31] = value[M30]*mat[M01] + value[M31]*mat[M11] + value[M32]*mat[M21] + value[M33]*mat[M31];

    temp[M02] = value[M00]*mat[M02] + value[M01]*mat[M12] + value[M02]*mat[M22] + value[M03]*mat[M32];
    temp[M12] = value[M10]*mat[M02] + value[M11]*mat[M12] + value[M12]*mat[M22] + value[M13]*mat[M32];
    temp[M22] = value[M20]*mat[M02] + value[M21]*mat[M12] + value[M22]*mat[M22] + value[M23]*mat[M32];
    temp[M32] = value[M30]*mat[M02] + value[M31]*mat[M12] + value[M32]*mat[M22] + value[M33]*mat[M32];

    temp[M03] = value[M00]*mat[M03] + value[M01]*mat[M13] + value[M02]*mat[M23] + value[M03]*mat[M33];
    temp[M13] = value[M10]*mat[M03] + value[M11]*mat[M13] + value[M12]*mat[M23] + value[M13]*mat[M33];
    temp[M23] = value[M20]*mat[M03] + value[M21]*mat[M13] + value[M22]*mat[M23] + value[M23]*mat[M33];
    temp[M33] = value[M30]*mat[M03] + value[M31]*mat[M13] + value[M32]*mat[M23] + value[M33]*mat[M33];
    return temp;
}