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
	void * tls_container;
	pre_context_switch_callback_t usr_switch_pre_cb;
	post_context_switch_callback_t usr_switch_post_cb;
	pre_context_switch_callback_t kern_switch_pre_cb;
	post_context_switch_callback_t kern_switch_post_cb;
	uint32_t fpu_enabled_via_hook; 
	uint32_t fpu_enabled_internal; // +  7
	uint64_t data[10];        // + 10
} *thread_storage_data_p, thread_storage_data_t;

#elif defined(XENUS_BUILD)
	// You do not need these structs
typedef int (XENUS_MS_ABI *thread_callback_t)(void * data);
typedef void (XENUS_MS_ABI *pre_context_switch_callback_t)(void);
typedef void (XENUS_MS_ABI *post_context_switch_callback_t)(void);
#else
	// Bootstrap - these types are in sched.h (.../sched/core.h)
#endif