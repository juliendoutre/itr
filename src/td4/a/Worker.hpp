#ifndef td4_a_Worker_hpp_INCLUDED
#define td4_a_Worker_hpp_INCLUDED

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

#endif
