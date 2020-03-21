#pragma once
#include "Timer.hpp"

class PeriodicTimer : public Timer
{
public:
    void start(double duration_ms);
};
