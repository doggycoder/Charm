//
// Created by wuwang on 18-12-26.
//

#ifndef _ENGINE_RENDER_RENDER_H_
#define _ENGINE_RENDER_RENDER_H_

#include "Material.h"

class Model;

class Renderer {
private:
    Model * model{nullptr};

    void drawModel(Model * model);
public:
    void setModel(Model * model){this->model = model;};
    void setMaterial(SPtr<Material> material, const char * name = nullptr);
    void render();
};

#endif //_ENGINE_RENDER_RENDER_H_
