//
// Created by wuwang on 19-1-19.
//

#ifndef CHARM_RANDOM_H
#define CHARM_RANDOM_H

#include "Vec.h"

template <typename T> T random(T t);

template <typename T>
class BaseRate{
public:
    T base{};
    T rate{};

    BaseRate() = default;

    BaseRate(T base,T rate){
        this->base = base;
        this->rate = rate;
    }

    BaseRate&operator=(BaseRate r){
        this->base = r.base;
        this->rate = r.rate;
        return *this;
    }

    virtual T genRate();
};
typedef BaseRate<float> RateF;
typedef BaseRate<int> RateI;
typedef BaseRate<Vec3f> RateVec;
typedef BaseRate<Color4f> RateColor;

#include "Random.inl"
#endif //CHARM_RANDOM_H
