/**
 * @file
 * Implementation of the Request class for @ref td6.
 * @anchor lib_request
 * */

#include "itr/Request.hpp"

void Request::waitReturn()
{
    this->returnSema.take();
}

Request::~Request() {}
