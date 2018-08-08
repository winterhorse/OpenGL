#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <string>

#include "obj_loader.h"

//定义一个顶点数组类型
class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord, glm::vec3& normal = glm::vec3(0,0,0)) {
		this->pos = pos;
		this->texCoord = texCoord;		
		this->normal = normal;
	}

	inline glm::vec3* GetPos() { return &pos; }
	inline glm::vec2* GetTexCoord() { return &texCoord; }
	inline glm::vec3* GetNormal() { return &normal; }

private:
	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 normal;
};


//网格
class Mesh
{
public:
	//Mesh(Vertex* vertices, GLuint numVertices);
	Mesh(Vertex* vertices, GLuint numVertices, GLuint* indices, GLuint numIndices);

	Mesh(const std::string& fileName);

	void Draw();

	~Mesh();


private:

	void InitMesh(const IndexedModel& model);

	enum{
		POSITION_VB,
		TEXCOORD_VB,
		NORMAL_VB,		// 法线
		INDEX_VB,		// 索引
		NUM_BUFFERS
	};
	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	GLuint m_drawCount; //需要绘制顶点个数
};

