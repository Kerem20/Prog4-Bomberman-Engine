#pragma once
#include <chrono>

// Project includes
#include "Singleton.h"

namespace dae
{
    class Clock final : public Singleton<Clock>
    {
    public:
        void Init();

        Clock(const Clock& other) = delete;
        Clock(Clock&& other) = delete;
        Clock& operator=(const Clock& other) = delete;
        Clock& operator=(Clock&& other) = delete;

        void StartFrame();

        float GetDeltaTime() const { return m_DeltaTime; }
        float GetFPS() const { return 1.f / m_DeltaTime; }

    private:
        friend class Singleton<Clock>;
        Clock() = default;

        using clock = std::chrono::high_resolution_clock;

        clock::time_point m_LastTime{};
        clock::time_point m_FrameStart{};

        float m_DeltaTime{};
    };
}