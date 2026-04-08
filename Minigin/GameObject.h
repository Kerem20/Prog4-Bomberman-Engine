#pragma once
#include "Transform.h"

class GameObject final
{
public:
	GameObject(const glm::vec3& position);
	virtual ~GameObject() = default;
protected:
	dae::Transform m_transform;
private:
};
