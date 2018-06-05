/*
    Purpose: Aids in reading Linux types that we can't port to MSVC 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
    Depends on: xenus.h, xenus_string.h (xenus_memory.h on older builds)
*/
#pragma once

#if !defined(PS_IMPORTING) && !defined(PS_EXPORTING)
	#ifdef KERNEL
		#define PS_IMPORTING
	#else
		#define PS_EXPORTING
	#endif 
#endif 

#include <lib_port_structs.h>

PS_HEADER_GLOBAL_START
	//PS_HEADER_TYPE_START
	//	PS_HEADER_MEMBER(x)
	//	PS_HEADER_MEMBER(y)
	//	PS_HEADER_MEMBER(z)
	//PS_HEADER_TYPE_END(struct lengthy_struct, lengthy_struct)
	//PS_HEADER_TYPE_START
	//	PS_HEADER_MEMBER(x)
	//	PS_HEADER_MEMBER(y)
	//	PS_HEADER_MEMBER(z)
	//PS_HEADER_TYPE_END(struct lengthy_struct, lengthy_struct)
	int x;
PS_HEADER_GLOBAL_END

//PS_HEADER_INIT_TYPE(lengthy_struct)
//PS_HEADER_INIT_MEMBER(struct lengthy_struct, lengthy_struct, x)
//PS_HEADER_INIT_MEMBER(struct lengthy_struct, lengthy_struct, y)
//PS_HEADER_INIT_MEMBER(struct lengthy_struct, lengthy_struct, z)


