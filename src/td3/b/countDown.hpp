#include "include/timer.hpp"

class CountDown : public PeriodicTimer
{
private:
    int counter;

public:
    CountDown(int n);
    void callback();
};
