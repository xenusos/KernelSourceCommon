#pragma once 

/*
* Per process flags
*/
#define PF_IDLE                0x00000002    /* I am an IDLE thread */
#define PF_EXITING             0x00000004    /* Getting shut down */
#define PF_EXITPIDONE          0x00000008    /* PI exit done on shut down */
#define PF_VCPU                0x00000010    /* I'm a virtual CPU */
#define PF_WQ_WORKER           0x00000020    /* I'm a workqueue worker */
#define PF_FORKNOEXEC          0x00000040    /* Forked but didn't exec */
#define PF_MCE_PROCESS         0x00000080    /* Process policy on mce errors */
#define PF_SUPERPRIV           0x00000100    /* Used super-user privileges */
#define PF_DUMPCORE            0x00000200    /* Dumped core */
#define PF_SIGNALED            0x00000400    /* Killed by a signal */
#define PF_MEMALLOC            0x00000800    /* Allocating memory */
#define PF_NPROC_EXCEEDED      0x00001000    /* set_user() noticed that RLIMIT_NPROC was exceeded */
#define PF_USED_MATH           0x00002000    /* If unset the fpu must be initialized before use */
#define PF_USED_ASYNC          0x00004000    /* Used async_schedule*(), used by module init */
#define PF_NOFREEZE            0x00008000    /* This thread should not be frozen */
#define PF_FROZEN              0x00010000    /* Frozen for system suspend */
#define PF_KSWAPD              0x00020000    /* I am kswapd */
#define PF_MEMALLOC_NOFS       0x00040000    /* All allocation requests will inherit GFP_NOFS */
#define PF_MEMALLOC_NOIO       0x00080000    /* All allocation requests will inherit GFP_NOIO */
#define PF_LESS_THROTTLE       0x00100000    /* Throttle me less: I clean memory */
#define PF_KTHREAD             0x00200000    /* I am a kernel thread */
#define PF_RANDOMIZE           0x00400000    /* Randomize virtual address space */
#define PF_SWAPWRITE           0x00800000    /* Allowed to write to swap */
#define PF_NO_SETAFFINITY      0x04000000    /* Userland is not allowed to meddle with cpus_allowed */
#define PF_MCE_EARLY           0x08000000    /* Early kill for mce process policy */
#define PF_MUTEX_TESTER        0x20000000    /* Thread belongs to the rt mutex tester */
#define PF_FREEZER_SKIP        0x40000000    /* Freezer should not count it as freezable */
#define PF_SUSPEND_TASK        0x80000000    /* This thread called freeze_processes() and should not be frozen */
