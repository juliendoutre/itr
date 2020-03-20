#include "include/Mutex.hpp"
#include <pthread.h>
#include "include/time.hpp"

Mutex::Mutex()
{
    pthread_mutex_init(&this->posixId, nullptr);
    pthread_cond_init(&this->posixCondId, nullptr);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&this->posixId);
    pthread_cond_destroy(&this->posixCondId);
}

void Mutex::lock()
{
    pthread_mutex_lock(&this->posixId);
}

bool Mutex::lock(double timeout_ms)
{
    timespec deadline = timespec_from_ms(timeout_ms) + timespec_now();
    return pthread_mutex_timedlock(&this->posixId, &deadline) == 0;
}

bool Mutex::trylock()
{
    return pthread_mutex_trylock(&this->posixId) == 0;
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&this->posixId);
}
