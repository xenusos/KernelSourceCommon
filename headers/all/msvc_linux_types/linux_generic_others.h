/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once


//_k = unknown (K)ernel type
// general
typedef void *	unknown_k;

#define DEFINE_TYPE(fuckoff, x) typedef void * x ## _k
#include <all/_unknown_types.macros>
#undef DEFINE_TYPE

// TODO: make into portable types:
typedef void * lockref_k;
typedef void * spinlock_t_k;   // #ifdef nightmare
typedef void * lockdep_map_k;  // no lock maps
typedef void * class_compat_k; // no public defintion. AHHHAH fuck linux
typedef void * kernel_symbol_k;
typedef void nodemask_t;
typedef void * page_frag_cache_k;
typedef void * sysinfo_k;
typedef void * vm_struct_k;

typedef sysv_fptr_t pte_fn_t;

typedef void  sigset_t;


#define __ARCH_SI_PREAMBLE_SIZE	(3 * sizeof(l_int))
#define SI_MAX_SIZE	128
#define SI_PAD_SIZE	((SI_MAX_SIZE - __ARCH_SI_PREAMBLE_SIZE) / sizeof(l_int))
typedef struct siginfo { //TODO: portable type - padding and changes could be an issue
    l_int si_signo;
#ifndef __ARCH_HAS_SWAPPED_SIGINFO
    l_int si_errno;
    l_int si_code;
#else
    l_int si_code;
    l_int si_errno;
#endif

    union {
        l_int _pad[SI_PAD_SIZE];

        /* kill() */
        struct {
            l_int _pid;	/* sender's pid */
            l_uint _uid;	/* sender's uid */
        } _kill;
    };
} siginfo_t;

typedef void * siginfo_k;
typedef void * __sighandler_t;


//kernel_symbol

typedef wait_queue_entry_k wait_queue_entry_t_p;
typedef task_k task_struct_k;
//enum pid_type

typedef l_unsigned gfp_t;

#define XENUS_SUBCLASSES_SAFETYBUFFER (10UL)
#define MAX_LOCKDEP_SUBCLASSES		  (8UL + XENUS_SUBCLASSES_SAFETYBUFFER)

#pragma pack(push, 1)
struct lockdep_subclass_key {
    char __one_byte;
};
#pragma pack(pop)

typedef struct lock_class_key {
    struct lockdep_subclass_key	subkeys[MAX_LOCKDEP_SUBCLASSES];
} *lock_class_key_k;

struct callback_head {
	struct callback_head *next;
	void(*func)(struct callback_head *head);
}/*__attribute__((aligned(sizeof(void *))));*/;

enum vtime_state {
	/* Task is sleeping or running in a CPU with VTIME inactive: */
	VTIME_INACTIVE = 0,
	/* Task runs in userspace in a CPU with VTIME active: */
	VTIME_USER,
	/* Task runs in kernelspace in a CPU with VTIME active: */
	VTIME_SYS,
};

typedef struct {
	uint64_t val;
} pfn_t;



typedef struct
{
	union
	{
		uint64_t cpu_mask;
#ifndef PRODUCTION
		struct
		{
			//bitwise macros? nah. i hate myself
			uint64_t core_0 : 1;
			uint64_t core_1 : 1;
			uint64_t core_2 : 1;
			uint64_t core_3 : 1;
			uint64_t core_4 : 1;
			uint64_t core_5 : 1;
			uint64_t core_6 : 1;
			uint64_t core_7 : 1;
			uint64_t core_8 : 1;
			uint64_t core_9 : 1;
			uint64_t core_10 : 1;
			uint64_t core_11 : 1;
			uint64_t core_12 : 1;
			uint64_t core_13 : 1;
			uint64_t core_14 : 1;
			uint64_t core_15 : 1;
			uint64_t core_16 : 1;
			uint64_t core_17 : 1;
			uint64_t core_18 : 1;
			uint64_t core_19 : 1;
			uint64_t core_20 : 1;
			uint64_t core_21 : 1;
			uint64_t core_22 : 1;
			uint64_t core_23 : 1;
			uint64_t core_24 : 1;
			uint64_t core_25 : 1;
			uint64_t core_26 : 1;
			uint64_t core_27 : 1;
			uint64_t core_28 : 1;
			uint64_t core_29 : 1;
			uint64_t core_30 : 1;
			uint64_t core_31 : 1;
			uint64_t core_32 : 1;
			uint64_t core_33 : 1;
			uint64_t core_34 : 1;
			uint64_t core_35 : 1;
			uint64_t core_36 : 1;
			uint64_t core_37 : 1;
			uint64_t core_38 : 1;
			uint64_t core_39 : 1;
			uint64_t core_40 : 1;
			uint64_t core_41 : 1;
			uint64_t core_42 : 1;
			uint64_t core_43 : 1;
			uint64_t core_44 : 1;
			uint64_t core_45 : 1;
			uint64_t core_46 : 1;
			uint64_t core_47 : 1;
			uint64_t core_48 : 1;
			uint64_t core_49 : 1;
			uint64_t core_50 : 1;
			uint64_t core_51 : 1;
			uint64_t core_52 : 1;
			uint64_t core_53 : 1;
			uint64_t core_54 : 1;
			uint64_t core_55 : 1;
			uint64_t core_56 : 1;
			uint64_t core_57 : 1;
			uint64_t core_58 : 1;
			uint64_t core_59 : 1;
			uint64_t core_60 : 1;
			uint64_t core_61 : 1;
			uint64_t core_62 : 1;
			uint64_t core_63 : 1;
		};
#endif
	};
} cpumask; 
typedef cpumask *			cpumask_k;




typedef size_t						__kernel_size_t;
typedef ssize_t						__kernel_ssize_t;
typedef ptrdiff_t					__kernel_ptrdiff_t;

typedef l_long						__kernel_long_t;
typedef l_u_long					__kernel_ulong_t;

typedef __kernel_long_t				__kernel_off_t;
typedef l_longlong					__kernel_loff_t;
typedef __kernel_long_t				__kernel_time_t;
typedef __kernel_long_t				__kernel_clock_t;
typedef l_int						__kernel_timer_t;
typedef l_int						__kernel_clockid_t;
typedef char *						__kernel_caddr_t;
typedef l_short						__kernel_uid16_t;
typedef l_short						__kernel_gid16_t;
typedef __kernel_long_t				__kernel_suseconds_t;
typedef l_int						__kernel_daddr_t;
typedef l_uint						__kernel_uid32_t;
typedef l_uint						__kernel_gid32_t;
typedef l_uint						__kernel_uid_t;
typedef l_int						__kernel_pid_t;
typedef l_uint						__kernel_mode_t;
typedef l_uint						__kernel_gid_t;

typedef l_int						__kernel_ipc_pid_t;
typedef l_int						__kernel_key_t;
typedef l_int						__kernel_mqd_t;
typedef __kernel_ulong_t			__kernel_ino_t;
typedef u32							__kernel_dev_t;

#define __FD_SETSIZE	1024
typedef struct {
	unsigned long fds_bits[__FD_SETSIZE / (8 * sizeof(l_long))];
} __kernel_fd_set;

typedef __kernel_off_t				off_t;
typedef __kernel_loff_t				loff_t;


typedef __kernel_pid_t		pid_t;
typedef __kernel_gid_t		gid_t;

typedef __kernel_suseconds_t		suseconds_t;
typedef __kernel_time_t				time_t;
typedef __kernel_timer_t			timer_t;
typedef __kernel_clock_t			clock_t;
typedef __kernel_clockid_t			clockid_t;

typedef __kernel_caddr_t			caddr_t;
typedef __kernel_daddr_t			daddr_t;

typedef __kernel_uid32_t			uid32_t;
typedef __kernel_gid32_t			gid32_t;

typedef __kernel_mode_t				mode_t;
typedef l_ushort					umode_t;

typedef u32							nlink_t;

typedef __kernel_fd_set				fd_set;
typedef __kernel_dev_t				dev_t;
typedef __kernel_ino_t				ino_t;
typedef __kernel_key_t				key_t;
typedef __kernel_mqd_t				mqd_t;


typedef __kernel_uid32_t			uid_t;
typedef __kernel_gid32_t			gid_t;
typedef __kernel_uid16_t			uid16_t;
typedef __kernel_gid16_t			gid16_t;


typedef l_u_long					pteval_t;
typedef l_u_long					pmdval_t;
typedef l_u_long					pudval_t;
typedef l_u_long					p4dval_t;
typedef l_u_long					pgdval_t;
typedef l_u_long					pgprotval_t;

#define MINORBITS       20
#define MINORMASK       ((1U << MINORBITS) - 1)

#define MAJOR(dev)      ((unsigned int) ((dev) >> MINORBITS))
#define MINOR(dev)      ((unsigned int) ((dev) & MINORMASK))
#define MKDEV(ma,mi)    (((ma) << MINORBITS) | (mi))


#define __AC(X,Y)			(X##Y)
#define _AC(X,Y)			__AC(X,Y)
#define _AT(T,X)			((T)(X))

#define PAGE_SHIFT			(kernel_information.LINUX_PAGE_SHIFT)
#define PAGE_SIZE			(_AC(1,UL) << PAGE_SHIFT)
#define PAGE_MASK			(~(PAGE_SIZE-1))

#define PFN_ALIGN(x)		(((unsigned long)(x) + (PAGE_SIZE - 1)) & PAGE_MASK)
#define PFN_UP(x)			(((x) + PAGE_SIZE-1) >> PAGE_SHIFT)
#define PFN_DOWN(x)			((x) >> PAGE_SHIFT)
#define PFN_PHYS(x)			((phys_addr_t)(x) << PAGE_SHIFT)
#define PHYS_PFN(x)			((unsigned long)((x) >> PAGE_SHIFT))

typedef struct {
	uid_t val;
} kuid_t;


typedef struct {
	gid_t val;
} kgid_t;

//typedef int(*filldir_t)(struct dir_context *, const char *, int, loff_t, u64,
//	unsigned);
typedef void * filldir_t;


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