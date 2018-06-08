/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once


//_k = unknown (K)ernel type
// general
typedef void *	unknown_k;

#define DEFINE_TYPE(x) typedef void * x ## _k
#include "_unknown_types.macros"
#undef DEFINE_TYPE

struct llist_head {
	struct llist_node *first;
};

struct llist_node {
	struct llist_node *next;
};

struct callback_head {
	struct callback_head *next;
	void(*func)(struct callback_head *head);
}/*__attribute__((aligned(sizeof(void *))));*/;


enum pid_type
{
	PIDTYPE_PID,
	PIDTYPE_PGID,
	PIDTYPE_SID,
	PIDTYPE_MAX,
	/* only valid to __task_pid_nr_ns() */
	__PIDTYPE_TGID
};



struct rb_node {
	unsigned long  __rb_parent_color;
	struct rb_node *rb_right;
	struct rb_node *rb_left;
};

struct rb_root {
	struct rb_node *rb_node;
};

/*
* Leftmost-cached rbtrees.
*
* We do not cache the rightmost node based on footprint
* size vs number of potential users that could benefit
* from O(1) rb_last(). Just not worth it, users that want
* this feature can always implement the logic explicitly.
* Furthermore, users that want to cache both pointers may
* find it a bit asymmetric, but that's ok.
*/
struct rb_root_cached {
	struct rb_root rb_root;
	struct rb_node *rb_leftmost;
};

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

struct list_head {
	struct list_head *next, *prev;
};

struct hlist_head {
	struct hlist_node *first;
};

struct hlist_node {
	struct hlist_node *next, **pprev;
};

typedef struct {
	int counter;
} atomic_t;



typedef int					pci_power_t;


typedef uint64_t			cpumask; //TODO: int 128
typedef cpumask *			cpumask_k;


typedef long long			__kernel_long_t;
typedef unsigned long long	__kernel_ulong_t;
#define __kernel_long_t		__kernel_long_t

typedef __kernel_long_t		__kernel_off_t;
typedef long long			__kernel_loff_t;
typedef __kernel_long_t		__kernel_time_t;
typedef __kernel_long_t		__kernel_clock_t;
typedef int					__kernel_timer_t;
typedef int					__kernel_clockid_t;
typedef char *				__kernel_caddr_t;
typedef unsigned short		__kernel_uid16_t;
typedef unsigned short		__kernel_gid16_t;
typedef __kernel_long_t		__kernel_suseconds_t;
typedef int					__kernel_daddr_t;
typedef unsigned int		__kernel_uid32_t;
typedef unsigned int		__kernel_gid32_t;
typedef unsigned int		__kernel_uid_t;
typedef int					__kernel_pid_t;
typedef unsigned int		__kernel_mode_t;
typedef unsigned int		__kernel_gid_t;


typedef __kernel_loff_t				loff_t;
typedef __kernel_off_t				off_t;
typedef __kernel_loff_t				loff_t;
typedef __kernel_time_t				time_t;
typedef __kernel_clock_t			clock_t;
typedef __kernel_timer_t			timer_t;
typedef __kernel_clockid_t			clockid_t;
typedef __kernel_caddr_t			caddr_t;
typedef __kernel_uid16_t			uid16_t;
typedef __kernel_gid16_t			gid16_t;
typedef __kernel_suseconds_t		suseconds_t;
typedef __kernel_daddr_t			daddr_t;
typedef __kernel_uid32_t			uid32_t;
typedef __kernel_gid32_t			gid32_t;
typedef __kernel_uid_t				uid_t;
typedef __kernel_pid_t				pid_t;
typedef __kernel_mode_t				mode_t;
typedef __kernel_gid_t				gid_t;
typedef size_t						dev_t;

typedef physical_address_t resource_size_t;
typedef physical_address_t dma_addr_t;
typedef physical_address_t pci_bus_addr_t;

typedef unsigned long pteval_t;
typedef unsigned long pmdval_t;
typedef unsigned long pudval_t;
typedef unsigned long p4dval_t;
typedef unsigned long pgdval_t;
typedef unsigned long pgprotval_t;

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
#define PFN_PHYS(x)			((physical_address_t)(x) << PAGE_SHIFT)
#define PHYS_PFN(x)			((unsigned long)((x) >> PAGE_SHIFT))


typedef unsigned short umode_t;

typedef struct {
	uid_t val;
} kuid_t;


typedef struct {
	gid_t val;
} kgid_t;

//typedef int(*filldir_t)(struct dir_context *, const char *, int, loff_t, u64,
//	unsigned);
typedef void * filldir_t;