/**
 * @file
 * - **TD:** @ref td4_d
 * - **Example class:** Consumer
 * @anchor td4_d_consumer
 * */

#include "itr/Fifo.hpp"
#include "itr/Mutex.hpp"
#include "Consumer.hpp"
#include <iostream>

Consumer::Consumer(unsigned int id, int queries, Fifo<int> &fifo, Mutex &printMutex) : id(id), queries(queries), fifo(fifo), printMutex(printMutex) {}

void Consumer::run()
{
    for (int i = 0; i < this->queries; i++)
    {
        this->fifo.pop();
    }

    Mutex::Lock(this->printMutex);
    std::cout << "Consumer " << this->id << " processed " << this->queries << " elements" << std::endl;
}
