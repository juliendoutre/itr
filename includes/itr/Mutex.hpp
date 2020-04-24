#ifndef Mutex_hpp_INCLUDED
#define Mutex_hpp_INCLUDED

#include <pthread.h>
#include <exception>

class Mutex
{
private:
    pthread_mutex_t posixId;
    pthread_cond_t posixCondId;
    void lock();
    bool lock(double timeout_ms);
    bool trylock();
    void unlock();

public:
    class Monitor;
    class Lock;
    class TryLock;

public:
    Mutex();
    ~Mutex();
};

class Mutex::Monitor
{
protected:
    Mutex &mutex;

protected:
    Monitor(Mutex &mutex);

public:
    class TimeoutException;

public:
    void wait();
    bool wait(double timeout_ms);
    void notify();
    void notifyAll();
};

class Mutex::Monitor::TimeoutException : public std::exception
{
    const char *what() const throw()
    {
        return "Failed to unlock the mutex";
    }
};

class Mutex::Lock : public Mutex::Monitor
{
public:
    Lock(Mutex &mutex);
    Lock(Mutex &mutex, double timeout_ms);
    ~Lock();
};

class Mutex::TryLock : public Mutex::Monitor
{
public:
    TryLock(Mutex &mutex);
    ~TryLock();
};

#endif
