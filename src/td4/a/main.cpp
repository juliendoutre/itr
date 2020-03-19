#include "Looper.hpp"
#include <iostream>

int main()
{
    Looper looper = Looper(1000);

    looper.start();
    looper.sleep_ms(1000);

    std::cout << looper.stopTime_ms() - looper.startTime_ms() << std::endl;
    std::cout << looper.execTime_ms() << std::endl;

    return EXIT_SUCCESS;
}
