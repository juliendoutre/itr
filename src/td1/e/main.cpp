/**
 * @file
 * A better function execution time calibration for @ref td1_e.
 * @anchor td1_e_main
 * */

#include <iostream>
#include <climits>
#include <signal.h>
#include "itr/time.hpp"
#include <vector>

struct Sample
{
    double time_ms;
    unsigned int loopsNumber;
};

struct Data
{
    std::vector<Sample> samples;
    unsigned int nSamples;
    volatile bool pStop;
    volatile unsigned int iLoop;
    double startTime;
};

struct Parameters
{
    double a;
    double b;
};

void handler(int, siginfo_t *si, void *)
{
    Data *data = (Data *)(si->si_value.sival_ptr);
    if (data->samples.size() < data->nSamples)
    {
        data->samples.push_back(Sample{
            timespec_to_ms(timespec_now()) - data->startTime,
            data->iLoop,
        });
    }
    else
    {
        data->pStop = true;
    }
}

unsigned int incr(unsigned int nLoops, double *pCounter, Data *data)
{
    unsigned int doneLoops = 0;

    while (doneLoops < nLoops && !data->pStop)
    {
        *pCounter += 1.0;
        doneLoops++;
        data->iLoop = doneLoops;
    }

    return doneLoops;
}

std::vector<Sample> run(double samplingPeriod_ms, unsigned int samplesNumber)
{
    double counter = 0;

    struct Data data;
    data.pStop = false;
    data.iLoop = 0;
    data.nSamples = samplesNumber;

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void *)&data;

    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);
    itimerspec its;
    its.it_value = timespec_from_ms(samplingPeriod_ms);
    its.it_interval = timespec_from_ms(samplingPeriod_ms);
    timer_settime(tid, 0, &its, nullptr);

    data.startTime = timespec_to_ms(timespec_now());
    incr(UINT_MAX, &counter, &data);

    timer_delete(tid);

    return data.samples;
}

Parameters calibrate()
{
    struct Parameters params;

    std::vector<Sample> samples = run(10, 100);

    double xSum = 0;
    double ySum = 0;
    double xySum = 0;
    double xSquareSum = 0;
    for (auto const &s : samples)
    {
        xSum += s.time_ms;
        ySum += s.loopsNumber;
        xySum += s.time_ms * s.loopsNumber;
        xSquareSum += s.time_ms * s.time_ms;
    }

    params.a = (samples.size() * xySum - xSum * ySum) / (samples.size() * xSquareSum - xSum * xSum);
    params.b = (ySum * xSquareSum - xSum * xySum) / (samples.size() * xSquareSum - xSum * xSum);

    return params;
}

int main()
{
    struct Parameters parameters = calibrate();

    std::cout << "number of loops function of the time: y = " << parameters.a << "t + " << parameters.b << std::endl;

    return EXIT_SUCCESS;
}
