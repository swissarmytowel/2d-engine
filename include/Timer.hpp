#pragma once

#include <chrono>
#include "utilities.hpp"

namespace util
{
    class Timer
    {
    public:
        static Timer &instance();
        void reset();

        double getDeltaTime();
        void setTimeScale(double timeScale = 1.0);

        void tick();
    private:
        Timer();
        ~Timer() = default;

        double _timeScale;

        std::chrono::system_clock::time_point _startTime;
        std::chrono::duration<double> _deltaTime;
    };
}