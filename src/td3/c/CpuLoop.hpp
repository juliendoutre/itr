#ifndef td3_c_CpuLoop_hpp_INCLUDED
#define td3_c_CpuLoop_hpp_INCLUDED

#include "Calibrator.hpp"
#include "Looper.hpp"

class CpuLoop : public Looper
{
private:
    Calibrator &calibrator;

public:
    CpuLoop(Calibrator &calibrator);
    void runTime(double duration_ms);
};

#endif
