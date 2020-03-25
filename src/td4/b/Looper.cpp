#include "Looper.hpp"

Looper::Looper(int n) : n(n), i(0) {}

void Looper::run()
{
    for (int j = 0; j < this->n; j++)
    {
        this->i += 1;
    }
}
