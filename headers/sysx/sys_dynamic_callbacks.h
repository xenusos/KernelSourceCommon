#pragma once

#define SYS_V_MAGIC *(uint64_t*)("URMOMGAY")

#define DEFINE_SYSV_FUNCTON_START(name, rettype)
#define DEFINE_SYSV_FUNCTON_END_DEF(name, rettype)
#define DEFINE_SYSV_FUNCTON_END
#define SYS_V_GET_DYNAMIC_CALLBACK
#define SYS_V_GET_DATA

//
// DEFINE_SYSV_FUNCTON_START(fileio, void *)
// uint64_t test,
// uint64_t test2
// DEFINE_SYSV_FUNCTON_END_DEF(fileio, void *)
// {
// 
// }
// DEFINE_SYSV_FUNCTON_END


XENUS_SYM size_t  dyncb_calc_size		(size_t parameters);
XENUS_SYM error_t dyncb_allocate_stub	(void * msft, size_t parameters, void * data, void ** sysv); // i hate allocating memory in functions. free sysv w/ execfree 



#include "___sys_dynamic_callbacks.h"
