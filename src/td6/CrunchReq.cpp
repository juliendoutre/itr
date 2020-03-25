#include "CrunchReq.hpp"
#include "Calculator.hpp"

CrunchReq::CrunchReq(double param, Calculator &calc) : param(param), calc(calc) {}

void CrunchReq::execute()
{
    this->result = this->calc.crunch(this->param);
    this->returnSema.give();
}

double CrunchReq::waitReturn()
{
    this->returnSema.take();
    return this->result;
}
