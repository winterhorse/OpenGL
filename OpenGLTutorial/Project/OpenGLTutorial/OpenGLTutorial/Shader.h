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

	// ��ɫ������ ��Ӧ������ɫ����ƬԪ��ɫ��
	GLuint m_shaders[NUM_SHADERS];

	GLuint m_uniforms[NUM_UNIFORM];

};

