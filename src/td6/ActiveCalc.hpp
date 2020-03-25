#pragma once
#include "itr/ActiveObject.hpp"
#include "CrunchReq.hpp"
#include "Calculator.hpp"

class ActiveCalc : public ActiveObject
{
private:
    Calculator &calc;

public:
    ActiveCalc(Calculator &calc);
    CrunchReq *async_crunch(double param);
};
