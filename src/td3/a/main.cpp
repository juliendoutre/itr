/**
 * @file
 * Test of the Chrono class for @ref td3_a.
 * @anchor td3_a_main
 * */

#include "itr/Chrono.hpp"
#include "itr/time.hpp"
#include <assert.h>
#include <iostream>

void test_chrono_init()
{
    Chrono ch = Chrono();
    assert(ch.isActive());
    assert(ch.stopTime() == 0);
    ch.stop();
    assert(ch.stopTime() != 0);
    assert(!ch.isActive());
}

void test_chrono_wait()
{
    Chrono ch = Chrono();

    timespec_wait(timespec_from_ms(2000));
    ch.stop();
    std::cout << ch.lap() << std::endl;

    ch.restart();
    timespec_wait(timespec_from_ms(5000));
    std::cout << ch.lap() << std::endl;
    ch.stop();
    std::cout << ch.lap() << std::endl;
}

int main()
{
    test_chrono_init();
    test_chrono_wait();

    return EXIT_SUCCESS;
}
