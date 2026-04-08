#pragma once
#include "Transform.h"

class GameObject final
{
public:
	explicit GameObject();
	explicit GameObject(const glm::vec3& position);
	~GameObject() = default;

	GameObject(const GameObject& other) = delete;
	GameObject(GameObject&& other) = delete;
	GameObject& operator=(const GameObject& other) = delete;
	GameObject& operator=(GameObject&& other) = delete;

	void FixedUpdate();
	void Update();
	void Render();

protected:
	dae::Transform m_transform;
private:
};
