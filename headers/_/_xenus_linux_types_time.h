#pragma once 

struct timespec {
	__kernel_time_t	tv_sec;			/* seconds */
	long			tv_nsec;		/* nanoseconds */
};

struct timeval {
	__kernel_time_t		tv_sec;			/* seconds */
	__kernel_suseconds_t	tv_usec;	/* microseconds */
};

struct timezone {
	int	tz_minuteswest;	/* minutes west of Greenwich */
	int	tz_dsttime;	/* type of dst correction */
};


/*
* Names of the interval timers, and structure
* defining a timer setting:
*/
#define	ITIMER_REAL		0
#define	ITIMER_VIRTUAL		1
#define	ITIMER_PROF		2

struct itimerspec {
	struct timespec it_interval;	/* timer period */
	struct timespec it_value;	/* timer expiration */
};

struct itimerval {
	struct timeval it_interval;	/* timer interval */
	struct timeval it_value;	/* current value */
};
