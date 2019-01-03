//
// Created by wuwang on 19-1-1.
//

#ifndef _CHARM_BASE_MATRIX_H_
#define _CHARM_BASE_MATRIX_H_

class Matrix {
protected:
    float value[16];
public:
    static const int M00 = 0;
    static const int M01 = 1;
    static const int M02 = 2;
    static const int M03 = 3;
    static const int M10 = 4;
    static const int M11 = 5;
    static const int M12 = 6;
    static const int M13 = 7;
    static const int M20 = 8;
    static const int M21 = 9;
    static const int M22 = 10;
    static const int M23 = 11;
    static const int M30 = 12;
    static const int M31 = 13;
    static const int M32 = 14;
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

    static Matrix createViewMatrix(float posX,float posY,float posZ,
            float lookAtX,float lookAtY,float lookAtZ,
            float upX,float upY,float upZ);

    static Matrix createOrthogonalCamera(float left,float right,float up,float down,float near,float far);

    static Matrix createPerspectiveCamera(float fov,float aspect,float near,float far);

};


#endif //CHARM_MATRIX_H
