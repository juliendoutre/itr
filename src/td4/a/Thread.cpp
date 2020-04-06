/**
 * @file
 * - **TD:** @ref td4_a
 * - **Lib implementation:** Thread
 * @anchor lib_thread
 * */

#include "itr/PosixThread.hpp"
#include "itr/Thread.hpp"
#include "itr/time.hpp"
#include <thread>

Thread::Thread() : PosixThread()
{
    this->started = false;
    this->startTime_ = 0;
    this->stopTime_ = 0;
}

Thread::~Thread() {}

void *Thread::call_run(void *v_thread)
{
    Thread *t_thread = (Thread *)v_thread;

    t_thread->startTime_ = timespec_to_ms(timespec_now());
    t_thread->run();
    t_thread->stopTime_ = timespec_to_ms(timespec_now());

    return nullptr;
}

bool Thread::start()
{
    if (!this->started)
    {
        this->started = true;
        this->PosixThread::start(Thread::call_run, this);
    }

    return this->started;
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
