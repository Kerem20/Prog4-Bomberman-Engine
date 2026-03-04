#pragma once
#include <string>
#include <memory>
#include "Transform.h"
#include "Component.h"

namespace dae
{
	class Texture2D;
	class GameObject
	{
		bool m_markedForDeletion{ false };
		Transform m_transform{};
		std::shared_ptr<Texture2D> m_texture{};

		// new refactor
		std::vector <std::unique_ptr<Component>> m_components{};
	public:
		virtual void FixedUpdate(float fixedDeltaTime);
		virtual void Update(float deltaTime);
		virtual void Render(float alpha) const;

		// new refactor
		template<class T>
		T& AddComponent(T);
		void DeleteComponent(const Component& component);

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		bool IsMarkedForDeletion() const { return m_markedForDeletion; }
		void MarkForDeletion();

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;
	};

	template<class T>
	inline T& GameObject::AddComponent(T)
	{
		if (std::is_base_of_v<Component, T>) return;

		auto component = new T(this);
		m_components.emplace_back(std::move(component));
		return component;
	}
}
