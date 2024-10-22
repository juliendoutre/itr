/**
 * @file
 * - **TD:** @ref td4_d
 * - **Example:** lib's Fifo usage (through Consumer and Producer)
 * @anchor td4_d_main
 * */

#include "itr/Fifo.hpp"
#include "itr/Mutex.hpp"
#include "Producer.hpp"
#include "Consumer.hpp"
#include <vector>
#include <assert.h>

int main()
{
    unsigned int consumersPoolSize = 5;
    unsigned int producersPoolSize = 5;

    Fifo<int> fifo = Fifo<int>();
    Mutex printMutex = Mutex();

    // Initialize the workers pool
    std::vector<Producer> producers;
    for (unsigned int i = 0; i < producersPoolSize; i++)
    {
        producers.push_back(Producer(i, 100, fifo, printMutex));
    }
    std::vector<Consumer> consumers;
    for (unsigned int i = 0; i < consumersPoolSize; i++)
    {
        consumers.push_back(Consumer(i, 100, fifo, printMutex));
    }

    // Start the workers
    for (auto &p : producers)
    {
        p.start();
    }
    for (auto &c : consumers)
    {
        c.start();
    }

    // Wait for all workers to finish their job
    for (auto &p : producers)
    {
        p.join();
    }
    for (auto &c : consumers)
    {
        c.join();
    }

    try
    {
        fifo.pop(100);
        assert(false);
    }
    catch (Fifo<int>::EmptyException e)
    {
        assert(true);
    }

    return 0;
}
