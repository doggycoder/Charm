const char * ssVertexImage = R"(

attribute vec4 aPosition;
attribute vec2 aCoord;

varying vec2 vCoord;

void main()
{
    gl_Position = aPosition;
    vCoord = aCoord;
}

)";
