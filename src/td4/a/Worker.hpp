#pragma once
#include "itr/Thread.hpp"

class Worker : public Thread
{
private:
    unsigned int loops;
    volatile int *counter;

public:
    Worker(unsigned int loops, volatile int *counter);
    void run();
};
