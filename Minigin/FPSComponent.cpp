#include "FPSComponent.h"
#include "ResourceManager.h"
#include <Font.h>
#include "Clock.h"

#include <sstream>
#include <iomanip>

FPSComponent::FPSComponent(const GameObject& gameobject, const std::shared_ptr<dae::Font> font)
	: Component(gameobject)
	, m_elapsedMS{0}
	, m_clock{ dae::Clock::GetInstance() }
{
	m_previousFPS = m_clock.GetFPS();

	std::string fps = FloatToStringFPS(m_previousFPS);
	m_fpsCounter = std::make_unique<dae::TextObject>(fps, font);
}

void FPSComponent::Update()
{
	m_elapsedMS += m_clock.GetDeltaTime();

	float newFPS = m_clock.GetFPS();

	if (m_elapsedMS >= 0.5) {
		if (newFPS != m_previousFPS)
		{
			m_fpsCounter.get()->SetText(FloatToStringFPS(newFPS));
			m_previousFPS = newFPS;
		}

		m_elapsedMS = 0;
	}

	m_fpsCounter.get()->Update();
}

void FPSComponent::Render()
{
	m_fpsCounter.get()->Render();
}

std::string FPSComponent::FloatToStringFPS(const float fps)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) << fps;
	return oss.str();
}
