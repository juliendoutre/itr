#pragma once
#include "itr/ActiveObject"
#include "CrunchReq.hpp"

class ActiveCalc : public ActiveObject
{
public:
    CrunchReq *async_crunch(double param);
};
