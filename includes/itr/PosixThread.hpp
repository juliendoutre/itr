#ifndef PosixThread_hpp_INCLUDED
#define PosixThread_hpp_INCLUDED

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

class PosixThread::Exception : public std::exception
{
    const char *what() const throw()
    {
        return "No existing thread matches this Posix id";
    }
};

#endif
