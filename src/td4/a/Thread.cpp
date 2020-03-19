#include "include/Thread.hpp"
#include <thread>

void *Thread::call_run(void *v_thread)
{
    Thread *t_thread = (Thread *)v_thread;
    t_thread->run();
}

void Thread::start()
{
    this->PosixThread::start(Thread::call_run, this);
}

void Thread::sleep_ms(double delay_ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

double Thread::startTime_ms()
{
    return 0;
}

double Thread::stopTime_ms()
{
    return 0;
}

double Thread::execTime_ms()
{
    return 0;
}
