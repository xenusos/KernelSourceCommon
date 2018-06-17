/*
    Purpose: general purpose xenus kernel header
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once

#ifdef BOOTSTRAP
	#define XENUS_MS_ABI __attribute__((ms_abi))
	#define XENUS_SYSV_ABI __attribute__((sysv_abi))

	#define XENUS_IMPORT XENUS_MS_ABI
	#define XENUS_EXPORT XENUS_MS_ABI

	#define XENUS_IMPORT_VAR   extern
	#define XENUS_EXPORT_VAR   extern
#elif defined(_MSC_VER) && defined (XENUS_BUILD)
	#define XENUS_SYSV_ABI
	#define XENUS_MS_ABI 

	#define XENUS_IMPORT		XENUS_MS_ABI __declspec(dllimport)
	#define XENUS_EXPORT		XENUS_MS_ABI __declspec(dllexport)

	#define XENUS_IMPORT_VAR	extern __declspec(dllimport) 
	#define XENUS_EXPORT_VAR	extern __declspec(dllexport) 
#endif	

#ifdef KERNEL
    #define XENUS_SYM XENUS_EXPORT 
    #define XENUS_SYM_VAR XENUS_EXPORT_VAR 
#else
    #define XENUS_SYM XENUS_IMPORT
    #define XENUS_SYM_VAR XENUS_IMPORT_VAR 
#endif 

#ifdef __cplusplus
	#define XENUX_BEGIN_C extern "C" {
	#define XENUS_END_C  }
#else
	#define XENUX_BEGIN_C
	#define XENUS_END_C
#endif 

XENUX_BEGIN_C

#include <_/_generic_config.h>

#ifndef BOOTSTRAP
	#include <stdarg.h>							// i don't like doing this, but we have to. MSVC allows us to get away with this. we need _va structs
	#include <_/_xenus_ints.h>					// similar to inttypes.h
	#include <_/_xenus_errors.h>				// error and status codes 
	#include <_/_xenus_types_modules.h>			// entrypoint type, options, etc
	#include <_/_xenus_hash_codes.h>
#endif

#include <_/_generic_types_threads.h>		// thread callback, etc


#ifdef BOOTSTRAP
    #include <_/_linux_all_headers.h>
	#include <_/_linux_linux_types_mapping.h>
#else
	#include <_/_xenus_linux_types_generic.h>
	#include <_/_xenus_linux_types_cpu.h>
	#include <_/_xenus_linux_types_fio.h>
	#include <_/_xenus_linux_types_interrupts.h>
	#include <_/_xenus_linux_types_io.h>
	#include <_/_xenus_linux_types_memory.h>
	#include <_/_xenus_linux_types_pci.h>
	#include <_/_xenus_linux_types_task.h>
	#include <_/_xenus_linux_types_time.h>
	#include <_/_xenus_linux_types_usb.h>	
	#include <_/_xenus_linux_types_fcntl.h>
#endif

#define XENUS_LIBLINUX_SYM extern
#define XENUS_LIBLINUX_SYM_VAR extern

XENUS_END_C

