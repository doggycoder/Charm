//
// Created by wuwang on 19-1-17.
//

#ifndef _CHARM_PARTICLE_BASE_H_
#define _CHARM_PARTICLE_BASE_H_

#include <base/Base.h>
#include <base/Random.h>
#include <cstdint>
#include <vector>
#include <queue>

enum AtomType{

};

enum AtomBlendType{
    eABT_NONE = 0
};

enum EmitterState{
    eES_UPDATE,eES_EMIT
};

class Atom{
public:
    Vec3f currentPos;                       //粒子当前的位置
    AtomType type;                          //粒子类型

    Color4f currentColor;                   //粒子当前颜色
    Color4f startColor;                     //粒子开始时的颜色
    Color4f endColor;                       //粒子死亡时候的颜色

    float totalLifeTime;                    //粒子的生命总时长
    float currentLifeTime;                  //粒子当前已经存活的时长
    Vec3f currentSpeed;                     //粒子当前速度
    Vec3f currentRotate;                    //粒子当前旋转角度
    Vec3f rotateSpeed;                      //粒子当前旋转速度
    float scaleSpeed;                       //粒子缩放大小
    float width;                            //粒子宽度
    float height;                           //粒子高度
};

class BaseEmitter{
private:
    float passTime{0.0f};
    float frameTime{0.0f};

    float currentPeriodPassTime{0};          //当前发射周期已经过去的时间
    float currentPeriod{0};                  //发射周期
    float currentEmitTime{0};                //发射持续时间
    int currentEmitSpeed{0};                 //发射粒子速度
protected:
    RateF emitPeriod{};                      //多久发射一次粒子
    RateF emitTime{};                        //一次发射持续多久
    RateI emitSpeed{};                       //发射速度，每秒产生多少个粒子

    RateVec emitPosition{};                  //发射器的位置
    RateVec emitForce{};                     //发射出的粒子受到的作用力
    RateColor atomStartColor;                //发射初始颜色
    RateColor atomEndColor;                  //发射初始颜色
    RateF atomScale{1.0f,0.0f};              //发射出的粒子的缩放大小
    RateF atomScaleSpeed{0.0f,0.0f};         //发射出的粒子的缩放速度
    RateVec atomRotate{};                    //发射出的粒子的初始旋转角度
    RateVec atomRotateSpeed{};               //发射出的粒子的旋转速度
    RateF atomLifeTime{};                    //发射出的粒子的生命时长
    RateVec atomSpeed{};                     //发射出的粒子的运动速度

    float atomWidth;                         //发射出的粒子的基准宽度
    float atomHeight;                        //发射出的粒子的基准高度
    uint32_t atomMaxNum{};                   //支持的最大粒子个数
    AtomBlendType blendType{eABT_NONE};      //发射出的粒子的融合方式

    std::vector<Atom*> livingAtoms;
    std::queue<Atom*> cacheAtoms;

protected:

    virtual Atom * genAtom();
    virtual Atom * genAndInitAtom();
    virtual void emitAtomIfNeeded();

public:
    virtual inline void setEmitPeriod(RateF& p){
        this->emitPeriod = p;
    }
    virtual inline void setEmitTime(RateF& t){
        this->emitTime = t;
    }
    virtual inline void setEmitSpeed(RateI& s){
        this->emitSpeed = s;
    }
    virtual inline void setAtomMaxNum(uint32_t num){
        this->atomMaxNum = num;
    };
    virtual inline void setPosition(RateVec& pos){
        this->emitPosition = pos;
    }

    virtual void init();
    virtual void start();
    virtual void stop();
    virtual void update(float time);

};

class Observer{

};

#endif
