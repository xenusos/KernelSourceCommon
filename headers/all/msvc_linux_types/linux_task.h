#pragma once
enum vtime_state {
    /* Task is sleeping or running in a CPU with VTIME inactive: */
    VTIME_INACTIVE = 0,
    /* Task runs in userspace in a CPU with VTIME active: */
    VTIME_USER,
    /* Task runs in kernelspace in a CPU with VTIME active: */
    VTIME_SYS,
};

typedef struct task_cputime {
    uint64_t				utime;
    uint64_t				stime;
    unsigned long long		sum_exec_runtime;
} *task_cputime_k;

typedef struct sched_param {
    int sched_priority;
} *sched_param_k;

#define PF_IDLE				0x00000002  /* I am an IDLE thread */
#define PF_EXITING			0x00000004  /* Getting shut down */
#define PF_EXITPIDONE		0x00000008  /* PI exit done on shut down */
#define PF_VCPU				0x00000010  /* I'm a virtual CPU */
#define PF_WQ_WORKER		0x00000020  /* I'm a workqueue worker */
#define PF_FORKNOEXEC		0x00000040  /* Forked but didn't exec */
#define PF_MCE_PROCESS		0x00000080  /* Process policy on mce errors */
#define PF_SUPERPRIV		0x00000100  /* Used super-user privileges */
#define PF_DUMPCORE			0x00000200  /* Dumped core */
#define PF_SIGNALED			0x00000400  /* Killed by a signal */
#define PF_MEMALLOC			0x00000800  /* Allocating memory */
#define PF_NPROC_EXCEEDED	0x00001000  /* set_user() noticed that RLIMIT_NPROC was exceeded */
#define PF_USED_MATH		0x00002000  /* If unset the fpu must be initialized before use */
#define PF_USED_ASYNC		0x00004000  /* Used async_schedule*(), used by module init */
#define PF_NOFREEZE			0x00008000  /* This thread should not be frozen */
#define PF_FROZEN			0x00010000  /* Frozen for system suspend */
#define PF_KSWAPD			0x00020000  /* I am kswapd */
#define PF_MEMALLOC_NOFS	0x00040000  /* All allocation requests will inherit GFP_NOFS */
#define PF_MEMALLOC_NOIO	0x00080000  /* All allocation requests will inherit GFP_NOIO */
#define PF_LESS_THROTTLE	0x00100000  /* Throttle me less: I clean memory */
#define PF_KTHREAD			0x00200000  /* I am a kernel thread */
#define PF_RANDOMIZE		0x00400000  /* Randomize virtual address space */
#define PF_SWAPWRITE		0x00800000  /* Allowed to write to swap */
#define PF_NO_SETAFFINITY	0x04000000  /* Userland is not allowed to meddle with cpus_allowed */
#define PF_MCE_EARLY		0x08000000  /* Early kill for mce process policy */
#define PF_MUTEX_TESTER		0x20000000  /* Thread belongs to the rt mutex tester */
#define PF_FREEZER_SKIP		0x40000000  /* Freezer should not count it as freezable */
#define PF_SUSPEND_TASK		0x80000000  /* This thread called freeze_processes() and should not be frozen */


/* Used in tsk->state: */
#define TASK_RUNNING			0x0000
#define TASK_INTERRUPTIBLE		0x0001
#define TASK_UNINTERRUPTIBLE	0x0002
#define __TASK_STOPPED			0x0004
#define __TASK_TRACED			0x0008
/* Used in tsk->exit_state: */
#define EXIT_DEAD				0x0010
#define EXIT_ZOMBIE				0x0020
#define EXIT_TRACE				(EXIT_ZOMBIE | EXIT_DEAD)
/* Used in tsk->state again: */
#define TASK_PARKED				0x0040
#define TASK_DEAD				0x0080
#define TASK_WAKEKILL			0x0100
#define TASK_WAKING				0x0200
#define TASK_NOLOAD				0x0400
#define TASK_NEW				0x0800
#define TASK_STATE_MAX			0x1000

/* Convenience macros for the sake of set_current_state: */
#define TASK_KILLABLE			(TASK_WAKEKILL | TASK_UNINTERRUPTIBLE)
#define TASK_STOPPED			(TASK_WAKEKILL | __TASK_STOPPED)
#define TASK_TRACED				(TASK_WAKEKILL | __TASK_TRACED)
#define TASK_IDLE				(TASK_UNINTERRUPTIBLE | TASK_NOLOAD)

/* Convenience macros for the sake of wake_up(): */
#define TASK_NORMAL				(TASK_INTERRUPTIBLE | TASK_UNINTERRUPTIBLE)
#define TASK_ALL				(TASK_NORMAL | __TASK_STOPPED | __TASK_TRACED)

/* get_task_state(): */
#define TASK_REPORT				(TASK_RUNNING | TASK_INTERRUPTIBLE | TASK_UNINTERRUPTIBLE | __TASK_STOPPED | __TASK_TRACED | EXIT_DEAD | EXIT_ZOMBIE | TASK_PARKED)

#define task_is_traced(task_state)		((task_state & __TASK_TRACED) != 0)
#define task_is_stopped(task_state)		((task_state & __TASK_STOPPED) != 0)
#define task_is_stopped_or_traced(task_state)	((task_state & (__TASK_STOPPED | __TASK_TRACED)) != 0)
#define task_contributes_to_load(task_state, task_flag)	((task_state & TASK_UNINTERRUPTIBLE) != 0 && (task_flag & PF_FROZEN) == 0 && (task_state & TASK_NOLOAD) == 0)

#define HIDEPID_OFF 0
#define HIDEPID_NO_ACCESS 1
#define HIDEPID_INVISIBLE 2

#define MAX_NICE	19
#define MIN_NICE	-20
#define NICE_WIDTH	(MAX_NICE - MIN_NICE + 1)
#define MAX_USER_RT_PRIO	100
#define MAX_RT_PRIO		MAX_USER_RT_PRIO
#define MAX_PRIO		(MAX_RT_PRIO + NICE_WIDTH)
#define DEFAULT_PRIO		(MAX_RT_PRIO + NICE_WIDTH / 2)
#define NICE_TO_PRIO(nice)	((nice) + DEFAULT_PRIO)
#define PRIO_TO_NICE(prio)	((prio) - DEFAULT_PRIO)
#define USER_PRIO(p)		((p)-MAX_RT_PRIO)
#define TASK_USER_PRIO(p)	USER_PRIO((p)->static_prio)
#define MAX_USER_PRIO		(USER_PRIO(MAX_PRIO))

static inline long nice_to_rlimit(long nice)
{
    return (MAX_NICE - nice + 1);
}

static inline long rlimit_to_nice(long prio)
{
    return (MAX_NICE - prio + 1);
}

typedef struct
{
    uint64_t cpu_mask;
    uint64_t fuckyourserver_mask;
} cpumask;
typedef cpumask *			cpumask_k;

#define OSThread _current()
