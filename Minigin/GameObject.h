#pragma once
#include <type_traits>
#include <vector>

#include "Transform.h"
#include "Component.h"
#include <memory>

class GameObject final
{
private:
	std::vector<std::unique_ptr<Component>> m_components{};
public:
	explicit GameObject();
	explicit GameObject(const glm::vec3& position);
	~GameObject() = default;

	GameObject(const GameObject& other) = delete;
	GameObject(GameObject&& other) = delete;
	GameObject& operator=(const GameObject& other) = delete;
	GameObject& operator=(GameObject&& other) = delete;

	dae::Transform m_transform;

	void FixedUpdate();
	void Update();
	void Render();

	template <class T, class... Args>
	T* AddComponent(Args&&... args) {
		static_assert(std::is_base_of_v<Component, T>, "T must inherit from Component");
		auto component = std::make_unique<T>(*this, std::forward<Args>(args)...);
		T* rawPtr = component.get();
		m_components.emplace_back(std::move(component));
		return rawPtr;
	}
};

