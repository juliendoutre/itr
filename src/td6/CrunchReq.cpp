/**
 * @file
 * Implementation of the CrunchReq class for @ref td6.
 * @anchor td6_crunch_req
 * */

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

bool CrunchReq::shouldTerminate()
{
    return false;
}
