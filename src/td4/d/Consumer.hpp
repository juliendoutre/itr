#pragma once
#include "itr/Thread.hpp"
#include "itr/Fifo.hpp"

class Consumer : public Thread
{
private:
    unsigned int id;
    int queries;
    Fifo<int> &fifo;

public:
    Consumer(unsigned int id, int queries, Fifo<int> &fifo);
    void run();
};
