/**
 * @file
 * - **TD:** @ref td2_b
 * - **Example:** multi-theaded computation execution time measurement
 * @anchor td2_b_main
 * */

#include <iostream>
#include <pthread.h>
#include "itr/time.hpp"

void incr(unsigned int nLoops, volatile double *pCounter)
{
    for (unsigned int i = 0; i < nLoops; i++)
    {
        *pCounter += 1.0;
    }
}

struct Data
{
    volatile unsigned int nLoops;
    volatile double *pCounter;
};

void *call_incr(void *v_data)
{
    Data *p_data = (Data *)v_data;
    incr(p_data->nLoops, p_data->pCounter);

    return nullptr;
}

int main(int argc, char *argv[])
{
    volatile unsigned int nLoops = 0;
    unsigned int nTasks = 0;
    int schedPolicy = 0;

    if (argc > 1)
    {
        nLoops = atoi(argv[1]);

        if (argc > 2)
        {
            nTasks = atoi(argv[2]);

            if (argc > 3)
            {
                schedPolicy = atoi(argv[3]);
            }
        }
    }

    volatile double counter = 0.0;
    Data data = Data{nLoops, &counter};
    pthread_t threads[nTasks];

    sched_param mainSchedParams;
    if (schedPolicy > 0)
    {
        mainSchedParams.sched_priority = sched_get_priority_max(schedPolicy);
    }
    else
    {
        mainSchedParams.sched_priority = 0;
    }
    pthread_setschedparam(pthread_self(), schedPolicy, &mainSchedParams);

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, schedPolicy);
    sched_param schedParams;
    schedParams.sched_priority = 10;
    pthread_attr_setschedparam(&attr, &schedParams);

    struct timespec start_ts = timespec_now();

    for (unsigned int i = 0; i < nTasks; i++)
    {
        pthread_create(&threads[i], &attr, call_incr, &data);
    }

    for (unsigned int i = 0; i < nTasks; i++)
    {
        pthread_join(threads[i], nullptr);
    }

    pthread_attr_destroy(&attr);

    struct timespec end_ts = timespec_now();
    std::cout << nLoops << "," << nTasks << "," << (end_ts - start_ts).tv_nsec << std::endl;

    return EXIT_SUCCESS;
}
