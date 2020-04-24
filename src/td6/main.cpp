/**
 * @file
 * - **TD:** @ref td6
 * - **Example:** lib's ActiveObject usage (through ActiveCalc, Calculator, CrunchReq, TerminalReq and Client)
 * @anchor td6_main
 * */

#include "Calculator.hpp"
#include "ActiveCalc.hpp"
#include "CrunchReq.hpp"
#include "Client.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<double> results;

    Calculator calc = Calculator();
    ActiveCalc activeCalc = ActiveCalc(calc);
    activeCalc.start();

    std::vector<Client *> clients;
    for (int i = 0; i < 10; i++)
    {
        clients.push_back(new Client(i, 10 * i, 10 * (i + 1), activeCalc));
    }

    for (auto const &client : clients)
    {
        client->start();
    }

    for (auto const &client : clients)
    {
        std::vector<int> results = client->getResults();
        std::cout << results.size() << " results were collected for client " << client->id << ":" << std::endl;
        for (auto const &res : results)
        {
            std::cout << res << std::endl;
        }

        delete client;
    }

    activeCalc.stop();

    return EXIT_SUCCESS;
}
