#include "FPSComponent.h"
#include "ResourceManager.h"
#include <Font.h>
#include "Clock.h"

FPSComponent::FPSComponent(const GameObject& gameobject, const std::shared_ptr<dae::Font> font)
	: Component(gameobject)
	, m_elapsedMS{0}
	, m_clock{ dae::Clock::GetInstance() }
{
	m_previousFPS = static_cast<int>(m_clock.GetFPS());
	std::string fps = std::to_string(m_previousFPS);

	m_fpsCounter = std::make_unique<dae::TextObject>(fps, font);
}

void FPSComponent::Update()
{
	m_elapsedMS += m_clock.GetDeltaTime();

	int newFPS = static_cast<int>(m_clock.GetFPS());

	if (m_elapsedMS >= 0.5) {
		if (newFPS != m_previousFPS)
		{
			m_fpsCounter.get()->SetText(std::to_string(newFPS));
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
