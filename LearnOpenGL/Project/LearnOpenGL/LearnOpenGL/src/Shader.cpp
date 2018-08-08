#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	ifstream vertexFile;
	ifstream fragmnetFile;

	vertexFile.exceptions(ifstream::failbit || ifstream::badbit);
	fragmnetFile.exceptions(ifstream::failbit || ifstream::badbit);

	try{
		// open file
		vertexFile.open(vertexPath);
		fragmnetFile.open(fragmentPath);

		if ( !vertexFile.is_open() || !fragmnetFile.is_open() ){
			throw exception("open file error!\n");
		}

		stringstream vShaderStream, fShaderStream;
		vShaderStream << vertexFile.rdbuf();
		fShaderStream << fragmnetFile.rdbuf();

		vertexFile.close();
		fragmnetFile.close();

		vShaderString = vShaderStream.str();
		fShaderString = fShaderStream.str();

		vShaderCode = vShaderString.c_str();
		fShaderCode = fShaderString.c_str();

		//cout << vShaderCode << endl;
		//cout << fShaderCode << endl;

		/***********************************************************************************************
		* creat and complie shader
		***********************************************************************************************/
		// Vertex shader
		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vShaderCode, NULL);
		glCompileShader(vertexShader);

		// check for vertex shader complie errors
		checkCompileErrors(vertexShader, "VERTEXT");

		// fragment shader
		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
		glCompileShader(fragmentShader);

		// check for fragment shader errors
		checkCompileErrors(fragmentShader, "VERTEXT");

		// link shader		
		ID = glCreateProgram();
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);
		glLinkProgram(ID);

		// check for link errors
		checkCompileErrors(ID, "PROGRAM");

		// delete shader
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	} catch(const std::exception& e) {
		cout << e.what();
	}
}

void Shader::checkCompileErrors(unsigned int shader, std::string type){
	int  success;
	char infoLog[512];

	if ( "PROGRAM" != type){
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	} else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
	}
}

void Shader::use(){
	glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void Shader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

Shader::~Shader()
{
}
