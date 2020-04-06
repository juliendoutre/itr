/**
 * @file
 * Demonstration of the use of a POSIX mutex for @ref td2_c.
 * @anchor td2_c_main
 * */

#include <iostream>
#include <pthread.h>
#include <string.h>
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
    bool protec;
    pthread_mutex_t mutex;
};

void *call_incr(void *v_data)
{
    Data *p_data = (Data *)v_data;

    if (p_data->protec)
    {
        pthread_mutex_lock(&p_data->mutex);
    }

    incr(p_data->nLoops, p_data->pCounter);

    if (p_data->protec)
    {
        pthread_mutex_unlock(&p_data->mutex);
    }

    return nullptr;
}

int main(int argc, char *argv[])
{
    volatile unsigned int nLoops = 0;
    unsigned int nTasks = 0;
    int schedPolicy = 0;
    bool protec = false;

    if (argc > 1)
    {
        nLoops = atoi(argv[1]);

        if (argc > 2)
        {
            nTasks = atoi(argv[2]);

            if (argc > 3)
            {
                schedPolicy = atoi(argv[3]);

                if (argc > 4 && *argv[4] == 'p')
                {
                    protec = true;
                }
            }
        }
    }

    volatile double counter = 0.0;
    Data data;
    data.nLoops = nLoops;
    data.pCounter = &counter;
    data.protec = protec;

    if (protec)
    {
        pthread_mutex_init(&data.mutex, nullptr);
    }

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
    if (protec)
    {
        pthread_mutex_destroy(&data.mutex);
    }

    struct timespec end_ts = timespec_now();

    std::cout << "counter value: " << counter << std::endl;
    std::cout << "function execution time: " << end_ts - start_ts << std::endl;

    return EXIT_SUCCESS;
}
