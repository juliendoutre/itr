#include "Calibrator.hpp"

class CpuLoop : public Looper
{
private:
    Calibrator &calibrator;

public:
    CpuLoop(Calibrator &calibrator);
    void runTime(double duration_ms);
};
