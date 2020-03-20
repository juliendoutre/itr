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

class Mutex::Monitor::TimeoutException
{
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
