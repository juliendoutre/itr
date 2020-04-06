/**
 * @file
 * Implementation of the Worker class for @ref td4_a.
 * @anchor td4_a_worker
 * */

#include "Worker.hpp"

Worker::Worker(unsigned int loops, volatile int *counter) : loops(loops), counter(counter) {}

void Worker::run()
{
    for (unsigned int j = 0; j < this->loops; j++)
    {
        *(this->counter) += 1;
    }
}
