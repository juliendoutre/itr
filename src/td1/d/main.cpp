#include <iostream>
#include <climits>
#include <signal.h>
#include "itr/time.hpp"

void handler(int, siginfo_t *si, void *)
{
    *(volatile bool *)(si->si_value.sival_ptr) = true;
}

unsigned int incr(unsigned int nLoops, double *pCounter, volatile bool *pStop)
{
    unsigned int doneLoops = 0;

    while (doneLoops < nLoops && !(*pStop))
    {
        *pCounter += 1.0;
        doneLoops++;
    }

    return doneLoops;
}

struct Sample
{
    int seconds;
    unsigned int loopsNumber;
};

Sample run(int seconds)
{
    struct Sample sample;
    sample.seconds = seconds;

    double counter = 0.0;
    volatile bool pStop = false;

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void *)&pStop;

    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);

    itimerspec its;
    its.it_value.tv_sec = seconds;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;

    timer_settime(tid, 0, &its, nullptr);

    struct timespec start_ts = timespec_now();
    sample.loopsNumber = incr(UINT_MAX, &counter, &pStop);
    struct timespec end_ts = timespec_now();

    timer_delete(tid);

    std::cout << "counter value: " << counter << std::endl;
    std::cout << "loops done: " << sample.loopsNumber << std::endl;
    std::cout << "function execution time: " << end_ts - start_ts << std::endl;

    return sample;
}

struct Parameters
{
    double a;
    double b;
};

Parameters calibrate()
{
    struct Parameters params;

    Sample p1 = run(4);
    Sample p2 = run(6);

    params.a = (p2.loopsNumber - p1.loopsNumber) / (p2.seconds - p1.seconds);
    params.b = p2.loopsNumber - params.a * p2.seconds;

    return params;
}

int main()
{
    struct Parameters parameters = calibrate();

    std::cout << "number of loops function of the time: y = " << parameters.a << "t + " << parameters.b << std::endl;

    return EXIT_SUCCESS;
}
