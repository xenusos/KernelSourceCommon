/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
    Depends on: xenus.h
*/
#pragma once

#ifdef KERNEL
typedef struct thread_index_counter_s
{
	void * list;
	uint32_t max_threads;
	uint32_t counter;
} *thread_index_counter_p, thread_index_counter_t;
#else
typedef void * thread_index_counter_p;
#endif



#ifdef KERNEL
uint32_t    thread_geti();
#endif

XENUS_SYM void        thread_pause();

// slow 
XENUS_SYM error_t     thread_tls_allocate(uint32_t hash, uint32_t length, void **out);
XENUS_SYM error_t     thread_tls_deallocate(uint32_t hash);
XENUS_SYM error_t     thread_tls_get(uint32_t hash, void ** out);


//fast				  
XENUS_SYM error_t     thread_indexing_create(uint32_t max_threads, thread_index_counter_p * tic);
XENUS_SYM error_t     thread_indexing_destory(thread_index_counter_p tic);
XENUS_SYM error_t     thread_indexing_register(thread_index_counter_p tic);
XENUS_SYM error_t     thread_indexing_get(thread_index_counter_p tic, uint32_t * index);

// thread creation (fpu will be enabled by default)
XENUS_SYM error_t     thread_create(task_k *, thread_callback_t callback, void * data, char * name);

XENUS_SYM error_t     thread_fpu_lock();
XENUS_SYM error_t     thread_fpu_unlock();

// 
XENUS_SYM error_t     thread_pre_context_switch_hook(pre_context_switch_callback_t);
XENUS_SYM error_t     thread_post_context_switch_hook(post_context_switch_callback_t);