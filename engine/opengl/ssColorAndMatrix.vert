const char * ssVertexColorAndMatrix = R"(

attribute vec4 aPosition;
attribute vec4 aColor;
uniform mat4 uPosMatrix;

varying vec4 vColor;

void main()
{
    gl_Position = uPosMatrix * aPosition;
    vColor = aColor;
}

)";
