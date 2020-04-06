/**
 * @file
 * - **TD:** @ref td1_a
 * - **Example:** lib's time utils functions tests
 * @anchor td1_a_main
 * */

#include "itr/time.hpp"
#include <assert.h>
#include <iostream>

void test_timespec_to_ms()
{
    struct timespec t1;
    t1.tv_sec = 20;
    t1.tv_nsec = 1'546'237;

    assert(timespec_to_ms(t1) == 20'001.546237);

    struct timespec t2;
    t2.tv_sec = -20;
    t2.tv_nsec = 1'546'237;

    assert(timespec_to_ms(t2) == -19'998.453763);
}

void test_timespec_from_ms()
{
    double t1 = 20'001.546237;
    struct timespec expected_t1;
    expected_t1.tv_sec = 20;
    expected_t1.tv_nsec = 1'546'237;

    assert(timespec_from_ms(t1) == expected_t1);

    double t2 = -19'998.453763;
    struct timespec expected_t2;
    expected_t2.tv_sec = -20;
    expected_t2.tv_nsec = 1'546'237;

    assert(timespec_from_ms(t2) == expected_t2);
}

void test_timespec_now()
{
    struct timespec t1 = timespec_now();
    struct timespec t2 = timespec_now();
    assert(t1 < t2);
    assert(t2 > t1);
}

void test_timespec_negate()
{
    struct timespec t1;
    t1.tv_sec = 19;
    t1.tv_nsec = 0;

    struct timespec expected_t;
    expected_t.tv_sec = -19;
    expected_t.tv_nsec = 0;

    assert(timespec_negate(t1) == expected_t);
}

void test_timespec_add()
{
    struct timespec t1;
    t1.tv_sec = 20;
    t1.tv_nsec = 0;

    struct timespec t2;
    t2.tv_sec = -20;
    t2.tv_nsec = 0;

    struct timespec expected_t;
    expected_t.tv_sec = 0;
    expected_t.tv_nsec = 0;

    assert(t1 + t2 == expected_t);
    assert(t2 + t1 == expected_t);
}

void test_timespec_substract()
{
    struct timespec t1;
    t1.tv_sec = 20;

    struct timespec t2;
    t2.tv_sec = 20;

    struct timespec expected_t;
    expected_t.tv_sec = 0;
    expected_t.tv_nsec = 0;

    assert(t1 - t2 == expected_t);
    assert(t2 - t1 == expected_t);
}

int main()
{
    test_timespec_to_ms();
    test_timespec_from_ms();
    test_timespec_now();
    test_timespec_negate();
    test_timespec_add();
    test_timespec_substract();

    return EXIT_SUCCESS;
}
