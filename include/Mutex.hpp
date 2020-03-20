#pragma once
#include <pthread.h>

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
    Mutex();
    ~Mutex();
    class Monitor;
    class Lock;
    class TryLock;
};

class Mutex::Monitor
{
protected:
    Monitor(Mutex &m);

public:
    class TimeoutException
    {
    };

    void wait();
    bool wait(double timeout_ms);
    void notify();
    void notifyAll();
};

class Mutex::Lock : public Mutex::Monitor
{
public:
    Lock(Mutex &m);
    Lock(Mutex &m, double timeout_ms);
    ~Lock();
};

class Mutex::TryLock : public Mutex::Monitor
{
public:
    TryLock(Mutex &m);
    ~TryLock();
};
