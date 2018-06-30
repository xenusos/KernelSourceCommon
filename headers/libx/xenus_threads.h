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
	mutex_k mutex;
} *thread_index_counter_p, thread_index_counter_t;
#else
typedef void * thread_index_counter_p;
#endif

#ifdef KERNEL
thread_storage_data_p	thread_nopreempt_get_tls();
void					thread_nopreempt_put_tls(thread_storage_data_p tls);
uint32_t    thread_geti();
#endif


static uint64_t TLS_TYPE_GENERIC	= 0;
static uint64_t TLS_TYPE_GENERIC_1	= 0;
static uint64_t TLS_TYPE_GENERIC_2	= 1;
static uint64_t TLS_TYPE_GENERIC_3	= 2;
static uint64_t TLS_TYPE_XIP		= 3;        // INTERNAL LIB LINUX THING - DO NOT USE THIS!
static uint64_t TLS_TYPE_XGLOBAL	= 4;        // INTERNAL LIB LINUX THING - DO NOT USE THIS!

XENUS_SYM void        thread_pause();

XENUS_SYM error_t     _thread_tls_allocate(uint64_t type, uint64_t hash, size_t length, void **out);
XENUS_SYM error_t     _thread_tls_get(uint64_t type, uint64_t hash, void ** out);
XENUS_SYM error_t     _thread_tls_deallocate(uint64_t type, uint64_t hash);

error_t inline thread_tls_allocate(uint64_t hash, size_t length, void **out)	{	return _thread_tls_allocate(TLS_TYPE_GENERIC, hash, length, out);}
error_t inline thread_tls_get(uint64_t hash, void ** out)						{	return _thread_tls_get(TLS_TYPE_GENERIC, hash, out);}
error_t inline thread_tls_deallocate(uint64_t hash) { return _thread_tls_deallocate(TLS_TYPE_GENERIC, hash); }
//TODO: we need a way to clean up task structs!!!

//fast				  
XENUS_SYM error_t     thread_indexing_create(uint32_t max_threads, thread_index_counter_p * tic);
XENUS_SYM error_t     thread_indexing_destory(thread_index_counter_p tic);
XENUS_SYM error_t     thread_indexing_register(thread_index_counter_p tic);
XENUS_SYM error_t     thread_indexing_get(thread_index_counter_p tic, uint32_t * index);


// utils
XENUS_SYM void thread_tls_lock();	// preemption stuff
XENUS_SYM void thread_tls_unlock(); // preemption stuff

// thread creation (fpu will be enabled by default)
XENUS_SYM error_t     thread_create(task_k *, thread_callback_t callback, void * data, char * name);

XENUS_SYM error_t     thread_fpu_lock();
XENUS_SYM error_t     thread_fpu_unlock();

// 
XENUS_SYM error_t     thread_pre_context_switch_hook(pre_context_switch_callback_t);
XENUS_SYM error_t     thread_post_context_switch_hook(post_context_switch_callback_t);