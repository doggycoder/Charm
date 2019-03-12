//
// Created by wuwang on 18-12-24.
//

#ifndef _CHARM_VEC_H_
#define _CHARM_VEC_H_

#include <cmath>

template <typename T>
class Vec2{
public:
    T x;
    T y;

    Vec2() = default;

    Vec2(T x,T y);

    Vec2& operator+=(Vec2& a);

    Vec2  operator+(Vec2& a);

    Vec2& operator-=(Vec2& a);

    Vec2 operator-(Vec2& a);

};


template <typename T>
class Vec3{
public:
    T x;
    T y;
    T z;

    Vec3() = default;

    Vec3(T x,T y,T z);

    Vec3&operator+=(Vec3& a);

    Vec3 operator+(Vec3& a);

    Vec3&operator-=(Vec3& a);

    Vec3 operator-(Vec3& a);

    Vec3 operator-();

    Vec3& operator=(Vec3 a);

    Vec3&operator*=(float scale);

    Vec3& normalize();

    T length2();

    T length();

    Vec3 copy();

    Vec3& cross(Vec3& vec);

    T dot(Vec3& a);

};

template <typename T,int val>
class Vec4{
public:
    T x;
    T y;
    T z;
    T w;

    Vec4(T x,T y,T z,T w = val);

    explicit Vec4(T d = val);

    explicit Vec4(Vec3<T>& in,T d = val);

    Vec4 operator+(Vec4& a);

    Vec4& operator=(Vec4 a);

};

typedef Vec2<double>                Vec2d;
typedef Vec2<float>                 Vec2f;
typedef Vec2<int>                   Vec2i;
typedef Vec3<double>                Vec3d;
typedef Vec3<float>                 Vec3f;
typedef Vec3<int>                   Vec3i;
typedef Vec4<float,1>               Vec4f;
typedef Vec4<float,1>               Color4f;
typedef Vec4<unsigned char,0>       Color4i;

#include "Vec.inl"
#endif //CHARM_VEC_H
