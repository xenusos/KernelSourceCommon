/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once

#ifdef KERNEL

typedef int (XENUS_MS_ABI *thread_callback_t)(void * data);

typedef struct pt_regs 
{
	uint64_t r15;			   //unsigned long r15;
	uint64_t r14;			   //unsigned long r14;
	uint64_t r13;			   //unsigned long r13;
	uint64_t r12;			   //unsigned long r12;
	uint64_t rbp;			   //unsigned long bp;
	uint64_t rbx;			   //unsigned long bx;
	uint64_t r11;			   //unsigned long r11;
	uint64_t r10;			   //unsigned long r10;
	uint64_t r9;			   //unsigned long r9;
	uint64_t r8;			   //unsigned long r8;
	uint64_t rax;			   //unsigned long ax;
	uint64_t rcx;			   //unsigned long cx;
	uint64_t rdx;			   //unsigned long dx;
	uint64_t rsi;			   //unsigned long si;
	uint64_t rdi;			   //unsigned long di;
	uint64_t orig_rax;		   //unsigned long orig_ax;
	uint64_t rip;			   //unsigned long ip;
	uint64_t cs;			   //unsigned long cs;
	uint64_t eflags;		   //unsigned long flags;
	uint64_t rsp;			   //unsigned long sp;
	uint64_t ss;			   //unsigned long ss;
} *pt_regs_p, pt_regs_t;



typedef void (XENUS_MS_ABI *pre_context_switch_cb_t)(void);
typedef void (XENUS_MS_ABI *post_context_switch_cb_t)(void);
typedef void (XENUS_MS_ABI *post_context_switch_cb_t)(void);
typedef void	(XENUS_MS_ABI *xenus_attention_krn_cb_t)(uint8_t, pt_regs_p registers);
typedef void *	(XENUS_MS_ABI *xenus_attention_usr_cb_t)(uint8_t);

typedef struct
{
	// Do not touch, do not reorder, do not do anything

	union
	{
		void * tls_container;							// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
		void * tls_container_generic_a;					// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
	};

	void * tls_container_generic_b;						// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
	void * tls_container_generic_c;						// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
	void * tls_container_xstatic_ip;					// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
	void * tls_container_xstatic_global;				// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)	

	pre_context_switch_cb_t usr_switch_pre_callback;	// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
	post_context_switch_cb_t usr_switch_post_callback;	// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)

	pre_context_switch_cb_t kern_switch_pre_callback;	// OPTIONAL: to be called pre-preemption  (a/k/a out)
	post_context_switch_cb_t kern_switch_post_callback;	// OPTIONAL: to be called post-preemption (a/k/a in )

	xenus_attention_krn_cb_t kern_thread_attention_callback;// 
	xenus_attention_usr_cb_t user_thread_attention_callback;// 
	xenus_attention_usr_cb_t proc_thread_attention_callback;// 

	uint32_t fpu_enabled_via_hook;						// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
	uint32_t fpu_enabled_internal;						// OPT IMPL: to be used within the linux kernel for debugging begin/end fpu calls (are they nested? are push or pops non-complementory?) - this isn't that important

	uint64_t future_proofing[10];					    //

	// Do not touch, do not reorder, do not do anything
} *thread_storage_data_p, thread_storage_data_t;

#elif defined(XENUS_BUILD)
	// You do not need these thread_storage_data_p/thread_storage_data_t
typedef int (XENUS_MS_ABI *thread_callback_t)(void * data);
typedef void (XENUS_MS_ABI *pre_context_switch_callback_t)(void);
typedef void (XENUS_MS_ABI *post_context_switch_callback_t)(void);
#else
	// Bootstrap - these types are in sched.h ([...]/sched/core.h)
#endif