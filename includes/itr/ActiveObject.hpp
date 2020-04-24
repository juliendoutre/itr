#ifndef ActiveObject_hpp_INCLUDED
#define ActiveObject_hpp_INCLUDED

#include "Thread.hpp"
#include "Fifo.hpp"
#include "Request.hpp"

class ActiveObject : public Thread
{
protected:
    Fifo<Request *> reqFifo;

protected:
    void run();
};

#endif
