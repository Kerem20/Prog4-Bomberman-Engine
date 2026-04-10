#include "TextComponent.h"

TextComponent::TextComponent(const GameObject& gameobject, const std::string& text, const std::shared_ptr<dae::Font> font)
	: Component(gameobject)
{
	m_textObject = std::make_unique<dae::TextObject>(text, font);
}

void TextComponent::Update()
{
	m_textObject->Update();
}

void TextComponent::Render()
{
	m_textObject->Render();
}