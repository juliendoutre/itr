/**
 * @file
 * - **TD:** @ref td4_c
 * - **Example class:** Consumer
 * @anchor td4_c_consumer
 * */

#include "Consumer.hpp"
#include "itr/Semaphore.hpp"

Consumer::Consumer(Semaphore &semaphore) : semaphore(semaphore) {}

void Consumer::run()
{
    this->semaphore.take();
}
