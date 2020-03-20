#pragma once
#include <pthread.h>
#include <exception>

class PosixThread
{
private:
    pthread_t posixId;
    pthread_attr_t posixAttr;

protected:
    bool isActive;

public:
    class Exception;

public:
    PosixThread();
    PosixThread(pthread_t posixId);
    ~PosixThread();
    void start(void *(*threadFunc)(void *), void *threadArg);
    void join();
    bool join(double timeout_ms);
    bool setScheduling(int schedPolicy, int priority);
    bool getScheduling(int *p_schedPolicy, int *p_priority);
};

class PosixThread::Exception
{
};
