/**
 * @file
 * - **TD:** @ref td4_c
 * - **Example:** lib's Semaphore usage (through Consumer and Producer)
 * @anchor td4_c_main
 * */

#include "itr/Semaphore.hpp"
#include "Consumer.hpp"
#include "Producer.hpp"
#include <vector>
#include <assert.h>

int main()
{
    unsigned int consumersPoolSize = 10;
    unsigned int producersPoolSize = 10;

    Semaphore semaphore = Semaphore(0, 10);

    // Initialize the workers pool
    std::vector<Producer> producers;
    for (unsigned int i = 0; i < producersPoolSize; i++)
    {
        producers.push_back(Producer(semaphore));
    }
    std::vector<Consumer> consumers;
    for (unsigned int i = 0; i < consumersPoolSize; i++)
    {
        consumers.push_back(Consumer(semaphore));
    }

    // Start the workers
    for (auto &c : consumers)
    {
        c.start();
    }
    for (auto &p : producers)
    {
        p.start();
    }

    // Wait for all workers to finish their job
    for (auto &c : consumers)
    {
        c.join();
    }
    for (auto &p : producers)
    {
        p.join();
    }

    // no token should be available
    assert(!semaphore.take(100));

    return 0;
}
