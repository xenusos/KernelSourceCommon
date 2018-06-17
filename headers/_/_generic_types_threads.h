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
		void * tls_container;
		void * tls_container_generic_a;
	};
	pre_context_switch_callback_t usr_switch_pre_cb;
	post_context_switch_callback_t usr_switch_post_cb;
	pre_context_switch_callback_t kern_switch_pre_cb;
	post_context_switch_callback_t kern_switch_post_cb;
	uint32_t fpu_enabled_via_hook; 
	uint32_t fpu_enabled_internal;            // +  7
	union
	{
		uint64_t future_proofing[10];         // + 10
		struct
		{
			void * tls_container_generic_b;
			void * tls_container_generic_c;
			void * tls_container_xstatic_ip;
			void * tls_container_xstatic_global;
			
			// 6 * 8 remaining bytes
		};
	};
} *thread_storage_data_p, thread_storage_data_t;

#elif defined(XENUS_BUILD)
	// You do not need these thread_storage_data_p/thread_storage_data_t
typedef int (XENUS_MS_ABI *thread_callback_t)(void * data);
typedef void (XENUS_MS_ABI *pre_context_switch_callback_t)(void);
typedef void (XENUS_MS_ABI *post_context_switch_callback_t)(void);
#else
	// Bootstrap - these types are in sched.h ([...]/sched/core.h)
#endif