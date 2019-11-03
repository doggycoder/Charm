//
// Created by wuwang on 18-12-26.
//

#ifndef _ENGINE_RENDER_RENDER_H_
#define _ENGINE_RENDER_RENDER_H_

#include <base/Base.h>
#include <base/MParam.h>
#include "RenderName.h"

class Model;
class Mesh;
class Material;
class IContext;

class Renderer {
private:
    Material * defaultMaterial{nullptr};
    IContext * context{nullptr};

    MParam paramWorldMat = MParam(uWorldMatrix);

    void drawModel(Model * model);
public:
    Renderer();
    ~Renderer();

    void init(IContext* context);
    void renderMesh(Mesh* mesh, Material* material = nullptr);
    void renderModel(Model* model);
};

#endif //_ENGINE_RENDER_RENDER_H_
