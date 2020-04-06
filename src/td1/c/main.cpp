/**
 * @file
 * - **TD:** @ref td1_d
 * - **Example:** function simple execution time measurement
 * @anchor td1_c_main
 * */

#include <iostream>
#include "itr/time.hpp"

void incr(unsigned int nLoops, double *pCounter)
{
    for (unsigned int i = 0; i < nLoops; i++)
    {
        *pCounter += 1.0;
    }
}

int main(int argc, char *argv[])
{
    unsigned int nLoops = 0;

    if (argc > 1)
    {
        nLoops = atoi(argv[1]);
    }

    double counter = 0.0;

    struct timespec start_ts = timespec_now();
    incr(nLoops, &counter);
    struct timespec end_ts = timespec_now();

    std::cout << "counter value: " << counter << std::endl;
    std::cout << "function execution time: " << end_ts - start_ts << std::endl;

    return EXIT_SUCCESS;
}
