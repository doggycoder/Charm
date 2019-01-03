//
// Created by wuwang on 18-12-24.
//

#include "Vec.h"
#include "cmath"

template <typename T> Vec2<T>::Vec2(T x, T y) {
    this->x = x;
    this->y = y;
};

template <typename T> Vec2<T>& Vec2<T>::operator+=(Vec2<T> &a){
    this->x += a.x;
    this->y += a.y;
    return *this;
};

template <typename T> Vec2<T> Vec2<T>::operator+(Vec2<T> &a) {
    return {x+a.x,y+a.y};
};

template <typename T> Vec2<T>& Vec2<T>::operator-=(Vec2 &a){
    x += a.x;
    y += a.y;
    return *this;
}

template <typename T> Vec2<T> Vec2<T>::operator-(Vec2 &a){
    return {x-a.x,y-a.y};
}

template <typename T> Vec3<T>::Vec3(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

template <typename T> Vec3<T>& Vec3<T>::operator+=(Vec3<T> &a){
    this->x += a.x;
    this->y += a.y;
    this->z += a.z;
    return *this;
};

template <typename T> Vec3<T> Vec3<T>::operator+(Vec3<T> &a) {
    return {x+a.x,y+a.y,z+a.z};
};

template <typename T> Vec3<T>& Vec3<T>::operator-=(Vec3 &a){
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return *this;
};

template <typename T> Vec3<T>& Vec3<T>::operator*=(float length) {
    x *= length;
    y *= length;
    z *= length;
    return *this;
}

template <typename T> Vec3<T> Vec3<T>::operator-(Vec3 &a){
    return {x - a.x,y - a.y,z - a.z};
};

template <typename T> T Vec3<T>::length() {
    return sqrt(length2());
}

template <typename T> T Vec3<T>::length2() {
    return x*x+y*y+z*z;
}

template <typename T> Vec3<T>& Vec3<T>::normalize() {
    (*this) *= (1/length());
    return *this;
}

template <typename T> Vec3<T>& Vec3<T>::cross(Vec3 &vec) {
    T tmpX = y * vec.z - z * vec.y;
    T tmpY = z * vec.x - x * vec.z;
    T tmpZ = x * vec.y - y * vec.x;
    x = tmpX;
    y = tmpY;
    z = tmpZ;
    return *this;
}

template <typename T> Vec3<T> Vec3<T>::copy() {
    return {x,y,z};
}

template <typename T> T Vec3<T>::dot(Vec3 &a) {
    return x*a.x + y*a.y + z*a.z;
}