#pragma once

class GameObject;
class Component
{
	// just need refference, no ownership
	GameObject& m_gameObject;

public:
	Component(GameObject& gameObect);
	~Component() = default;

	Component(const Component& other) = delete;
	Component(Component&& other) = delete;
	Component& operator=(const Component& other) = delete;
	Component& operator=(Component&& other) = delete;
};