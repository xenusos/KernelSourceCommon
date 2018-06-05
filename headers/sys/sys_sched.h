#pragma once


// current


XENUS_IMPORT void(*kernel_fpu_begin)							(void);	// UNSAFE!
XENUS_IMPORT void(*kernel_fpu_end)							(void); // UNSAFE!

XENUS_IMPORT task_k _current(void);

//preemption

XENUS_IMPORT void preempt_enable(void);
XENUS_IMPORT void preempt_disable(void);

//timing

XENUS_IMPORT void msleep(unsigned int msecs);
XENUS_IMPORT unsigned long msleep_interruptible(unsigned int msecs);
XENUS_IMPORT void usleep_range(unsigned long min, unsigned long max);

static inline void ssleep(unsigned int seconds)
{
	msleep(seconds * 1000);
}


// core
