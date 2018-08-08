#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform {
public:
	Transform(
		const glm::vec3 &pos = glm::vec3(),
		const glm::vec3 &rot = glm::vec3(),
		const glm::vec3 &scale = glm::vec3(1.0f, 1.0f, 1.0f)) 
	{
		this->pos = pos;
		this->rot = rot;
		this->scale = scale;
	}
	
	inline glm::vec3* GetPos()  { return &pos; }
	inline glm::vec3* GetRot()  { return &rot; }
	inline glm::vec3* GetScale()  { return &scale; }

	inline void SetPos(glm::vec3& pos) { this->pos = pos; }
	inline void SetRot(glm::vec3& rot) { this->rot = rot; }
	inline void SetScale(glm::vec3& scale) { this->scale = scale; }

	inline glm::mat4 GetModel() const {
		glm::mat4 posMat = glm::translate(glm::mat4(), pos);
		glm::mat4 scaleMat = glm::scale(glm::mat4(), scale);	
		glm::mat4 rotX = glm::rotate(glm::mat4(), (rot.x), glm::vec3(1.0, 0.0, 0.0));
		glm::mat4 rotY = glm::rotate(glm::mat4(), (rot.y), glm::vec3(0.0, 1.0, 0.0));
		glm::mat4 rotZ = glm::rotate(glm::mat4(), (rot.z), glm::vec3(0.0, 0.0, 1.0));
		glm::mat4 rotMat = rotX * rotY * rotZ;

		return posMat * rotMat * scaleMat;
	}

private:
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;
};