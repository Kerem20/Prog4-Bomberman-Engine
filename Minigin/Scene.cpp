#include <algorithm>
#include "Scene.h"

using namespace dae;

void Scene::AddGameObject(std::unique_ptr<GameObject> object)
{
	assert(object != nullptr && "Cannot add a null GameObject to the scene.");
	m_AddBuffer.emplace_back(std::move(object));
}

void Scene::Remove(const GameObject& object)
{
	m_objects.erase(
		std::remove_if(
			m_objects.begin(),
			m_objects.end(),
			[&object](const auto& ptr) { return ptr.get() == &object; }
		),
		m_objects.end()
	);
}

void Scene::RemoveAll()
{
	m_objects.clear();
}

void dae::Scene::FixedUpdate(float fixedDeltaTime)
{
	for (auto& object : m_objects)
	{
		object->FixedUpdate(fixedDeltaTime);
	}
}

void Scene::Update(float deltaTime)
{
	for(auto& object : m_objects)
	{
		object->Update(deltaTime);
	}

	RemoveMarkedForDeletion();
	AddNewObjects();
}

void Scene::Render(float alpha) const
{
	for (const auto& object : m_objects)
	{
		object->Render(alpha);
	}
}

void dae::Scene::RemoveMarkedForDeletion()
{
	// Remove all objects that are flagged
	m_objects.erase(
		std::remove_if(m_objects.begin(), m_objects.end(),
			[](const auto& obj) { return obj->IsMarkedForDeletion(); }),
		m_objects.end()
	);
}

void dae::Scene::AddNewObjects()
{
	// Move all objects from the AddBuffer to the main objects vector
	for (auto& object : m_AddBuffer)
	{
		m_objects.emplace_back(std::move(object));
	}

	m_AddBuffer.clear();
}

