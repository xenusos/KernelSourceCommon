/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once

#ifdef KERNEL
typedef int (XENUS_MS_ABI *thread_callback_t)(void * data);
typedef void (XENUS_MS_ABI *pre_context_switch_callback_t)(void);
typedef void (XENUS_MS_ABI *post_context_switch_callback_t)(void);

typedef struct
{
	union
	{
		void * tls_container;							// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
		void * tls_container_generic_a;					// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
	};													   
	pre_context_switch_callback_t usr_switch_pre_cb;    // (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
	post_context_switch_callback_t usr_switch_post_cb;  // (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
	pre_context_switch_callback_t kern_switch_pre_cb;   // OPTIONAL: to be called pre-preemption  (a/k/a out)
	post_context_switch_callback_t kern_switch_post_cb; // OPTIONAL: to be called post-preemption (a/k/a in )
	uint32_t fpu_enabled_via_hook; 						// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
	uint32_t fpu_enabled_internal;            // +  7	// OPT IMPL: to be used within the linux kernel for debugging begin/end fpu calls (are they nested? are push or pops non-complementory?) - this isn't that important
	union
	{
		uint64_t future_proofing[10];         // + 10
		struct
		{
			void * tls_container_generic_b;				// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
			void * tls_container_generic_c;				// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
			void * tls_container_xstatic_ip;			// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
			void * tls_container_xstatic_global;		// (LINUX KERNEL - do not fucking touch... XENUS KERNEL ONLY)
			
			// 6 * 8 remaining bytes
		};
	};

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