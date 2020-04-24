#ifndef td4_d_Consumer_hpp_INCLUDED
#define td4_d_Consumer_hpp_INCLUDED

#include "itr/Thread.hpp"
#include "itr/Fifo.hpp"
#include "itr/Mutex.hpp"

class Consumer : public Thread
{
private:
    unsigned int id;
    int queries;
    Fifo<int> &fifo;
    Mutex &printMutex;

protected:
    void run();

public:
    Consumer(unsigned int id, int queries, Fifo<int> &fifo, Mutex &printMutex);
};

#endif
