#include "Transform.h"



Transform::Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f,1.0f,1.0f))
	:m_pos(pos),
	m_rot(rot),
	m_scale(scale)
{
}


Transform::~Transform()
{
}
