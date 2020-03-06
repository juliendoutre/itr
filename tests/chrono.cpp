#include "include/chrono.hpp"
#include <assert.h>
#include <iostream>

void test_chrono_init()
{
    Chrono ch = Chrono();
    assert(ch.isActive());
    ch.stop();
    assert(!ch.isActive());
}

int main()
{
    test_chrono_init();

    return EXIT_SUCCESS;
}
