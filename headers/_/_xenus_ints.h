/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once


// MSVC types to specific standard type names

typedef signed char				int8_t;
typedef unsigned char			uint8_t;

typedef signed  short  int		int16_t;
typedef unsigned short  int		uint16_t;

typedef signed long int 		int32_t;
typedef unsigned long int 		uint32_t;

typedef signed long long int	int64_t;
typedef unsigned long long int  uint64_t;


// More standard int types based around the native machine word size

typedef int64_t 	intptr_t;
typedef uint64_t 	uintptr_t;
typedef int64_t     ptrdiff_t;

typedef int64_t		int_t;
typedef uint64_t 	uint_t;
typedef uint64_t	size_t;
typedef int64_t		ssize_t;


// Errors

typedef int64_t		error_t;


// Address mapping (Move to _xenus_linux_types_xxx?)

typedef void *		phys_addr_t;
typedef void *		dma_addr_t;
typedef void *		user_addr_t;
typedef phys_addr_t	resource_size_t;
typedef phys_addr_t	pci_bus_addr_t;
#define __user /* this is this linux attribute that is used interchangeably with the xenus user_addr_t type*/

// Function pointers to another calling convention (often defined by a differing calling convention)

typedef void *		sysv_fptr_t;


// C boolean logic

#ifndef __cplusplus
	#define bool int
	#define true 1
	#define false 0
#endif


// Word construction

#define HILONG(l)               ((uint32_t)((((uint64_t)(l)) >> 32) & 0xFFFFFFFF))
#define LOLONG(l)               ((uint32_t)(uint64_t)(l))

#define HIWORD(l)               ((uint16_t)((((uint32_t)(l)) >> 16) & 0xFFFF))
#define LOWORD(l)               ((uint16_t)(uint32_t)(l))

#define HIBYTE(w)               ((uint8_t)(((uint16_t)(w) >> 8) & 0xFF))
#define LOBYTE(w)               ((uint8_t)(w))

#define MAKELONGLONG(low,hi)    ((uint64_t)(((uint32_t)(low)) | (((uint64_t)((uint32_t)(hi))) << 32 )))
#define MAKELONG(low,hi)        ((uint32_t)(((uint16_t)(low)) | (((uint32_t)((uint16_t)(hi))) << 16 )))
#define MAKEWORD(low,hi)        ((uint16_t)(((uint8_t) (low)) | (((uint16_t)((uint8_t) (hi))) << 8  )))


// Communism  

#ifndef INT8_MAX
#define INT8_MAX 127
#endif

#ifndef INT8_MIN
#define INT8_MIN (-128)
#endif

#ifndef UINT8_MAX
#define UINT8_MAX 0xFFU
#endif

#ifndef UINT8_MIN
#define UINT8_MIN 0x00U
#endif

#ifndef INT16_MAX
#define INT16_MAX 32767
#endif

#ifndef INT16_MIN
#define INT16_MIN (-32768)
#endif

#ifndef UINT16_MAX
#define UINT16_MAX 0xFFFFU
#endif

#ifndef UINT16_MIN
#define UINT16_MIN 0x0000U
#endif

#ifndef INT32_MAX
#define INT32_MAX 0x7FFFFFFF
#endif

#ifndef INT32_MIN
#define INT32_MIN (-INT32_MAX - 1)
#endif

#ifndef UINT32_MAX
#define UINT32_MAX 0xFFFFFFFFU
#endif

#ifndef UINT32_MIN
#define UINT32_MIN 0x00000000U
#endif

#ifndef INT64_MAX
#define INT64_MAX 0x7FFFFFFFFFFFFFFF
#endif

#ifndef INT64_MIN
#define INT64_MIN (-INT64_MAX - 1)
#endif

#ifndef UINT64_MAX
#define UINT64_MAX 0xFFFFFFFFFFFFFFFFU
#endif

#ifndef UINT64_MIN
#define UINT64_MIN 0x0000000000000000U
#endif
