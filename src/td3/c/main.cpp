#include <iostream>
#include "CpuLoop.hpp"

int main()
{
    Calibrator calibrator = Calibrator(10, 100);
    CpuLoop controledLooper = CpuLoop(calibrator);

    controledLooper.runTime(100);

    return EXIT_SUCCESS;
}
