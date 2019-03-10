/*
    Purpose:
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
    Depends: xenus.h
*/
#pragma once

static inline l_int puts(const char * str)
{
    char msg[STDOUT_BUFFER_LENGTH_W_NULL + 2];
    size_t copy_len;
    copy_len = MIN(strlen(str), STDOUT_BUFFER_LENGTH);
    memcpy(msg, str, copy_len);
    (*(uint16_t*)(((uint64_t)msg) + copy_len)) = *(uint16_t*)("\n\00");
    return print(msg);
}

static inline l_int printf(const char *fmt, ...)
{
    char msg[STDOUT_BUFFER_LENGTH_W_NULL];
    va_list ap;
    msg[0] = 0;
    va_start(ap, fmt);
    vsnprintf(msg, STDOUT_BUFFER_LENGTH_W_NULL, fmt, ap); //TODO check response
    va_end(ap);
    return print(msg);
}

static inline __declspec(noreturn) void  panicf(const char *fmt, ...)
{
    char msg[STDOUT_BUFFER_LENGTH_W_NULL];
    va_list ap;
    msg[0] = 0;
    va_start(ap, fmt);
    vsnprintf(msg, STDOUT_BUFFER_LENGTH_W_NULL, fmt, ap); //TODO check response
    va_end(ap);
    panic(msg);
}

//int atexit(void(*func)(void));
