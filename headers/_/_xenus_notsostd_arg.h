/*
    Purpose: Unfuck stdarg.h
    Author : Microsoft Corporation, Reece Wilson
    License: NaN - Public Domain
			 Insufficient work to warrent protection; arbitrary strings and symbols do not warrent protection under respective laws due to the inherently public nature of the primative abstract concepts at play and simplicity
*/
#pragma once
#pragma pack(push,8)

typedef char* va_list;
void __cdecl __va_start(va_list*, ...);

#define __crt_va_start_a(ap, x) ((void)(__va_start(&ap, x)))

#if defined(__cplusplus)
	extern "C++"
	{
		template <typename _Ty>
		struct __vcrt_va_list_is_reference
		{
			enum : bool { __the_value = false };
		};
	
		template <typename _Ty>
		struct __vcrt_va_list_is_reference<_Ty&>
		{
			enum : bool { __the_value = true };
		};
	
		template <typename _Ty>
		struct __vcrt_va_list_is_reference<_Ty&&>
		{
			enum : bool { __the_value = true };
		};
	
		template <typename _Ty>
		void __vcrt_va_start_verify_argument_type() throw()
		{
			static_assert(!__vcrt_va_list_is_reference<_Ty>::__the_value, "va_start argument must not have reference type and must not be parenthesized");
		}
	} 
	#define va_start(ap, x) ((void)(__vcrt_va_start_verify_argument_type<decltype(x)>(), __crt_va_start_a(ap, x)))
#else 
	#define va_start(ap, x) __crt_va_start_a(ap, x)
#endif

#define va_arg(ap, t)																					\
								((sizeof(t) > sizeof(__int64) || (sizeof(t) & (sizeof(t) - 1) ) != 0)	\
							    ? **(t **)((ap += sizeof(__int64)) - sizeof(__int64))					\
							    :  *(t  *)((ap += sizeof(__int64)) - sizeof(__int64)))
#define va_end(ap)      ( ap = (va_list)0 )

#pragma pack(pop)