#pragma once
#include "itr/Thread.hpp"

class Looper : public Thread
{
private:
    int n;
    volatile int i;

public:
    Looper(int n);
    void run();
};
