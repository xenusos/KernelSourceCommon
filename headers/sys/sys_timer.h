#pragma once

//timing
XENUS_IMPORT void msleep(unsigned int msecs);
XENUS_IMPORT unsigned long msleep_interruptible(unsigned int msecs);
XENUS_IMPORT void usleep_range(unsigned long min, unsigned long max);

static inline void ssleep(unsigned int seconds)
{
	msleep(seconds * 1000);
}