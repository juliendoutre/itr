#include "CpuLoop.hpp"

CpuLoop::CpuLoop(Calibrator &calibrator) : calibrator(calibrator)
{
}

void CpuLoop::runTime(double duration_ms)
{
    this->runLoop(this->calibrator.nLoops(duration_ms));
}
