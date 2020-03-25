#include "Producer.hpp"
#include "itr/Semaphore.hpp"

Producer::Producer(Semaphore &semaphore) : semaphore(semaphore) {}

void Producer::run()
{
    this->semaphore.give();
}
