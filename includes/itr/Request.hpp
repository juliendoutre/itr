#pragma once
#include "Semaphore.hpp"

class Request
{
protected:
    Semaphore returnSema;

public:
    void execute() = 0;
    void waitReturn();
};
