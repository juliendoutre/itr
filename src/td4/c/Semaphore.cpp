#include "itr/Semaphore.hpp"

Semaphore::Semaphore(unsigned int initCount, unsigned int maxCount)
{
    this->counter = initCount;
    this->maxCount = maxCount;
}

void Semaphore::give() {}

void Semaphore::take() {}

bool Semaphore::take(double timeout_ms)
{
    return true;
}
