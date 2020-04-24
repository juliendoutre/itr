#ifndef td4_c_Consumer_hpp_INCLUDED
#define td4_c_Consumer_hpp_INCLUDED

#include "itr/Thread.hpp"
#include "itr/Semaphore.hpp"

class Consumer : public Thread
{
private:
    Semaphore &semaphore;

protected:
    void run();

public:
    Consumer(Semaphore &semaphore);
};

#endif
