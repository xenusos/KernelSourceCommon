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
	uint_t max_threads;
	uint32_t counter;
	mutex_k mutex;
} * thread_index_counter_p, * thread_index_counter_ref, thread_index_counter_t;
#else
typedef void * thread_index_counter_p;
#endif

#ifdef KERNEL
thread_storage_data_p	thread_nopreempt_get_tls();
void					thread_nopreempt_put_tls(thread_storage_data_p tls);
#endif

XENUS_SYM uint32_t    thread_geti();


static uint64_t TLS_TYPE_GENERIC	= 0;
static uint64_t TLS_TYPE_GENERIC_1	= 0;
static uint64_t TLS_TYPE_GENERIC_2	= 1;
static uint64_t TLS_TYPE_GENERIC_3	= 2;
static uint64_t TLS_TYPE_XIP		= 3;        // INTERNAL LIB LINUX THING - DO NOT USE THIS!
static uint64_t TLS_TYPE_XGLOBAL	= 4;        // INTERNAL LIB LINUX THING - DO NOT USE THIS!
#define TLS_MAX_TYPE TLS_TYPE_XGLOBAL

XENUS_SYM void        thread_pause();

XENUS_SYM error_t     _thread_tls_allocate(uint64_t type, uint64_t hash, size_t length, void ** out_handle, void ** out_buffer);
XENUS_SYM error_t     _thread_tls_deallocate_hash(uint64_t type, uint64_t hash);
XENUS_SYM error_t     _thread_tls_deallocate_handle(void * handle);
XENUS_SYM error_t     _thread_tls_get(uint64_t type, uint64_t hash, void ** out_handle, void ** out_buffer);

#ifdef KERNEL
error_t     _thread_tls_cleanup(uint64_t type);
error_t     _thread_tls_cleanup_all();
#endif

error_t inline thread_tls_allocate(uint64_t hash, size_t length, void ** out_handle, void ** out_buffer){	return _thread_tls_allocate(TLS_TYPE_GENERIC, hash, length, out_handle, out_buffer);}
error_t inline thread_tls_get(uint64_t type, uint64_t hash, void ** out_handle, void ** out_buffer)		{	return _thread_tls_get(TLS_TYPE_GENERIC, hash, out_handle, out_buffer);}
error_t inline thread_tls_deallocate_hash(uint64_t hash)												{	return _thread_tls_deallocate_hash(TLS_TYPE_GENERIC, hash); }
error_t inline thread_tls_deallocate_handle(void * handle)												{	return _thread_tls_deallocate_handle(handle); }

XENUS_SYM error_t	thread_indexing_create(uint_t max_threads, thread_index_counter_p * tic);
XENUS_SYM error_t	thread_indexing_destory(thread_index_counter_p tic);
XENUS_SYM error_t	thread_indexing_register(thread_index_counter_p tic);
XENUS_SYM error_t	thread_indexing_get(thread_index_counter_p tic, size_t * index);

// utils
XENUS_SYM void		thread_preempt_lock();	// preemption stuff
XENUS_SYM void		thread_preempt_unlock(); // preemption stuff

// thread creation (fpu will be enabled by default)
XENUS_SYM error_t	thread_create(task_k *, thread_callback_t callback, void * data, const  char * name, bool run);


// lock fpu down - to be used in callbacks only - unless you know what you're doing.  
XENUS_SYM bool thread_fpu_lock();
XENUS_SYM bool thread_fpu_unlock();

// 
XENUS_SYM void thread_pre_context_switch_hook(pre_context_switch_cb_t);      //
XENUS_SYM void thread_post_context_switch_hook(post_context_switch_cb_t);

XENUS_SYM void threading_set_current_trap_handler(xenus_trap_cb_t handler);  // int 15, 0xID
XENUS_SYM void threading_set_process_trap_handler(xenus_trap_cb_t handler);  // 

XENUS_SYM void threading_set_current_syscall_handler(xenus_sys_cb_t handler);
XENUS_SYM void threading_set_process_syscall_handler(xenus_sys_cb_t handler);

XENUS_SYM error_t threading_get_exit_callbacks(thread_exit_cb_t ** list, int * cnt);

typedef void(*thread_exit_hack_t)(long code);
XENUS_SYM error_t threading_ntfy_singleshot_exit(uint32_t pid, thread_exit_hack_t cb);

#ifdef KERNEL
void thread_enable_cleanup();
#endif