const char * ssFragImage = R"(

#ifdef GL_ES
precision lowp float;
#endif

uniform sampler2D uTexture;

varying vec2 vCoord;

void main() {
	gl_FragColor = texture2D(uTexture,vCoord);
}

)";
