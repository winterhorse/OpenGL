#version 120

uniform sampler2D diffuse;

varying vec2 texCoord_out;
varying vec3 normal_out;

void main(){
	//gl_FragColor = texture2D(diffuse, texCoord_out);

	gl_FragColor = texture2D(diffuse, texCoord_out) * clamp(dot(-vec3(0,1,1), normal_out), 0.1, 1.0);
}