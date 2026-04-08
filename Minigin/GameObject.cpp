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
	for (auto& com : m_components) {
		com->FixedUpdate();
	}
}

void GameObject::Update()
{
	for (auto& com : m_components) {
		com->Update();
	}
}

void GameObject::Render()
{
	for (auto& com : m_components) {
		com->Render();
	}
}
