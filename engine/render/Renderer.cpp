//
// Created by wuwang on 18-12-26.
//

#include "GL/glew.h"
#include "GL/glut.h"
#include "Renderer.h"
#include "opengl/Shader.h"
#include "assert.h"
#include "Model.h"

void Renderer::setMaterial(SPtr<Material> material, const char *name) {

}

void Renderer::drawModel(Model *model) {
    if(!model)return;
    if(!model->mesh && model->childes.empty())return;
    if(model->material){
        model->material->apply();
    }
    for (auto& m : model->childes){
        drawModel(m.second);
    }

}

void Renderer::render() {
    drawModel(model);
}