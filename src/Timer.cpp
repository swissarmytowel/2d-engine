#include "../include/Timer.hpp"

util::Timer::Timer()
{
    reset();
    setTimeScale();
    _deltaTime = std::chrono::duration<double>(0.0);
}

util::Timer &util::Timer::instance()
{
    static Timer timer;
    return reinterpret_cast<Timer &>(timer);
}

void util::Timer::reset()
{
    _startTime = std::chrono::system_clock::now();
}

double util::Timer::getDeltaTime()
{
    return _deltaTime.count();
}

void util::Timer::setTimeScale(double timeScale)
{
    _timeScale = timeScale;
}

void util::Timer::tick()
{
    _deltaTime = std::chrono::system_clock::now() - _startTime;
}
