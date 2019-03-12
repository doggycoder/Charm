#include <random>

template <typename T> Vec3<T> random(Vec3<T> t) {
    std::random_device rd;
    static std::default_random_engine e(rd());
    T ox,oy,oz;
    if(t.x != 0){
        static std::uniform_real_distribution<T> ux(-t.x,t.x);
        ox = ux(e);
    }
    if(t.y != 0){
        static std::uniform_real_distribution<T> uy(-t.y,t.y);
        oy = uy(e);
    }
    if(t.z != 0){
        static std::uniform_real_distribution<T> uz(-t.z,t.z);
        oz = uz(e);
    }
    return {ox,oy,oz};
};

template <typename T> Vec4<T,1> random(Vec4<T,1> t){
    std::random_device rd;
    static std::default_random_engine e(rd());
    Vec3<T> v3(t.x,t.y,t.z);
    v3 = random(v3);
    T ow;
    if(t.w != 0){
        static std::uniform_real_distribution<T> uw(-t.w,t.w);
        ow = uw(e);
    }
    return {v3.x,v3.y,v3.z,ow};
};

template <typename T> T random(T t){
    if(fabsf(t) <= static_cast<T>(0.0000003f)){
        return 0;
    }
    std::random_device rd;
    static std::default_random_engine e(rd());
    static std::uniform_real_distribution<float> uw(-t,t);
    return static_cast<T>(uw(e));
};

template <typename T> T BaseRate<T>::genRate() {
    T r = random(rate);
    return base + r;
}