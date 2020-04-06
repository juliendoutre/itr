/**
 * @file
 * - **TD:** @ref td6
 * - **Lib implementation:** ActiveObject
 * @anchor lib_active_object
 * */

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
