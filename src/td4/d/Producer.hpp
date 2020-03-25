#pragma once
#include "itr/Thread.hpp"
#include "itr/Fifo.hpp"

class Producer : public Thread
{
private:
    unsigned int id;
    int upperBound;
    Fifo<int> &fifo;

public:
    Producer(unsigned int id, int upperBound, Fifo<int> &fifo);
    void run();
};
