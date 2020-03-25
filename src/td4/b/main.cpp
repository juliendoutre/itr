#include "itr/Mutex.hpp"
#include "Looper.hpp"

int main()
{
    Mutex mutex;
    Mutex::Lock lock = Mutex::Lock(mutex);

    return 0;
}
