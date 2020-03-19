#include "Looper.hpp"
#include <iostream>

Looper::Looper(int n) : n(n), i(0) {}

void Looper::run()
{
    for (int j = 0; j < this->n; j++)
    {
        this->i += 1;
        std::cout << this->i << std::endl;
    }
}
