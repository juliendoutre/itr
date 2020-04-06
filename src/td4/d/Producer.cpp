/**
 * @file
 * - **TD:** @ref td4_d
 * - **Example class:** Producer
 * @anchor td4_d_producer
 * */

#include "itr/Fifo.hpp"
#include "itr/Mutex.hpp"
#include "Producer.hpp"
#include <iostream>

Producer::Producer(unsigned int id, int upperBound, Fifo<int> &fifo, Mutex &printMutex) : id(id), upperBound(upperBound), fifo(fifo), printMutex(printMutex) {}

void Producer::run()
{
    for (int i = 0; i < this->upperBound; i++)
    {
        this->fifo.push(i);
    }

    Mutex::Lock(this->printMutex);
    std::cout << "Producer " << this->id << " finished to load " << this->upperBound << " elements" << std::endl;
}
