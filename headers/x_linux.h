#pragma once

XENUX_BEGIN_C

#if !defined(PS_IMPORTING) && !defined(PS_EXPORTING)
	#ifdef KERNEL
		#define PS_IMPORTING
	#else
		#define PS_EXPORTING
	#endif 
#endif 

#include <_/_generic_linux_structs.h>

XENUS_END_C