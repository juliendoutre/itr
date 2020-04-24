#ifndef td3_b_CountDown_hpp_INCLUDED
#define td3_b_CountDown_hpp_INCLUDED

#include "itr/PeriodicTimer.hpp"

class CountDown : public PeriodicTimer
{
private:
    int counter;

public:
    CountDown(int n);
    void callback();
};

#endif
