/**
 * @file
 * - **TD:** @ref td3_b
 * - **Example class:** CountDown
 * @anchor td3_b_countdown
 * */

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
