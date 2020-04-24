#ifndef td6_TerminalReq_hpp_INCLUDED
#define td6_TerminalReq_hpp_INCLUDED

#include "itr/Request.hpp"

class TerminalReq : public Request
{
public:
    void execute();
    bool shouldTerminate();
};

#endif
