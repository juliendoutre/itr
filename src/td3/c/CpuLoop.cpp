/**
 * @file
 * Implementation of the CpuLoop class for @ref td3_c.
 * @anchor td3_c_cpu_loop
 * */

#include "CpuLoop.hpp"

CpuLoop::CpuLoop(Calibrator &calibrator) : calibrator(calibrator) {}

void CpuLoop::runTime(double duration_ms)
{
    this->runLoop(this->calibrator.nLoops(duration_ms));
}
