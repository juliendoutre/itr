#pragma once
#include "include/PeriodicTimer.hpp"
#include "Looper.hpp"
#include <vector>

class Calibrator : public PeriodicTimer
{
private:
    double a, b;
    unsigned int n;
    Looper looper;
    std::vector<double> samples;

protected:
    void callback();

public:
    Calibrator(double samplingPeriod, unsigned int nSamples);
    double nLoops(double duration_ms);
};
