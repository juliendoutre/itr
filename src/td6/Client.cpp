/**
 * @file
 * - **TD:** @ref td6
 * - **Example class:** Client
 * @anchor td6_client
 * */

#include "Client.hpp"
#include "ActiveCalc.hpp"
#include <vector>

Client::Client(unsigned int id, int minBound, int maxBound, ActiveCalc &calc) : id(id), min(minBound), max(maxBound), calc(calc) {}

Client::~Client() {}

void Client::run()
{
    for (int i = this->min; i < this->max; i++)
    {
        this->requests.push_back(this->calc.async_crunch(i));
    }
}

std::vector<int> Client::getResults()
{
    std::vector<int> results;

    for (auto const &req : this->requests)
    {
        results.push_back(req->waitReturn());
        this->requests.pop_back();
        delete req;
    }

    return results;
}
