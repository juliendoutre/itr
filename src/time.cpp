#include "include/time.hpp"

double timespec_to_ms(const timespec &time_ts)
{
    return time_ts.tv_sec * 1'000 + time_ts.tv_nsec / 1'000'000;
}

timespec timespec_from_ms(double time_ms)
{
    struct timespec time_ts;

    time_ts.tv_sec = long(time_ms * 1'000'000) / 1'000'000'000;

    long remains = long(time_ms * 1'000'000) % 1'000'000'000;
    time_ts.tv_nsec = remains;

    if (time_ts.tv_sec < 0 && remains != 0)
    {
        time_ts.tv_sec -= 1;
        time_ts.tv_nsec = 1'000'000'000 - remains;
    }

    return time_ts;
}

timespec timespec_now()
{
    struct timespec currentTime;
    clock_gettime(CLOCK_REALTIME, &currentTime);
    return currentTime;
}

timespec timespec_negate(const timespec &time_ts)
{
    struct timespec neg_time_ts;
    neg_time_ts.tv_sec = -time_ts.tv_sec;

    if (time_ts.tv_nsec != 0)
    {
        neg_time_ts.tv_sec -= 1;
        neg_time_ts.tv_nsec = 1'000'000'000 - time_ts.tv_nsec;
    }

    return neg_time_ts;
}

timespec timespec_add(const timespec &time1_ts, const timespec &time2_ts)
{
    struct timespec res_time_ts;
    res_time_ts.tv_sec = time1_ts.tv_sec + time2_ts.tv_sec;

    if (time1_ts.tv_nsec + time2_ts.tv_nsec > 1'000'000'000)
    {
        res_time_ts.tv_sec += 1;
        res_time_ts.tv_nsec = (time1_ts.tv_nsec + time2_ts.tv_nsec) % 1'000'000'000;
    }

    return res_time_ts;
}

timespec timespec_substract(const timespec &time1_ts, const timespec &time2_ts)
{
    return timespec_add(time1_ts, timespec_negate(time2_ts));
}

timespec timespec_wait(const timespec &delay_ts)
{
    struct timespec remaining_time_ts;
    nanosleep(&delay_ts, &remaining_time_ts);
    return remaining_time_ts;
}

timespec operator-(const timespec &time_ts)
{
    return timespec_negate(time_ts);
}

timespec operator+(const timespec &time1_ts, const timespec &time2_ts)
{
    return timespec_add(time1_ts, time2_ts);
}

timespec operator-(const timespec &time1_ts, const timespec &time2_ts)
{
    return timespec_substract(time1_ts, time2_ts);
}

timespec &operator+=(timespec &time_ts, const timespec &delay_ts)
{
    struct timespec res_time = timespec_add(time_ts, delay_ts);
    time_ts.tv_sec = res_time.tv_sec;
    time_ts.tv_nsec = res_time.tv_nsec;

    return time_ts;
}

timespec &operator-=(timespec &time_ts, const timespec &delay_ts)
{
    struct timespec res_time = timespec_substract(time_ts, delay_ts);
    time_ts.tv_sec = res_time.tv_sec;
    time_ts.tv_nsec = res_time.tv_nsec;

    return time_ts;
}

bool operator==(const timespec &time1_ts, const timespec &time2_ts)
{
    return time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec == time2_ts.tv_nsec;
}

bool operator!=(const timespec &time1_ts, const timespec &time2_ts)
{
    return time1_ts.tv_sec != time2_ts.tv_sec || time1_ts.tv_nsec != time2_ts.tv_nsec;
}

bool operator<(const timespec &time1_ts, const timespec &time2_ts)
{
    return time1_ts.tv_sec < time2_ts.tv_sec || (time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec < time2_ts.tv_nsec);
}

bool operator>(const timespec &time1_ts, const timespec &time2_ts)
{
    return time1_ts.tv_sec > time2_ts.tv_sec || (time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec > time2_ts.tv_nsec);
}

std::ostream &operator<<(std::ostream &os, const timespec &time_ts)
{
    os << "{s: " << time_ts.tv_sec << ", ns: " << time_ts.tv_nsec << "}";
    return os;
}
