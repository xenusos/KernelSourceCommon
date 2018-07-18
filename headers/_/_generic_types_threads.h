/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once
#ifndef _H_GENERIC_TYPES_THREADS
#define _H_GENERIC_TYPES_THREADS

#ifdef XENUS_PLATFORM_LINUX_KERNEL
	struct pt_regs;
	typedef struct pt_regs pt_regs_p;
#else
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
#endif
	
typedef struct xenus_attention_trap
{
	uint8_t attention_id;
	pt_regs_p registers; //https://i.kym-cdn.com/entries/icons/original/000/021/311/free.jpg
} * xenus_attention_trap_p, xenus_attention_trap_t;

typedef struct xenus_attention_sys
{
	uint8_t attention_id;
	size_t arg_alpha;
	size_t arg_bravo;
	size_t arg_charlie;
	size_t arg_delta;
	size_t reponse;    
} * xenus_attention_sys_p, xenus_attention_sys_t;

typedef size_t(XENUS_MS_ABI *xenus_sys_cb_t)(xenus_attention_sys_p cbuf);		// GLOBAL
typedef size_t(XENUS_MS_ABI *xenus_trap_cb_t)(xenus_attention_trap_p cbuf);		// PER TASK STRUCT
typedef void (XENUS_MS_ABI *pre_context_switch_cb_t)(void);					    // PER TASK STRUCT
typedef void (XENUS_MS_ABI *post_context_switch_cb_t)(void);					// PER TASK STRUCT
typedef void (XENUS_MS_ABI *thread_exit_cb_t)(void);							// PER TASK STRUCT
	
#if defined(KERNEL) || defined(XENUS_PLATFORM_LINUX_KERNEL)
	typedef void   (XENUS_MS_ABI *xenus_attention_krn_cb_t)(uint8_t, pt_regs_p registers);
	typedef size_t (XENUS_MS_ABI *xenus_attention_usr_cb_t)(uint8_t, size_t arg_alpha, size_t arg_bravo, size_t arg_charlie, size_t arg_delta);

	typedef struct
	{
		union
		{
			void * tls_container;										// XENUS KERNEL <-> XENUS KERNEL
			void * tls_container_generic_a;								// XENUS KERNEL <-> XENUS KERNEL
		};																
															
		void * tls_container_generic_b;									// XENUS KERNEL <-> XENUS KERNEL
		void * tls_container_generic_c;									// XENUS KERNEL <-> XENUS KERNEL
		void * tls_container_xstatic_ip;								// XENUS KERNEL <-> XENUS KERNEL
		void * tls_container_xstatic_global;							// XENUS KERNEL <-> XENUS KERNEL
															
		pre_context_switch_cb_t pub_switch_pre_callback;				// XENUS KERNEL	-> MODULE
		post_context_switch_cb_t pub_switch_post_callback;				// XENUS KERNEL	-> MODULE
															
		pre_context_switch_cb_t  kern_switch_pre_callback;				// LINUX KERNEL -> XENUS KERNEL ||  OPTIONAL: to be called pre-preemption  (a/k/a out)
		post_context_switch_cb_t kern_switch_post_callback;				// LINUX KERNEL -> XENUS KERNEL ||  OPTIONAL: to be called post-preemption (a/k/a in  )

		xenus_attention_krn_cb_t trap_kt_thread_attention_callback;		// TRAP PT -> LINUX KERNEL -> XENUS KERNEL -> fpu enable, pub_ variant, fpu disable
		xenus_attention_krn_cb_t trap_kp_thread_attention_callback;		// TRAP PT -> LINUX KERNEL -> XENUS KERNEL -> fpu enable, pub_ variant, fpu disable

		xenus_attention_trap_t pub_process_thread_attention_callback;   // XENUS KERNEL -> MODULE
		xenus_attention_trap_t pub_task_thread_attention_callback;      // XENUS KERNEL -> MODULE
	
		thread_exit_cb_t kern_thread_exit;								// LINUX KERNEL -> XENUS KERNEL
	
		thread_exit_cb_t pub_thread_exit[5];							// XENUS KERNEL -> MODULE 
	
		uint32_t fpu_enabled_via_hook;									// XENUS KERNEL <-> XENUS KERNEL
		uint32_t fpu_enabled_internal;									// LINUX KERNEL <-> LINUX KERNEL |  are push or pops non-complementory/nested? this isn't that important

		uint64_t future_proofing[10];									//
		uint64_t pub_future_proofing[10];								//
	
		// Do not touch, do not reorder, do not do anything
	} *thread_storage_data_p, thread_storage_data_t;
#endif

#endif // !_H_GENERIC_TYPES_THREADS