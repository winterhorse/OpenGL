#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
public:
	// fov 视角的区域 弧度
	// aspect 纵横比
	// 
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar) {
		this->pos = pos;
		this->forword = glm::vec3(0.0f, 0.0f, 1.0f);
		this->up = glm::vec3(0.0f, 1.0f, 1.0f);
		this->projection = glm::perspective(fov, aspect, zNear, zFar);

	}

	inline glm::mat4 GetViewProjection() const {
		return projection * glm::lookAt(pos, pos + forword, up); // 照相机坐标矩阵
	}

private:
	glm::mat4 projection;	// 透视投影矩阵
	glm::vec3 pos;			// 照相机的位置
	glm::vec3 forword;		// 正前方 视角的方向 前景 
	glm::vec3 up;			// 正上方 视角的方向 
};

