#pragma once
#include "PosixThread.hpp"

class Thread : public PosixThread
{
private:
    static void *call_run(void *v_thread);
    double startTime_;
    double stopTime_;

protected:
    virtual void run() = 0;

public:
    void start();
    void sleep_ms(double delay_ms);
    double startTime_ms();
    double stopTime_ms();
    double execTime_ms();
};
