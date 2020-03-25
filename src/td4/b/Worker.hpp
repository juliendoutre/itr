#pragma once
#include "itr/Thread.hpp"
#include "itr/Mutex.hpp"

class Worker : public Thread
{
private:
    unsigned int loops;
    volatile int *counter;
    Mutex &mutex;

public:
    Worker(unsigned int loops, volatile int *counter, Mutex &mutex);
    void run();
};
