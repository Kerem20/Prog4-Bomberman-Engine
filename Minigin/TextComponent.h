#pragma once

#include "Component.h"
#include "GameObject.h"
#include "Font.h"
#include "TextObject.h"

class TextComponent : public Component
{
public:
	explicit TextComponent(const GameObject& gameobject, const std::string& text, const std::shared_ptr<dae::Font> font);
	virtual ~TextComponent() = default;
	
	virtual void Update() override;
	virtual void Render() override;
protected:
	std::unique_ptr<dae::TextObject> m_textObject;
};
