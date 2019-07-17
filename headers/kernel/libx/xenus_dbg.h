/*
    Purpose:
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson (See License.txt)
    Depends: xenus.h
*/
#pragma once


XENUS_SYM __declspec(noreturn) void  panicf(const char *fmt, ...);
XENUS_SYM l_int printf(const char *fmt, ...);
XENUS_SYM l_int puts(const char * str);

//int atexit(void(*func)(void));
