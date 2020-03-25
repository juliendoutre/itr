#pragma once
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
