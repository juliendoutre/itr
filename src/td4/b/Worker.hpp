#ifndef td4_b_Worker_hpp_INCLUDED
#define td4_b_Worker_hpp_INCLUDED

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

#endif
