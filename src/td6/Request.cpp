#include "itr/Request.hpp"

void Request::waitReturn()
{
    this->returnSema.take();
}

Request::~Request() {}
