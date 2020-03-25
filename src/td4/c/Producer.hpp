#pragma once
#include "itr/Thread.hpp"
#include "itr/Semaphore.hpp"

class Producer : public Thread
{
private:
    Semaphore &semaphore;

public:
    Producer(Semaphore &semaphore);
    void run();
};
