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
#include "_unknown_types.macros"
#undef DEFINE_TYPE

typedef void * delayed_call_k;


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

typedef struct
{ 
	pteval_t pte; 
} pte_t;
typedef struct pgprot 
{
	pgprotval_t pgprot_; 
} pgprot_t;
typedef struct { pgdval_t pgd; } pgd_t;


#define __AC(X,Y)			(X##Y)
#define _AC(X,Y)			__AC(X,Y)
#define _AT(T,X)			((T)(X))

#define PAGE_SHIFT			12
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