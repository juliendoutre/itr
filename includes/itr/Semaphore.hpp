#ifndef Semaphore_hpp_INCLUDED
#define Semaphore_hpp_INCLUDED

#include <limits.h>
#include "Mutex.hpp"

class Semaphore
{
private:
    unsigned int counter;
    unsigned int maxCount;
    Mutex mutex;

public:
    Semaphore(unsigned int initCount = 0, unsigned int maxCount = UINT_MAX);
    void give();
    void take();
    bool take(double timeout_ms);
};

#endif
