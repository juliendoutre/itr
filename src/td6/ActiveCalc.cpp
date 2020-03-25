#include "ActiveCalc.hpp"
#include "CrunchReq.hpp"
#include "Calculator.hpp"

ActiveCalc::ActiveCalc(Calculator &calc) : calc(calc) {}

CrunchReq *ActiveCalc::async_crunch(double param)
{
    CrunchReq *req = new CrunchReq(param, this->calc);
    this->reqFifo.push(req);
    return req;
}
