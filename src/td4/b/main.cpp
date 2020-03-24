#include "itr/Mutex.hpp"

int main()
{
    Mutex mutex;
    Mutex::Lock lock = Mutex::Lock(mutex);

    return 0;
}
