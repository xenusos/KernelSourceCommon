/*
    Purpose:
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
    Depends: xenus.h, xenus_threading.h
*/
#pragma once

#define SYSV_MAGIC_ALIGNED                                          *(uint64_t*)("URMOMGAY")
#define SYSV_MAGIC_UNALIGNED                                        *(uint64_t*)("URBIGGAY")
#define SYSV_MAGIC SYSV_MAGIC_ALIGNED


#define SYSV_GET_DATA												((uint64_t)____thisptr)
#define SYSV_FN(name)                                               not_callable_##name

#define DEFINE_SYSV_FUNCTON_START(name, rettype)					rettype SYSV_FN(name)(
#define DEFINE_SYSV_FUNCTON_END_DEF(name, rettype)				    void * ____thisptr, uint64_t ___magic) {                                                                        \
                                                                        chkstack_t __n;                                                                                             \
                                                                        bool __mgn_fpu = false;                                                                                     \
                                                                                                                                                                                    \
                                                                        if (((size_t)(&__n) % 16) != 0)                                                                             \
                                                                            panic("Xenus: not aligned " __FUNCTION__);                                                              \
                                                                                                                                                                                    \
                                                                        if ((___magic != SYSV_MAGIC_ALIGNED) && (___magic != SYSV_MAGIC_UNALIGNED))                                 \
                                                                            panicf("ILLEGAL SYSTEMV FUNCTION CALL - " #name " - CHECK FUNCTION DEFINTION AND PARAMETER COUNT. MAGIC: %zx", ___magic);      \
                                                                                                                                                                                    \
                                                                        __mgn_fpu  = thread_fpu_lock();

#define DEFINE_SYSV_END                                               if (__mgn_fpu) thread_fpu_unlock(); }
#define SYSV_FUNCTON_RETURN(r)									    { if (__mgn_fpu) thread_fpu_unlock(); return (r); }


// DEFINE_SYSV_FUNCTON_START(fileio, void *)
//  uint64_t test,
//  uint64_t test2,
// DEFINE_SYSV_FUNCTON_END_DEF(fileio, void *)
// {
// 
// }
// DEFINE_SYSV_END


XENUS_SYM error_t dyncb_allocate_stub	(void * msft, uint8_t parameters, void * data, sysv_fptr_t * sysv, void ** handle); 
XENUS_SYM error_t dyncb_free_stub		(void * handle);

