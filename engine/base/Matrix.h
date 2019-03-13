//
// Created by wuwang on 19-1-1.
//

#ifndef _CHARM_BASE_MATRIX_H_
#define _CHARM_BASE_MATRIX_H_

enum ScaleType{
    CENTER_INSIDE,
    CENTER_CROP,
    FIX_XY,
    START_CROP,
    END_CROP,
    FIT_START,
    FIT_END
};

class Matrix {
private:
    int currentPos{0};
protected:
    float value[16];
public:
    static const int M00 = 0;
    static const int M10 = 1;
    static const int M20 = 2;
    static const int M30 = 3;
    static const int M01 = 4;
    static const int M11 = 5;
    static const int M21 = 6;
    static const int M31 = 7;
    static const int M02 = 8;
    static const int M12 = 9;
    static const int M22 = 10;
    static const int M32 = 11;
    static const int M03 = 12;
    static const int M13 = 13;
    static const int M23 = 14;
    static const int M33 = 15;

    Matrix():value{1,0,0,0,
                   0,1,0,0,
                   0,0,1,0,
                   0,0,0,1}{

    }

    float * data(){
        return value;
    }

    float& operator[] (int i);

    Matrix& operator=(Matrix mat);

    Matrix& operator*=(Matrix& mat);

    Matrix operator*(Matrix& mat);

    Matrix operator<<(float a);

    Matrix operator,(float);

    Matrix& scale(float x,float y,float z);
    Matrix& scale(float scale);
    Matrix& translate(float x,float y,float z);
    Matrix& rotate(float x,float y,float z);
    Matrix& rotateEuler(float yaw,float pitch,float roll);

    Matrix& transpose();

    Matrix copy();

    static Matrix createViewMatrix(float posX,float posY,float posZ,
            float lookAtX,float lookAtY,float lookAtZ,
            float upX,float upY,float upZ);

    static Matrix createOrthogonalCamera(float left,float right,float up,float down,float near,float far);

    static Matrix createPerspectiveCamera(float fov,float aspect,float near,float far);

    static Matrix createImageMatrix(float imgWidth,float imgHeight,float viewWidth,float viewHeight,ScaleType type = CENTER_CROP);

};


#endif //CHARM_MATRIX_H
