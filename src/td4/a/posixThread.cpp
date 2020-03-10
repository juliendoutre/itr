#include "include/posixThread.hpp"
#include "include/time.hpp"

PosixThread::PosixThread()
{
    pthread_attr_init(&this->posixAttr);
    this->isActive = false;
}

PosixThread::PosixThread(pthread_t posixId)
{
    int errorCode = pthread_getschedparam(posixId, nullptr, nullptr);
    if (errorCode != 0)
    {
        throw Exception();
    }

    this->posixId = posixId;
    this->isActive = true;
}

PosixThread::~PosixThread()
{
    pthread_attr_destroy(&this->posixAttr);
}

void PosixThread::join()
{
    pthread_join(this->posixId, nullptr);
    this->isActive = false;
}

void PosixThread::start(void *(*threadFunc)(void *), void *threadArg)
{
    pthread_create(&this->posixId, nullptr, threadFunc, threadArg);
    this->isActive = true;
}

bool PosixThread::join(double timeout_ms)
{
    timespec timeout_ts = timespec_from_ms(timeout_ms);
    bool status = (bool)pthread_timedjoin_np(this->posixId, nullptr, &timeout_ts);
    this->isActive = false;
    return status;
}

bool PosixThread::setScheduling(int schedPolicy, int priority)
{

    pthread_attr_setschedpolicy(&this->posixAttr, schedPolicy);
    sched_param schedParams;
    schedParams.sched_priority = priority;
    pthread_attr_setschedparam(&this->posixAttr, &schedParams);

    if (this->isActive)
    {
        sched_param schedParams;
        schedParams.sched_priority = priority;
        pthread_setschedparam(this->posixId, schedPolicy, &schedParams);
    }

    return this->isActive;
}

bool PosixThread::getScheduling(int *p_schedPolicy = nullptr, int *p_priority = nullptr)
{
    if (this->isActive)
    {
        sched_param schedParams;
        pthread_getschedparam(this->posixId, p_schedPolicy, &schedParams);
        p_priority = &schedParams.sched_priority;
    }
    else
    {
        pthread_attr_getschedpolicy(&this->posixAttr, p_schedPolicy);
        sched_param schedParams;
        pthread_attr_getschedparam(&this->posixAttr, &schedParams);
        p_priority = &schedParams.sched_priority;
    }

    return this->isActive;
}
