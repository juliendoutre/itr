/**
 * @file
 * Implementation of the Looper class for @ref td3_c.
 * @anchor td3_c_looper
 * */

#include "Looper.hpp"
#include <float.h>

double Looper::runLoop(double nLoops)
{
    double counter = 0;
    this->doStop = false;

    while (!this->doStop && this->iLoop < nLoops)
    {
        counter++;
        this->iLoop++;
    }

    return this->iLoop;
}

double Looper::getSample()
{
    return this->iLoop;
}

double Looper::stopLoop()
{
    this->doStop = true;
    return this->iLoop;
}
