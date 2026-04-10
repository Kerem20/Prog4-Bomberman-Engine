#include "RenderComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "GameObject.h"

RenderComponent::RenderComponent(const GameObject& gameObject, const std::string& filepath)
	: Component(gameObject)
	, m_texture{ dae::ResourceManager::GetInstance().LoadTexture(filepath) }
{
}

void RenderComponent::Render()
{
	glm::vec3 pos = m_gameObject.m_transform.GetPosition();
	dae::Renderer::GetInstance().RenderTexture(*m_texture.get(), pos.x, pos.y);
}
