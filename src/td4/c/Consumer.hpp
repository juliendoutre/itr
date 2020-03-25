#pragma once
#include "itr/Thread.hpp"
#include "itr/Semaphore.hpp"

class Consumer : public Thread
{
private:
    Semaphore &semaphore;

public:
    Consumer(Semaphore &semaphore);
    void run();
};
