#include "itr/Thread.hpp"
#include "itr/Fifo.hpp"
#include "Consumer.hpp"
#include <iostream>

Consumer::Consumer(unsigned int id, int queries, Fifo<int> &fifo) : id(id), queries(queries), fifo(fifo) {}

void Consumer::run()
{
    for (int i = 0; i < this->queries; i++)
    {
        this->fifo.pop();
    }

    std::cout << "Consumer " << this->id << " processed " << this->queries << " elements" << std::endl;
}
