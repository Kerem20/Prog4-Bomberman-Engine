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

void GameObject::LateUpdate()
{
	if (m_componentsToRemove.empty()) return;
	FlushRemovals();
}

void GameObject::Render()
{
	for (auto& com : m_components) {
		com->Render();
	}
}

void GameObject::FlushRemovals()
{
	m_components.erase(
		std::remove_if(m_components.begin(), m_components.end(),
			[&](const std::unique_ptr<Component>& comp) {
				return std::find(
					m_componentsToRemove.begin(),
					m_componentsToRemove.end(),
					comp.get()
				) != m_componentsToRemove.end();
			}),
		m_components.end()
	);
	m_componentsToRemove.clear();
}
