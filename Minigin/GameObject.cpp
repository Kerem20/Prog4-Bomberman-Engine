#include "GameObject.h"

GameObject::GameObject()
	: GameObject(glm::vec3{0,0,0})
{
}

GameObject::GameObject(const glm::vec3& position)
	: m_transform{position}
{
}

void GameObject::FixedUpdate()
{
}

void GameObject::Update()
{
}

void GameObject::Render()
{
}
