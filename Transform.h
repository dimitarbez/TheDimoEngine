#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

class Transform
{
public:
	Transform(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scale);
	~Transform();

	// 4x4 matrix
	inline glm::mat4 GetModel() const 
	{
		glm::mat4 positionMatrix = glm::translate(m_pos);
		glm::mat4 rotXMatrix = glm::rotate(m_rot.x, glm::vec3(1, 0, 0));
		glm::mat4 rotYMatrix = glm::rotate(m_rot.y, glm::vec3(0, 1, 0));
		glm::mat4 rotZMatrix = glm::rotate(m_rot.z, glm::vec3(0, 0, 1));
		glm::mat4 scaleMatrix = glm::scale(m_scale);

		glm::mat4 rotationMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

		return positionMatrix * rotationMatrix * scaleMatrix;
	}

	inline glm::vec3& GetPosition() { return m_pos; }
	inline glm::vec3& GetRotation() { return m_rot; }
	inline glm::vec3& GetScale() { return m_scale; }

	inline void SetPos(glm::vec3& position) { m_pos = position; }
	inline void SetRot(glm::vec3& rotation) { m_rot = rotation; }
	inline void SetScale(glm::vec3& scale) { m_scale = scale; }
private:
	glm::vec3 m_pos;
	glm::vec3 m_rot;
	glm::vec3 m_scale;
};

