#include "Clock.h"
#include <thread>

dae::Clock::Clock(double targetFPS)
    : m_TargetFrameTime(1.0 / targetFPS)
{
    m_LastTime = clock::now();
}

void dae::Clock::StartFrame()
{
    m_FrameStart = clock::now();

    std::chrono::duration<double> elapsed = m_FrameStart - m_LastTime;
    m_DeltaTime = elapsed.count();

    // Prevent spiral of death
    if (m_DeltaTime > 0.25)
        m_DeltaTime = 0.25;

    m_LastTime = m_FrameStart;

    m_FPS = 1.0 / m_DeltaTime;
}

void dae::Clock::EndFrame() const
{
    auto frameEnd = clock::now();
    std::chrono::duration<double> frameDuration = frameEnd - m_FrameStart;

    double sleepTime = m_TargetFrameTime - frameDuration.count();

    if (sleepTime > 0.0)
    {
        std::this_thread::sleep_for(std::chrono::duration<double>(sleepTime));
    }
}

void dae::Clock::SetTargetFPS(double targetFPS)
{
	m_TargetFrameTime = 1.0 / targetFPS;
}
