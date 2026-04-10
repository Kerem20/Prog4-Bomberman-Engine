#include "FPSComponent.h"
#include "ResourceManager.h"
#include <Font.h>
#include "Clock.h"

#include <sstream>
#include <iomanip>

FPSComponent::FPSComponent(const GameObject& gameobject, const std::shared_ptr<dae::Font> font)
	: TextComponent(gameobject, "", font)
	, m_elapsedMS{ 0 }
	, m_clock{ dae::Clock::GetInstance() }
{
	m_previousFPS = m_clock.GetFPS();

	std::string fps = FloatToStringFPS(m_previousFPS);
	m_textObject->SetText(fps);
}

void FPSComponent::Update()
{
	m_elapsedMS += m_clock.GetDeltaTime();

	float newFPS = m_clock.GetFPS();

	if (m_elapsedMS >= 0.5) {
		if (newFPS != m_previousFPS)
		{
			m_textObject->SetText(FloatToStringFPS(newFPS) + " FPS");
			m_previousFPS = newFPS;
		}

		m_elapsedMS = 0;
	}

	m_textObject->Update();
}

std::string FPSComponent::FloatToStringFPS(const float fps)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) << fps;
	return oss.str();
}
