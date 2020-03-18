#include "Calibrator.hpp"
#include "Looper.hpp"
#include <iostream>

Calibrator::Calibrator(double samplingPeriod, unsigned int nSamples)
{
    this->n = nSamples;
    this->start(samplingPeriod);
    this->looper.runLoop();

    this->stop();

    // TODO use least square fit method instead
    this->a = (this->samples[this->samples.size() - 1] - this->samples[0]) / (nSamples * samplingPeriod);
    this->b = this->samples[0];
}

double Calibrator::nLoops(double duration_ms)
{
    return this->a * duration_ms + this->b;
}

void Calibrator::callback()
{
    this->samples.push_back(this->looper.getSample());

    if (this->samples.size() > this->n)
    {
        this->looper.stopLoop();
    }
};
