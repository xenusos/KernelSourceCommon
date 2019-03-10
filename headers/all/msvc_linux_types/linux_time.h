#pragma once 

typedef struct timespec 
{
    __kernel_time_t     tv_sec;      /* seconds */
    l_long              tv_nsec;     /* nanoseconds */
} *timespec_k;

typedef struct timeval
{
    __kernel_time_t      tv_sec;     /* seconds */
    __kernel_suseconds_t tv_usec;    /* microseconds */
} *timeval_k;

typedef struct timezone
{
    l_int    tz_minuteswest;         /* minutes west of Greenwich */
    l_int    tz_dsttime;             /* type of dst correction */
} *timezone_k;


typedef s64 time64_t;
typedef u64 timeu64_t;

typedef struct timespec64 {
    time64_t    tv_sec;              /* seconds */
    long        tv_nsec;             /* nanoseconds */
} *timespec64_k;


typedef struct itimerspec64 {
    struct timespec64 it_interval;
    struct timespec64 it_value;
} *itimerspec64_k;


/*
* Names of the interval timers, and structure
* defining a timer setting:
*/
#define    ITIMER_REAL        0
#define    ITIMER_VIRTUAL     1
#define    ITIMER_PROF        2

struct itimerspec {
    struct timespec it_interval;     /* timer period */
    struct timespec it_value;        /* timer expiration */
};

struct itimerval {                  
    struct timeval it_interval;      /* timer interval */
    struct timeval it_value;         /* current value */
};

enum tk_offsets {
    TK_OFFS_REAL,
    TK_OFFS_BOOT,
    TK_OFFS_TAI,
    TK_OFFS_MAX,
};

typedef int64_t    ktime_t;
