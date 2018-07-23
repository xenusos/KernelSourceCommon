/*
    Purpose: general purpose xenus kernel header for the bootstrap, linux kernel, xenus kernel, and all subsequent plugins/subsystems
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once
#ifndef _H_XENUS
#define _H_XENUS

#if defined(_KERNEL_MODE)
	#define XENUS_PLATFORM_NT_KERNEL
#elif defined(__KERNEL__)
	#define XENUS_PLATFORM_LINUX_KERNEL
#elif defined(_WIN64) || defined(_WIN32)
	#ifdef XENUS_BUILD
		#define XENUS_PLATFORM_WINDLL_KERNEL
	#else
		#define XENUS_PLATFORM_WIN_USER
	#endif
#endif

#if defined(GPL_MOD)
	#define COMMUNISM_MODE
#endif

#if defined(_MSC_VER)
	#define COMPILER_MSVC
#elif __GNUC__ > 8 || __GNUC__ == 8
	#define COMPILER_GCC8
	#define COMMUNISM_COMPILER
#elif __GNUC__
	#error GCC outdated
#else
	#error Illegal Compiler
#endif

#if !defined(XENUS_BUILD) && defined(COMPILER_MSVC)
	#error "Not an MSVC module."
#endif
#if defined(XENUS_BUILD) && !defined(COMPILER_MSVC)
	#error "Xenus **must** be compiled with MSVC."
#endif

#if defined(XENUS_PLATFORM_WIN_USER)
	#error Header not for usermode components
#endif	

#if defined(COMPILER_GCC8)
	#define XENUS_MS_ABI	__attribute__((ms_abi))
	#define XENUS_SYSV_ABI	__attribute__((sysv_abi))

	#define XENUS_IMPORT XENUS_MS_ABI
	#define XENUS_EXPORT XENUS_MS_ABI
	
	#define XENUS_IMPORT_VAR   extern
	#define XENUS_EXPORT_VAR   extern
#elif defined(COMPILER_MSVC)
	#define XENUS_SYSV_ABI
	#define XENUS_MS_ABI 

	#define XENUS_IMPORT		XENUS_MS_ABI __declspec(dllimport)
	#define XENUS_EXPORT		XENUS_MS_ABI __declspec(dllexport)

	#if defined(__cplusplus)
		#define XENUS_IMPORT_VAR	extern "C" __declspec(dllimport) 
		#define XENUS_EXPORT_VAR	extern "C" __declspec(dllexport) 
	#else
		#define XENUS_IMPORT_VAR	extern __declspec(dllimport) 
		#define XENUS_EXPORT_VAR	extern __declspec(dllexport) 
	#endif 
#endif	

#if defined(KERNEL)
    #define XENUS_SYM XENUS_EXPORT 
    #define XENUS_SYM_VAR XENUS_EXPORT_VAR 
#else
    #define XENUS_SYM XENUS_IMPORT
    #define XENUS_SYM_VAR XENUS_IMPORT_VAR 
#endif 

#if defined(__cplusplus)
	#define XENUS_BEGIN_C extern "C" {
	#define XENUS_END_C   }
#else
	#define XENUS_BEGIN_C
	#define XENUS_END_C
#endif 

XENUS_BEGIN_C

#include "all/_generic_config.h"

#if defined(XENUS_BUILD)
	//#include "stdarg.h"
	#include "all/_xenus_notsostd_arg.h"
	#include "all/_xenus_ints.h"					// similar to inttypes.h
	#include "all/_xenus_errors.h"				// error and status codes 
	#include "all/_xenus_types_modules.h"			// entrypoint type, options, etc
	#include "all/_xenus_hash_codes.h"
#endif

#if defined(XENUS_PLATFORM_LINUX_KERNEL)
	#include <linux/types.h>
#endif

#include "all/_generic_types_threads.h"			// thread callback, etc

#if defined(BOOTSTRAP)
    #include "all/_linux_all_headers.h"
	#include "all/_linux_linux_types_mapping.h"
#endif

#if defined(XENUS_BUILD)
	#include "all/msvc_linux_types/linux_inc.h"
#endif

#if defined(BOOTSTRAP) || defined(KERNEL)
	#include "all/_generic_bootstrap.h"
#endif

// is kernel && forced load
// or is bootstrap
// or is msvc binary AND NOT Kernel.XDLL
#if ((defined(KERNEL) && defined(FORCE_PORTABLE_STRUCTS)) || (defined(BOOTSTRAP)) || (defined(XENUS_BUILD) && !defined(KERNEL)))
	#if defined(KERNEL)
		// BAD - BAD - BAD
		#pragma message("including portable structs header within Kernel.XDLL. This is required, but you shouldn't see this message often assuming nobody fucked up")
		#include "stage2_sys.h" 
		#include "kernel\libx\xenus_memory.h" 
	#elif (defined(XENUS_BUILD) && !defined(KERNEL))
		// BAD - BAD - BAD
		XENUS_IMPORT void * malloc(size_t length);
		XENUS_IMPORT void free(void * s);
		XENUS_IMPORT void *	memcpy(void * dest, const void * src, size_t length);
	#endif
	
	#if ((!defined(PS_IMPORTING)) && (!defined(PS_EXPORTING)))
		#if defined(BOOTSTRAP)
			#define PS_EXPORTING
		#else
			#define PS_IMPORTING
		#endif 
	#endif 
	
	#include "all/_generic_linux_structs.h"
#endif

XENUS_END_C
#endif