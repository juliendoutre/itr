/**
 * @file
 * - **TD:** @ref td4_b
 * - **Example class:** Worker
 * @anchor td4_b_worker
 * */

#include "Worker.hpp"
#include "itr/Mutex.hpp"

Worker::Worker(unsigned int loops, volatile int *counter, Mutex &mutex) : loops(loops), counter(counter), mutex(mutex) {}

void Worker::run()
{
    for (unsigned int j = 0; j < this->loops; j++)
    {
        Mutex::Lock lock = Mutex::Lock(this->mutex);
        *(this->counter) += 1;
    }
}
