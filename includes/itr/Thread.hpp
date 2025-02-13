#ifndef Thread_hpp_INCLUDED
#define Thread_hpp_INCLUDED

#include "PosixThread.hpp"

class Thread : public PosixThread
{
private:
    static void *call_run(void *v_thread);
    double startTime_;
    double stopTime_;
    bool started;

protected:
    virtual void run() = 0;

public:
    Thread();
    virtual ~Thread();
    bool start();
    void sleep_ms(double delay_ms);
    double startTime_ms();
    double stopTime_ms();
    double execTime_ms();
};

#endif
