#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
public:
	// fov �ӽǵ����� ����
	// aspect �ݺ��
	// 
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar) {
		this->pos = pos;
		this->forword = glm::vec3(0.0f, 0.0f, 1.0f);
		this->up = glm::vec3(0.0f, 1.0f, 1.0f);
		this->projection = glm::perspective(fov, aspect, zNear, zFar);

	}

	inline glm::mat4 GetViewProjection() const {
		return projection * glm::lookAt(pos, pos + forword, up); // ������������
	}

private:
	glm::mat4 projection;	// ͸��ͶӰ����
	glm::vec3 pos;			// �������λ��
	glm::vec3 forword;		// ��ǰ�� �ӽǵķ��� ǰ�� 
	glm::vec3 up;			// ���Ϸ� �ӽǵķ��� 
};

