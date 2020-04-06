/**
 * @file
 * - **TD:** @ref td2_c
 * - **Example:** function execution time calibration using lib's Timer
 * @anchor td2_c_main
 * */

#include "CpuLoop.hpp"
#include "Calibrator.hpp"

int main()
{
    Calibrator calibrator = Calibrator(10, 100);
    CpuLoop controledLooper = CpuLoop(calibrator);

    controledLooper.runTime(100);

    return 0;
}
