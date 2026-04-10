#pragma once
#include "Component.h"
#include "Texture2D.h"

class RenderComponent : public Component
{
public:
	explicit RenderComponent(const GameObject& gameObject, const std::string& filepath);
	virtual ~RenderComponent() = default;

	virtual void Render() override;
private:
	std::shared_ptr<dae::Texture2D> m_texture;
};
