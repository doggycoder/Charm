//
// Created by wuwang on 18-12-24.
//

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

template <typename T> Vec3<T>& Vec3<T>::operator*=(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;
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

template <typename T, int val> Vec4<T,val>::Vec4(T x,T y,T z,T w){
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

template <typename T, int val> Vec4<T,val>::Vec4(T d) {
    x = d;
    y = d;
    z = d;
    w = d;
}

template <typename T, int val> Vec4<T,val>::Vec4(Vec3<T> &in, T d) {
    x = in.x;
    y = in.y;
    z = in.z;
    w = d;
}