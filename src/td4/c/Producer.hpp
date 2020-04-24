#ifndef td4_c_Producer_hpp_INCLUDED
#define td4_c_Producer_hpp_INCLUDED

#include "itr/Thread.hpp"
#include "itr/Semaphore.hpp"

class Producer : public Thread
{
private:
    Semaphore &semaphore;

protected:
    void run();

public:
    Producer(Semaphore &semaphore);
};

#endif
