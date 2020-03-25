#pragma once
#include "itr/Thread.hpp"
#include "itr/Fifo.hpp"
#include "itr/Mutex.hpp"

class Producer : public Thread
{
private:
    unsigned int id;
    int upperBound;
    Fifo<int> &fifo;
    Mutex &printMutex;

protected:
    void run();

public:
    Producer(unsigned int id, int upperBound, Fifo<int> &fifo, Mutex &printMutex);
};
