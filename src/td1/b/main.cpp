#include <signal.h>
#include <time.h>
#include <iostream>

void handler(int, siginfo_t *si, void *)
{
    std::cout << *(volatile int *)(si->si_value.sival_ptr) << std::endl;
    *(volatile int *)(si->si_value.sival_ptr) += 1;
}

// Create a POSIX timer and wait for its handler until it incremented a counter from 0 to 15.
int main()
{
    volatile int counter = 0;

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void *)&counter;

    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);

    itimerspec its;
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 500'000'000;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 500'000'000;

    timer_settime(tid, 0, &its, nullptr);

    while (counter < 15)
    {
    }

    timer_delete(tid);

    return EXIT_SUCCESS;
}
