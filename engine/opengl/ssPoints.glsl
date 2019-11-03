const char * ssGlPoints = R"(
#ifdef CODE_TYPE_VS
attribute vec4 aVertexCo;
uniform mat4 uWorldMat;

void main()
{
    gl_Position = uWorldMat * aVertexCo;
}
#endif

#ifdef CODE_TYPE_PS
#ifdef GL_ES
precision lowp float;
#endif

varying vec4 vColor;

void main() {
	gl_FragColor = vec4(1.0, 0.2, 0.5, 1.0);
}
#endif


)";
