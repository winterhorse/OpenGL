#version 120

attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;

varying vec2 texCoord_out;
varying vec3 normal_out;

uniform mat4 transform;

void main(){
	gl_Position = transform * vec4(position, 1.0f);
	texCoord_out = texCoord;
	normal_out = (transform * vec4(normal, 0)).xyz;
}