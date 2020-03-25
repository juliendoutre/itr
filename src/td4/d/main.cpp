#include "itr/Fifo.hpp"
#include "Producer.hpp"
#include "Consumer.hpp"
#include <vector>

int main()
{
    unsigned int consumersPoolSize = 10;
    unsigned int producersPoolSize = 10;

    Fifo<int> fifo = Fifo<int>();

    // Initialize the workers pool
    std::vector<Producer> producers;
    for (unsigned int i = 0; i < producersPoolSize; i++)
    {
        producers.push_back(Producer(i, 100, fifo));
    }
    std::vector<Consumer> consumers;
    for (unsigned int i = 0; i < consumersPoolSize; i++)
    {
        consumers.push_back(Consumer(i, 100, fifo));
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

    return 0;
}
