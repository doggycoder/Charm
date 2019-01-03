const char * ssFragColor = R"(

#ifdef GL_ES
precision lowp float;
#endif

varying vec4 vColor;

void main() {
	gl_FragColor = vColor;
}

)";
