/**
 * @file
 * - **TD:** @ref td4_c
 * - **Example class:** Producer
 * @anchor td4_c_producer
 * */

#include "Producer.hpp"
#include "itr/Semaphore.hpp"

Producer::Producer(Semaphore &semaphore) : semaphore(semaphore) {}

void Producer::run()
{
    this->semaphore.give();
}
