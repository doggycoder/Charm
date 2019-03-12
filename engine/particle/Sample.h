//
// Created by wuwang on 19-1-18.
//

#ifndef CHARM_PARTICLE_SAMPLE_H
#define CHARM_PARTICLE_SAMPLE_H

#include "Base.h"

class SampleEmitter : public BaseEmitter{
public:
    SampleEmitter();

    void init() override;

    void start() override;

    void stop() override;

    void update(float time) override;
};


#endif //CHARM_SAMPLE_H
