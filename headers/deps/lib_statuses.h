/*
    Purpose: Dual incremental and decremental enums for defining status codes of positive and negative values (errors being negative, status/info being positive)
    Author: Reece W.
    License: All Rights Reserved (2018)  J. Reece Wilson. Released under the MIT License.
	Note: 
			You may include this header several times
			Define STATUSES_NAME and STATUSES_HEADER before doing so. 
*/

#ifndef __LSTATUSES_DBG_MAP
    #define __LSTATUSES_DBG_MAP
    typedef struct debugging_status_map_s
    {
        const char * c_name;
        const char * cpp_name;
        int64_t code;
    } debugging_status_map_t;
#endif 

#if !defined(STATUSES_NAME) || !defined(STATUSES_HEADER)
	#error Config for lib_statuses not defined!
#endif 

#define __LSTATUSES_C_HACK_A __ ## STATUSES_NAME ## _c_hack_a
#define __LSTATUSES_C_HACK_B __ ## STATUSES_NAME ## _c_hack_b
#define __LSTATUSES_C_HACK_C __ ## STATUSES_NAME ## _null_status

#ifdef __cplusplus 
    const int64_t __LSTATUSES_C_HACK_B = __COUNTER__;
#else 
    enum __LSTATUSES_C_HACK_A { __LSTATUSES_C_HACK_B = __COUNTER__};
#endif

#define _LSTATUSES_NEW_INT          (const int64_t) ((const int64_t) __COUNTER__ - (const int64_t) __LSTATUSES_C_HACK_B)
#define _LSTATUSES_NEXT_INT_AS_POS  _LSTATUSES_NEW_INT
#define _LSTATUSES_NEXT_INT_AS_NEG  0 - _LSTATUSES_NEW_INT

#ifdef __cplusplus 
    #define STATUSES_START \
        enum  : long long  \
        { \
            __LSTATUSES_C_HACK_C = 0,
#else 
    #define STATUSES_START \
        enum STATUSES_NAME ## _codes_e \
        {\
            __LSTATUSES_C_HACK_C = 0,
#endif

#define STATUSES_END };

#define STATUSES_ADD_INFO(convention_c, convention_cpp) \
                          convention_c, /* just let the compiler increment its own internal index counter */ \
                          convention_cpp = convention_c

#define STATUSES_ADD_ERROR(convention_c, convention_cpp)  \
                          convention_c = _LSTATUSES_NEXT_INT_AS_NEG,  \
                          convention_cpp = convention_c
                  
// Debugging
#define STATUSES_DBG_START_EX(name) static const debugging_status_map_t debugging_status_ ## name ## _codes[] = {
#define STATUSES_DBG_START          STATUSES_DBG_START_EX(STATUSES_NAME)
#define STATUSES_DBG_ADD(c, cpp)     { #c, #cpp, c },
#define STATUSES_DBG_END            {0, 0, 0} };

#include STATUSES_HEADER

// Macros for defining statuses
#undef STATUSES_ADD_ERROR
#undef STATUSES_ADD_INFO
#undef STATUSES_START
#undef STATUSES_END

// Macros for debugging statuses
#undef STATUSES_DBG_START
#undef STATUSES_DBG_ADD
#undef STATUSES_DBG_END
#undef STATUSES_DBG_START_EX

// Counters 
#undef _LSTATUSES_NEXT_INT_AS_NEG
#undef _LSTATUSES_NEXT_INT_AS_POS
#undef _LSTATUSES_NEW_INT

// Hacks 
#undef  __LSTATUSES_C_HACK_A
#undef  __LSTATUSES_C_HACK_B
#undef  __LSTATUSES_C_HACK_C

// Should we do this?
// fuck it, they're present, they're going!
#undef STATUSES_NAME
#undef STATUSES_HEADER