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

    for (auto const &r : requests)
    {
        results.push_back(r->waitReturn());
    }

    std::cout << results.size() << std::endl;
    for (auto const &r : results)
    {
        std::cout << r << std::endl;
    }

    return EXIT_SUCCESS;
}
