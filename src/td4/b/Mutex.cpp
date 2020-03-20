#include "include/Mutex.hpp"
#include <pthread.h>
#include "include/time.hpp"

Mutex::Mutex()
{
    pthread_mutexattr_t mutexAttribute;
    pthread_mutexattr_init(&mutexAttribute);
    pthread_mutexattr_settype(&mutexAttribute, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(&this->posixId, &mutexAttribute);

    pthread_mutexattr_destroy(&mutexAttribute);

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

Mutex::Monitor::Monitor(Mutex &mutex) : mutex(mutex) {}

void Mutex::Monitor::wait()
{
    pthread_cond_wait(&this->mutex.posixCondId, &this->mutex.posixId);
}

bool Mutex::Monitor::wait(double timeout_ms)
{
    timespec deadline = timespec_from_ms(timeout_ms) + timespec_now();
    return pthread_cond_timedwait(&this->mutex.posixCondId, &this->mutex.posixId, &deadline) == 0;
}

void Mutex::Monitor::notify()
{
    pthread_cond_signal(&this->mutex.posixCondId);
}

void Mutex::Monitor::notifyAll()
{
    pthread_cond_broadcast(&this->mutex.posixCondId);
}

Mutex::Lock::Lock(Mutex &mutex) : Mutex::Monitor(mutex)
{
    this->mutex.lock();
}

Mutex::Lock::Lock(Mutex &m, double timeout_ms) : Mutex::Monitor(m)
{
    if (!this->mutex.lock(timeout_ms))
    {
        throw Mutex::Monitor::TimeoutException();
    }
}

Mutex::Lock::~Lock()
{
    this->mutex.unlock();
}

Mutex::TryLock::TryLock(Mutex &mutex) : Mutex::Monitor(mutex)
{
    if (!this->mutex.trylock())
    {
        throw Mutex::Monitor::TimeoutException();
    }
}

Mutex::TryLock::~TryLock()
{
    this->mutex.unlock();
}
