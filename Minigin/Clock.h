#pragma once
#include <chrono>

// Project includes
#include "Singleton.h"

namespace dae
{
    class Clock final : public Singleton<Clock>
    {
    public:
        Clock(double targetFPS = 60.0);

        void StartFrame();
        void EndFrame() const;

        double GetDeltaTime() const { return m_DeltaTime; }
        double GetFPS() const { return m_FPS; }

		void SetTargetFPS(double targetFPS);

    private:
        using clock = std::chrono::high_resolution_clock;

        clock::time_point m_LastTime{};
        clock::time_point m_FrameStart{};

        double m_DeltaTime{};
        double m_TargetFrameTime{};
        double m_FPS{};
    };
}