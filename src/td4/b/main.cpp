#include "itr/Mutex.hpp"
#include "Worker.hpp"
#include <iostream>
#include <vector>

int main()
{
    volatile int counter = 0;
    Mutex mutex = Mutex();

    unsigned int poolSize = 10;

    // Initialize the workers pool
    std::vector<Worker> workers;
    for (unsigned int i = 0; i < poolSize; i++)
    {
        workers.push_back(Worker(1000, &counter, mutex));
    }

    // Start the workers
    for (auto &w : workers)
    {
        w.start();
    }

    // Wait for all workers to finish their job
    for (unsigned int i = 0; i < workers.size(); i++)
    {
        workers[i].join();
        std::cout << "Task " << i << " took " << workers[i].execTime_ms() << " ms" << std::endl;
    }

    std::cout << "Counter value: " << counter << std::endl;

    return EXIT_SUCCESS;
}
