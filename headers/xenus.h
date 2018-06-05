/*
    Purpose: general purpose xenus kernel header (fundamental and important types)
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once

#ifdef __GNUC__
#define XENUS_MS_ABI __attribute__((ms_abi))
#define XENUS_SYSV_ABI __attribute__((sysv_abi ))
	#define XENUS_IMPORT XENUS_MS_ABI
	#define XENUS_EXPORT XENUS_MS_ABI
	#define XENUS_IMPORT_VAR 
	#define XENUS_EXPORT_VAR 
#elif defined(_MSC_VER) && defined (XENUS_BUILD)
	#define XENUS_SYSV_ABI
	#define XENUS_MS_ABI 
	#define XENUS_IMPORT		XENUS_MS_ABI __declspec(dllimport)
	#define XENUS_EXPORT		XENUS_MS_ABI __declspec(dllexport)
	#define XENUS_IMPORT_VAR	extern __declspec(dllimport) 
	#define XENUS_EXPORT_VAR	extern __declspec(dllexport) 
#else
	// VISUAL STUDIO BUG:
	#define XENUS_IMPORT  XENUS_MS_ABI __declspec(dllimport)
	#define XENUS_EXPORT  XENUS_MS_ABI __declspec(dllexport)
	//#error Illegal build environment. Compiling user mode plugin with a kernel header?
#endif	

#ifdef KERNEL
    #define XENUS_SYM XENUS_EXPORT 
    #define XENUS_SYM_VAR XENUS_EXPORT_VAR 
#else
    #define XENUS_SYM XENUS_IMPORT
    #define XENUS_SYM_VAR XENUS_IMPORT_VAR 
#endif 

#ifdef __cplusplus
	#define XENUS_BEGIN_C extern "C" {
	#define XENUS_END_C  }
#else
	#define XENUS_BEGIN_C
	#define XENUS_END_C
#endif 

#include <stdarg.h>							// i don't like doing this, but we have to. MSVC allows us to get away with this. we need _va tuff
#include <_\_xenus_ints.h>					// similar to inttypes.h
#include <_\_xenus_errors.h>					// error and status codes 

#include <_\_xenus_types_threads.h>			// thread callback, etc
#include <_\_xenus_types_modules.h>			// entrypoint type, options, etc


#ifdef __GNUC__
	#include <_\_linux_linux_types_mapping.h>
#else
	#include <_\_xenus_linux_types_generic.h>
#endif
//#include "_xenus_linux_types_time.h"
//#include "_xenus_linux_types_task.h"
//#include "_xenus_linux_types_memory.h"
//#include "_xenus_linux_types_usb.h"
//#include "_xenus_linux_types_pci.h"

#include <_\_xenus_linux_structs.h>

static void volatile hackerz()
{
    // volatile const char * a = "read me | xref me | Encryption http password https tor .onion file network microsoft linux hackers hack registry malloc alloc mem";
    // volatile const char * b = "read me | xref me | encrypt libtomcrypt openssl ssl tls .com .org wddm ddm xdll dll dump win win32 windows";
    // volatile const char * c = "read me | xref me | chrome pipe DMA pci sock sockets FILE";
    // volatile const char * d = "now i've got your attention, xref this particular stub for intersting locations!";
}