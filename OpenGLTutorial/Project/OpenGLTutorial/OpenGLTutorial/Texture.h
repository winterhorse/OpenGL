#pragma once
#include <GL/glew.h>
#include <string>
#include <iostream>



class Texture
{
public:
	Texture(const std::string& fileName);
	void Bind();	

	virtual ~Texture();

private:
	GLuint m_texture;
};

