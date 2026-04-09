#include <algorithm>
#include "Scene.h"
#include <assert.h>

void dae::Scene::FixedUpdate()
{
	for (auto& go : m_gameObjects) {
		go->FixedUpdate();
	}
}

void dae::Scene::Update()
{
	for (auto& go : m_gameObjects) {
		go->Update();
	}
}

void dae::Scene::LateUpdate()
{
	for (auto& go : m_gameObjects) {
		go->LateUpdate();
	}
}

void dae::Scene::Render() const
{
	for (auto& go : m_gameObjects) {
		go->Render();
	}
}

void dae::Scene::AddGameObject(std::unique_ptr<GameObject> gameObject)
{
	if (gameObject == nullptr) return;
	m_gameObjects.emplace_back(std::move(gameObject));
}
