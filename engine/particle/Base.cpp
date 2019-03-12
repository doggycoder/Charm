//
// Created by wuwang on 19-1-17.
//

#include "Base.h"

void BaseEmitter::init() {

}

void BaseEmitter::start() {

}

void BaseEmitter::stop() {

}

void BaseEmitter::update(float time) {
    frameTime = time;
    currentPeriodPassTime += time;
    if(currentPeriodPassTime > currentPeriod){
        currentPeriod = emitPeriod.genRate();
        currentEmitTime = emitTime.genRate();
        currentEmitSpeed = emitSpeed.genRate();
        currentPeriodPassTime = 0;
    }

    emitAtomIfNeeded();


    passTime += frameTime;
}

void BaseEmitter::emitAtomIfNeeded() {
    if(livingAtoms.size() >= atomMaxNum){
        return;
    }

    if(currentPeriodPassTime <= currentEmitTime){
        //一个周期发射的粒子数目/发射时间*本帧耗时=实际发射速度
        int num = static_cast<int>(currentEmitSpeed * currentPeriod / currentEmitTime * frameTime);
        while(num-->0){
            SPtr<Atom> atom = genAndInitAtom();
            if(atom == nullptr){
                return;
            }
            livingAtoms.push_back(atom);
        }
    }

}

SPtr<Atom> BaseEmitter::genAtom() {
    if(livingAtoms.size() >= atomMaxNum){
        return nullptr;
    }
    SPtr<Atom> d;
    if(!cacheAtoms.empty()){
        d = cacheAtoms.front();
        cacheAtoms.pop();
    }else{
        d = std::make_shared<Atom>();
    }
    return d;
}

SPtr<Atom> BaseEmitter::genAndInitAtom() {
    SPtr<Atom> atom = genAtom();
    if(atom != nullptr){
        atom->startColor = atomStartColor.genRate();
        atom->currentColor = atom->startColor;
        atom->endColor = atomEndColor.genRate();
        atom->currentPos = emitPosition.genRate();
        atom->totalLifeTime = atomLifeTime.genRate();
        float atomScaleSize = atomScale.genRate();
        atom->width = atomWidth * atomScaleSize;
        atom->height = atomHeight * atomScaleSize;
        atom->scaleSpeed = atomScaleSpeed.genRate();
        atom->currentSpeed = atomSpeed.genRate();
        atom->currentRotate = atomRotate.genRate();
        atom->rotateSpeed = atomRotateSpeed.genRate();
    }
    return atom;
}
