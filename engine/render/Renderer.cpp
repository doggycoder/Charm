//
// Created by wuwang on 18-12-26.
//

#include "GL/glew.h"
#include "GL/glut.h"
#include "Renderer.h"
#include "opengl/ShaderString.h"
#include "assert.h"
#include "Model.h"
#include "base/IContext.h"

Renderer::Renderer() {
    defaultMaterial = new Material();
    SPtr<Shader> s;
    s = SPtr<Shader>(new Shader(ssGlPoints));
    defaultMaterial->setShader(s);
}

Renderer::~Renderer() {
    delete defaultMaterial;
}

void Renderer::init(IContext *context) {
    this->context = context;
    defaultMaterial->init(context);
    defaultMaterial->onLoad();
}

void Renderer::drawModel(Model *model) {
    if(!model)return;
    if(!model->mesh && model->childes.empty())return;
    if(model->material){
        model->material->apply();
    }else{
        defaultMaterial->apply();
    }
    for (auto& m : model->childes){
        drawModel(m.second);
    }

}

void Renderer::renderMesh(Mesh *mesh, Material *material) {
    //todo material 为空的时候绘制白色的点
    if(!mesh){
        return;
    }
    //挂载material
    if(!material){
        //执行渲染
        defaultMaterial->setParam(paramWorldMat, mesh->worldMat);
        defaultMaterial->apply();
        mesh->render(context, defaultMaterial->getProgramId());
    }else{
        material->setParam(paramWorldMat, mesh->worldMat);
        material->apply();
        //执行渲染
        mesh->render(context, material->getProgramId());
    }
}

void Renderer::renderModel(Model *model) {
    drawModel(model);
}

