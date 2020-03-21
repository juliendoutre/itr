#pragma once
#include <time.h>

class Chrono
{
private:
    timespec startTime_;
    timespec stopTime_;

public:
    Chrono();
    void stop();
    void restart();
    bool isActive();
    double startTime();
    double stopTime();
    double lap();
};
