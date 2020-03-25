#include "ActiveCalc.hpp"
#include "CrunchReq.hpp"

CrunchReq *ActiveCalc::async_crunch(double param)
{
    CrunchReq *req = new CrunchReq(param);
    this->requestFifo.push(req);
    return req;
}
