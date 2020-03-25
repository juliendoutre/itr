#include "Consumer.hpp"
#include "itr/Semaphore.hpp"

Consumer::Consumer(Semaphore &semaphore) : semaphore(semaphore) {}

void Consumer::run()
{
    this->semaphore.take();
}
