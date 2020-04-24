#ifndef Request_hpp_INCLUDED
#define Request_hpp_INCLUDED

#include "Semaphore.hpp"

class Request
{
protected:
    Semaphore returnSema;

public:
    virtual void execute() = 0;
    virtual bool shouldTerminate() = 0;
    void waitReturn();
    virtual ~Request();
};

#endif
