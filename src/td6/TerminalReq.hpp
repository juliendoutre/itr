#pragma once
#include "itr/Request.hpp"

class TerminalReq : public Request
{
public:
    void execute();
    bool shouldTerminate();
};
