/**
 * @file
 * - **TD:** @ref td6
 * - **Example class:** ActiveCalc
 * @anchor td6_active_calc
 * */

#include "ActiveCalc.hpp"
#include "CrunchReq.hpp"
#include "TerminalReq.hpp"
#include "Calculator.hpp"

ActiveCalc::ActiveCalc(Calculator &calc) : calc(calc) {}

CrunchReq *ActiveCalc::async_crunch(double param)
{
    CrunchReq *req = new CrunchReq(param, this->calc);
    this->reqFifo.push(req);
    return req;
}

TerminalReq *ActiveCalc::stop()
{
    TerminalReq *req = new TerminalReq();
    this->reqFifo.push(req);
    return req;
}
