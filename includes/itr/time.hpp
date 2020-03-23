#pragma once
#include <time.h>
#include <iostream>

double timespec_to_ms(const timespec &time_ts);
timespec timespec_from_ms(double time_ms);

timespec timespec_now();
timespec timespec_wait(const timespec &delay_ts);

timespec timespec_negate(const timespec &time_ts);
timespec timespec_add(const timespec &time1_ts, const timespec &time2_ts);
timespec timespec_subtract(const timespec &time1_ts, const timespec &time2_ts);

timespec operator-(const timespec &time_ts);
timespec operator+(const timespec &time1_ts, const timespec &time2_ts);
timespec operator-(const timespec &time1_ts, const timespec &time2_ts);
timespec &operator+=(timespec &time_ts, const timespec &delay_ts);
timespec &operator-=(timespec &time_ts, const timespec &delay_ts);

bool operator==(const timespec &time1_ts, const timespec &time2_ts);
bool operator!=(const timespec &time1_ts, const timespec &time2_ts);
bool operator<(const timespec &time1_ts, const timespec &time2_ts);
bool operator>(const timespec &time1_ts, const timespec &time2_ts);

std::ostream &operator<<(std::ostream &os, const timespec &time_ts);