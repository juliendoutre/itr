/**
 * @file
 * Implementation of the Producer class for @ref td4_c.
 * @anchor td4_c_producer
 * */

#include "Producer.hpp"
#include "itr/Semaphore.hpp"

Producer::Producer(Semaphore &semaphore) : semaphore(semaphore) {}

void Producer::run()
{
    this->semaphore.give();
}
