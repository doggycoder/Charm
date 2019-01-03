//
// Created by wuwang on 18-12-26.
//

#include "GL/glew.h"
#include "GL/glut.h"
#include "Render.h"
#include "opengl/Shader.h"
#include "assert.h"

void Render::init() {
    GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    GLint length;
    glShaderSource(vertexShaderId,1,&ssVertexColorAndMatrix,&length);
    GLuint fragShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    assert(fragShaderId != 0);
}