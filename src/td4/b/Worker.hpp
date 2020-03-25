#pragma once
#include "itr/Thread.hpp"
#include "itr/Mutex.hpp"

class Worker : public Thread
{
private:
    unsigned int loops;
    volatile int *counter;
    Mutex &mutex;

protected:
    void run();

public:
    Worker(unsigned int loops, volatile int *counter, Mutex &mutex);
};
