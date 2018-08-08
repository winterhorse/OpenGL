#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	void use();
	// utility uniform functions
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;

public:
	string vShaderString;
	string fShaderString;

	const char* vShaderCode;
	const char* fShaderCode;
	unsigned int ID;

private:
	void checkCompileErrors(unsigned int shader, std::string type);

	
};

