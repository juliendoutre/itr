/**
 * @file
 * Implementation of the Semaphore class for @ref td4_c.
 * @anchor lib_semaphore
 * */

#include "itr/Semaphore.hpp"
#include "itr/Mutex.hpp"

Semaphore::Semaphore(unsigned int initCount, unsigned int maxCount) : counter(initCount), maxCount(maxCount)
{
    this->mutex = Mutex();
}

void Semaphore::take()
{
    Mutex::Lock lock = Mutex::Lock(this->mutex);
    while (this->counter == 0)
    {
        lock.wait();
    }

    this->counter -= 1;
}

bool Semaphore::take(double timeout_ms)
{
    try
    {
        Mutex::Lock lock = Mutex::Lock(this->mutex, timeout_ms);

        if (!lock.wait(timeout_ms) || this->counter == 0)
        {
            return false;
        }

        this->counter -= 1;

        return true;
    }
    catch (const Mutex::Monitor::TimeoutException e)
    {
        return false;
    }
}

void Semaphore::give()
{
    if (this->counter < this->maxCount - 1)
    {
        Mutex::Lock lock = Mutex::Lock(this->mutex);
        this->counter += 1;
        lock.notify();
    }
}
