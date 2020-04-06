/**
 * @file
 * - **TD:** @ref td6
 * - **Lib implementation:** Request
 * @anchor lib_request
 * */

#include "itr/Request.hpp"

void Request::waitReturn()
{
    this->returnSema.take();
}

Request::~Request() {}
