#pragma once

//timing
XENUS_IMPORT void msleep(unsigned int msecs);
XENUS_IMPORT l_ulong msleep_interruptible(unsigned int msecs);
XENUS_IMPORT void usleep_range(l_ulong min, l_ulong max);

static inline void ssleep(unsigned int seconds)
{
	msleep(seconds * 1000);
}
