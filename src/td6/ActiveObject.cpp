#include "itr/ActiveObject.hpp"
#include "itr/Request.hpp"

void ActiveObject::run()
{
    while (true)
    {
        Request *req = this->reqFifo.pop();
        if (!req->shouldTerminate())
        {
            req->execute();
        }
        else
        {
            break;
        }
    }
}
