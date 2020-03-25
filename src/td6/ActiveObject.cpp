#include "itr/ActiveObject.hpp"
#include "itr/Request.hpp"

void ActiveObject::run()
{
    while (true)
    {
        Request *req = this->reqFifo.pop();
        req->execute();
    }
}
