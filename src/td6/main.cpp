/**
 * @file
 * Example of use of the ActiveObject class for @ref td6.
 * @anchor td6_main
 * */

#include "Calculator.hpp"
#include "ActiveCalc.hpp"
#include "CrunchReq.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<double> results;

    Calculator calc = Calculator();
    ActiveCalc activeCalc = ActiveCalc(calc);
    activeCalc.start();

    std::vector<CrunchReq *> requests;
    for (int i = 0; i < 100; i++)
    {
        requests.push_back(activeCalc.async_crunch(i));
    }

    for (auto const &req : requests)
    {
        results.push_back(req->waitReturn());
        delete req;
        requests.pop_back();
    }

    std::cout << results.size() << " results were collected:" << std::endl;
    for (auto const &res : results)
    {
        std::cout << res << std::endl;
    }

    activeCalc.stop();

    return EXIT_SUCCESS;
}
