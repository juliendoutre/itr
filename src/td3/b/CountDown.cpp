#include "CountDown.hpp"
#include <iostream>

CountDown::CountDown(int n)
{
    counter = n;
}

void CountDown::callback()
{
    this->counter--;
    std::cout << this->counter << std::endl;
}
