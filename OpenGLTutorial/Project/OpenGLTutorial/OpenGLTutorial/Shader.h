#pragma once
#include <GL/glew.h>
#include <string>
#include "Transform.h"
#include "Camera.h"

class Shader
{
public:
	Shader(const std::string& fileName);
	void Bind();

	void Update(const Transform& transform, const Camera& camera);
	~Shader();

private:
	enum{
		TRANSFORM_U,
		NUM_UNIFORM
	};
	static const GLuint NUM_SHADERS = 2;
	GLuint m_program;

	// 着色器数组 对应顶点着色器和片元着色器
	GLuint m_shaders[NUM_SHADERS];

	GLuint m_uniforms[NUM_UNIFORM];

};

