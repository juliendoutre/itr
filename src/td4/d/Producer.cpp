#include "itr/Thread.hpp"
#include "itr/Fifo.hpp"
#include "Producer.hpp"
#include <iostream>

Producer::Producer(unsigned int id, int upperBound, Fifo<int> &fifo) : id(id), upperBound(upperBound), fifo(fifo) {}

void Producer::run()
{
    for (int i = 0; i < this->upperBound; i++)
    {
        this->fifo.push(i);
    }

    std::cout << "Producer " << this->id << " finished to load " << this->upperBound << " elements" << std::endl;
}
