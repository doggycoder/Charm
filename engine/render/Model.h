//
// Created by wuwang on 19-9-5.
//

#pragma once

#include <cstring>
#include "Material.h"
#include "Mesh.h"

class Model {
public:
    SPtr<Mesh> mesh;
    SPtr<Material> material;
    Matrix  matrix;
    std::map<const char *, Model*> childes;
};


