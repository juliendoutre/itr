/**
 * @file
 * Test of the CountDown class defined in @ref td3_b.
 * @anchor td3_b_main
 * */

#include "CountDown.hpp"
#include "itr/time.hpp"

int main()
{
    CountDown c = CountDown(10);
    c.start(100);

    timespec remaining_time = timespec_from_ms(1000);
    while (remaining_time > timespec_from_ms(10))
    {
        remaining_time = timespec_wait(remaining_time);
    }

    return 0;
}
