#include "include/Thread.hpp"
#include "include/time.hpp"
#include <thread>

void *Thread::call_run(void *v_thread)
{
    Thread *t_thread = (Thread *)v_thread;

    t_thread->startTime_ = timespec_to_ms(timespec_now());
    t_thread->run();
    t_thread->stopTime_ = timespec_to_ms(timespec_now());

    return nullptr;
}

void Thread::start()
{
    this->PosixThread::start(Thread::call_run, this);
}

void Thread::sleep_ms(double delay_ms)
{
    timespec_wait(timespec_from_ms(delay_ms));
}

double Thread::startTime_ms()
{
    return this->startTime_;
}

double Thread::stopTime_ms()
{
    return this->stopTime_;
}

double Thread::execTime_ms()
{
    if (this->stopTime_ > this->startTime_)
    {
        return this->stopTime_ - this->startTime_;
    }
    else
    {
        return timespec_to_ms(timespec_now()) - this->startTime_;
    }
}
