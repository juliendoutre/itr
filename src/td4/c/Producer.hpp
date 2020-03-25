#pragma once
#include "itr/Thread.hpp"
#include "itr/Semaphore.hpp"

class Producer : public Thread
{
private:
    Semaphore &semaphore;

protected:
    void run();

public:
    Producer(Semaphore &semaphore);
};
