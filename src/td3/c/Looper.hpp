#pragma once
#include "float.h"

class Looper
{
private:
    volatile bool doStop;
    volatile double iLoop;

public:
    double runLoop(double nLoops = DBL_MAX);
    double getSample();
    double stopLoop();
};
