#pragma once

#include "GameObject.h"
#include "TextComponent.h"
#include "TextObject.h"
#include <Font.h>

class FPSComponent : public TextComponent
{
public:
	explicit FPSComponent(const GameObject& gameobject, const std::shared_ptr<dae::Font> font);
	virtual ~FPSComponent() = default;

	virtual void Update() override;
private:
	float m_previousFPS;
	float m_elapsedMS;

	dae::Clock& m_clock;

	std::string FloatToStringFPS(const float fps);
};
