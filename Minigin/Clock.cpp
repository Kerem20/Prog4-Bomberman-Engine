#include "Clock.h"
#include <thread>

void dae::Clock::Init()
{
	m_LastTime = clock::now();
}

void dae::Clock::StartFrame()
{
    m_FrameStart = clock::now();

    std::chrono::duration<float> elapsed = m_FrameStart - m_LastTime;
    m_DeltaTime = elapsed.count();

    m_LastTime = m_FrameStart;
}
