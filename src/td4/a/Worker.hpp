#pragma once
#include "itr/Thread.hpp"

class Worker : public Thread
{
private:
    unsigned int loops;
    volatile int *counter;

protected:
    void run();

public:
    Worker(unsigned int loops, volatile int *counter);
};
