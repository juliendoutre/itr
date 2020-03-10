#include "CountDown.hpp"
#include <chrono>
#include <thread>

int main()
{
    CountDown c = CountDown(10);
    c.start(100);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    return 0;
}
