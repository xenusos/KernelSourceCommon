/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once

typedef signed char				int8_t;
typedef unsigned char			uint8_t;
typedef signed  short  int		int16_t;
typedef unsigned short  int		uint16_t;
typedef signed long int 		int32_t;
typedef unsigned long int 		uint32_t;
typedef signed long long int	int64_t;
typedef unsigned long long int  uint64_t;

typedef int64_t 	intptr_t;
typedef uint64_t 	uintptr_t;

typedef int64_t		int_t;
typedef uint64_t 	uint_t;
typedef uint64_t	size_t;

typedef int64_t		error_t;

typedef void *		physical_address_t;
typedef void *		system_v_function_t;


#define 	INT8_MAX   0x7f
#define 	INT8_MIN   (-INT8_MAX - 1)
#define 	UINT8_MAX   (INT8_MAX * 2 + 1)
#define 	INT16_MAX   0x7fff
#define 	INT16_MIN   (-INT16_MAX - 1)
#define 	UINT16_MAX   (__CONCAT(INT16_MAX, U) * 2U + 1U)
#define 	INT32_MAX   0x7fffffffL
#define 	INT32_MIN   (-INT32_MAX - 1L)
#define 	UINT32_MAX   (__CONCAT(INT32_MAX, U) * 2UL + 1UL)
#define 	INT64_MAX   0x7fffffffffffffffLL
#define 	INT64_MIN   (-INT64_MAX - 1LL)
#define 	UINT64_MAX   (__CONCAT(INT64_MAX, U) * 2ULL + 1ULL)

#define 	INT_LEAST8_MAX   INT8_MAX
#define 	INT_LEAST8_MIN   INT8_MIN
#define 	UINT_LEAST8_MAX   UINT8_MAX
#define 	INT_LEAST16_MAX   INT16_MAX
#define 	INT_LEAST16_MIN   INT16_MIN
#define 	UINT_LEAST16_MAX   UINT16_MAX
#define 	INT_LEAST32_MAX   INT32_MAX
#define 	INT_LEAST32_MIN   INT32_MIN
#define 	UINT_LEAST32_MAX   UINT32_MAX
#define 	INT_LEAST64_MAX   INT64_MAX
#define 	INT_LEAST64_MIN   INT64_MIN
#define 	UINT_LEAST64_MAX   UINT64_MAX

#ifndef CPLUSPLUS
#define bool int
#define true 1
#define false 0
#endif

#define HILONG(l)               ((uint32_t)((((uint64_t)(l)) >> 32) & 0xFFFFFFFF))
#define LOLONG(l)               ((uint32_t)(uint64_t)(l))

#define HIWORD(l)               ((uint16_t)((((uint32_t)(l)) >> 16) & 0xFFFF))
#define LOWORD(l)               ((uint16_t)(uint32_t)(l))

#define HIBYTE(w)               ((uint8_t)(((uint16_t)(w) >> 8) & 0xFF))
#define LOBYTE(w)               ((uint8_t)(w))

#define MAKELONGLONG(low,hi)    ((uint64_t)(((uint32_t)(low)) | (((uint64_t)((uint32_t)(hi))) << 32 )))
#define MAKELONG(low,hi)        ((uint32_t)(((uint16_t)(low)) | (((uint32_t)((uint16_t)(hi))) << 16 )))
#define MAKEWORD(low,hi)        ((uint16_t)(((uint8_t) (low)) | (((uint16_t)((uint8_t) (hi))) << 8  )))