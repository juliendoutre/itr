#include "Semaphore.hpp"

class Request
{
private:
    Semaphore returnSema;

public:
    void execute() = 0;
    void waitReturn();
};
