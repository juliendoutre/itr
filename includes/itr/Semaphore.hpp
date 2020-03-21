#include <limits.h>

class Semaphore
{
private:
    unsigned int counter;
    unsigned int maxCount;

public:
    Semaphore(unsigned int initCount = 0, unsigned int maxCount = UINT_MAX);
    void give();
    void take();
    bool take(double timeout_ms);
};
