/*
    Purpose:
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
	Depends: xenus.h, xenus_threading.h
*/
#pragma once

typedef __declspec(align(16)) struct chkstack_s
{
	uint64_t fuckmedotbat;
} chkstack_t;

#define SYS_V_MAGIC													*(uint64_t*)("URMOMGAY")

#define DEFINE_SYSV_FUNCTON_START(name, rettype)					 rettype not_callable_##name(
#define DEFINE_SYSV_FUNCTON_END_DEF(name, rettype)					uint64_t ___magic, void * ____disptr) { chkstack_t __n; bool __mgn_fpu = false; /* if (((size_t)(&__n) % 16) != 0) panic("Xenus: not aligned " __FUNCTION__);*/ //__mgn_fpu  = thread_fpu_lock();
#define DEFINE_SYSV_FUNCTON_END_DEF_NO_FPU(name, rettype)			uint64_t ___magic, void * ____disptr) { if (___magic != SYS_V_MAGIC) panicf("ILLEGAL SYSTEMV FUNCTION CALL - " #name " - CHECK FUNCTION DEFINTION AND PARAMETER COUNT"); 
#define DEFINE_SYSV_FUNCTON_END										if (__mgn_fpu) thread_fpu_unlock(); }
#define DEFINE_SYSV_FUNCTON_END_NO_FPU								}
#define SYS_V_GET_DATA												((uint64_t)____disptr)

//
// DEFINE_SYSV_FUNCTON_START(fileio, void *)
// uint64_t test,
// uint64_t test2,
// DEFINE_SYSV_FUNCTON_END_DEF(fileio, void *)
// {
// 
// }
// DEFINE_SYSV_FUNCTON_END


XENUS_SYM size_t  dyncb_calc_size		(uint8_t parameters);
XENUS_SYM error_t dyncb_allocate_stub	(void * msft, uint8_t parameters, void * data, sysv_fptr_t * sysv, void ** handle); 
XENUS_SYM error_t dyncb_free_stub		(void * handle);

