#pragma once

#undef DEFINE_SYSV_FUNCTON_START
#undef DEFINE_SYSV_FUNCTON_END_DEF
#undef DEFINE_SYSV_FUNCTON_END
#undef SYS_V_GET_DYNAMIC_CALLBACK
#undef SYS_V_GET_DATA
#define DEFINE_SYSV_FUNCTON_START(name, rettype) rettype not_callable_##name(
#define DEFINE_SYSV_FUNCTON_END_DEF(name, rettype) , uint64_t ___magic, void * ____disptr) { if (___magic != 9) panicf("ILLEGAL SYSTEMV FUNCTION CALL - " #name "- CHECK FUNCTION DEFINTION AND PARAMETER COUNT");
#define DEFINE_SYSV_FUNCTON_END }
#define SYS_V_GET_DYNAMIC_CALLBACK ((DynamicCallback *)(____disptr))
#define SYS_V_GET_DATA ((DynamicCallback *)(____disptr))->Data()