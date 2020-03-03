#include <iostream>
#include <pthread.h>
#include "include/time.hpp"

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

    return NULL;
}

int main(int argc, char *argv[])
{
    volatile unsigned int nLoops = 0;
    unsigned int nTasks = 0;

    if (argc > 1)
    {
        nLoops = atoi(argv[1]);

        if (argc > 2)
        {
            nTasks = atoi(argv[2]);
        }
    }

    volatile double counter = 0.0;
    Data data = Data{nLoops, &counter};
    pthread_t threads[nTasks];

    struct timespec start_ts = timespec_now();

    for (unsigned int i = 0; i < nTasks; i++)
    {
        pthread_create(&threads[i], NULL, call_incr, &data);
    }

    for (unsigned int i = 0; i < nTasks; i++)
    {
        pthread_join(threads[i], NULL);
    }

    struct timespec end_ts = timespec_now();

    std::cout << "counter value: " << counter << std::endl;
    std::cout << "function execution time: " << end_ts - start_ts << std::endl;

    return EXIT_SUCCESS;
}
