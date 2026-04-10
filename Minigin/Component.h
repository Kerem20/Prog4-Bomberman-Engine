#pragma once

#include <iostream>
#include "Clock.h"

class GameObject;
class Component
{
public:
	explicit Component(const GameObject& gameObject);
	virtual ~Component() = default;

	Component(const Component& other) = delete;
	Component(Component&& other) = delete;
	Component& operator=(const Component& other) = delete;
	Component& operator=(Component&& other) = delete;

	virtual void FixedUpdate() {};
	virtual void Update() {};
	virtual void LateUpdate() {};
	virtual void Render() {};
protected:
	const GameObject& m_gameObject;
private:
};