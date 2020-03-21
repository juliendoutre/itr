#pragma once
#include <time.h>
#include <signal.h>

class Timer
{
private:
    static void call_callback(int, siginfo_t *, void *);

protected:
    timer_t tid;
    virtual void callback() = 0;

public:
    Timer();
    ~Timer();
    void start(double duration_ms);
    void stop();
};
