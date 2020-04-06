/**
 * @file
 * Implementation of the Calibrator class for @ref td3_c.
 * @anchor td3_c_calibrator
 * */

#include "Calibrator.hpp"
#include "Looper.hpp"
#include <vector>
#include <iostream>

Calibrator::Calibrator(double samplingPeriod, unsigned int nSamples)
{
    this->n = nSamples;

    this->start(samplingPeriod);
    this->looper.runLoop();
    this->stop();

    double x = 0;
    double xSum = 0;
    double ySum = 0;
    double xySum = 0;
    double xSquareSum = 0;
    for (unsigned int i = 0; i < samples.size(); i++)
    {
        xSum += x;
        ySum += samples[i];
        xySum += x * samples[i];
        xSquareSum += x * x;

        x += samplingPeriod;
    }

    this->a = (samples.size() * xySum - xSum * ySum) / (samples.size() * xSquareSum - xSum * xSum);
    this->b = (ySum * xSquareSum - xSum * xySum) / (samples.size() * xSquareSum - xSum * xSum);
}

double Calibrator::nLoops(double duration_ms)
{
    return this->a * duration_ms + this->b;
}

void Calibrator::callback()
{
    if (this->samples.size() < this->n)
    {
        this->samples.push_back(this->looper.getSample());
    }
    else
    {
        this->looper.stopLoop();
    }
};
