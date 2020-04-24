#ifndef td6_CrunchReq_hpp_INCLUDED
#define td6_CrunchReq_hpp_INCLUDED

#include "itr/Request.hpp"
#include "Calculator.hpp"

class CrunchReq : public Request
{
private:
    double param, result;
    Calculator &calc;

public:
    CrunchReq(double param, Calculator &calc);
    void execute();
    double waitReturn();
    bool shouldTerminate();
};

#endif
