//
// Created by wuwang on 19-10-7.
//

#pragma once

#include <base/Base.h>
#include "QOpenGLItem.h"

class IContext;
class Mesh;


class EffectRenderer : public Render {
private:
    int width{0};
    int height{0};
    IContext* context{nullptr};
    SPtr<Mesh> mesh{nullptr};
public:
    EffectRenderer();
    void onInit() override;
    void onSizeChanged(int width,int height) override;
    void onDrawFrame() override;
};


