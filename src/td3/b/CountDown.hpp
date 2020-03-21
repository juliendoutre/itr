#pragma once
#include "itr/PeriodicTimer.hpp"

class CountDown : public PeriodicTimer
{
private:
    int counter;

public:
    CountDown(int n);
    void callback();
};
