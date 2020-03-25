#pragma once
#include "itr/Thread.hpp"
#include "itr/Semaphore.hpp"

class Consumer : public Thread
{
private:
    Semaphore &semaphore;

protected:
    void run();

public:
    Consumer(Semaphore &semaphore);
};
