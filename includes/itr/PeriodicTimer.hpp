#ifndef PeriodicTimer_hpp_INCLUDED
#define PeriodicTimer_hpp_INCLUDED

#include "Timer.hpp"

class PeriodicTimer : public Timer
{
public:
    void start(double duration_ms);
};

#endif
