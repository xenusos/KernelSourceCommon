/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
    Depends on: xenus.h, (if older build, xenus_memory.h)
*/
#pragma once

XENUX_BEGIN_C

// String formatting:
XENUS_IMPORT size_t vsnprintf(char *buf, size_t size, const char *fmt, va_list ap);
XENUS_IMPORT size_t vsprintf(char *buf, const char *fmt, va_list ap);

// String utils:
XENUS_IMPORT char * strcat(char * x, const char * y);
XENUS_IMPORT int 	strcasecmp(const char *s1, const char *s2);
XENUS_IMPORT int 	strncasecmp(const char *s1, const char *s2, size_t n);
XENUS_IMPORT char *	strncpy(char *dest, const char *src, size_t count);
XENUS_IMPORT size_t strlcpy(char *dest, const char *src, size_t size);
XENUS_IMPORT char *	strncat(char *dest, const char *src, size_t count);
XENUS_IMPORT size_t strlcat(char *dest, const char *src, size_t count);
XENUS_IMPORT int 	strcmp(const char * x, const char * y);
XENUS_IMPORT int    strrchr(const char *s, int c);
XENUS_IMPORT int 	strncmp(const char *cs, const char *ct, size_t count);
XENUS_IMPORT char *	strchr(const char *s, int c);
XENUS_IMPORT char *	strnchr(const char *s, size_t count, int c);
XENUS_IMPORT char *	skip_spaces(const char *str);
XENUS_IMPORT char *	strim(char *s);
XENUS_IMPORT size_t strlen(const char * source); //WDM hacks should ret int
XENUS_IMPORT size_t strnlen(const char *s, size_t count);
XENUS_IMPORT size_t	strspn(const char *s, const char *accept);
XENUS_IMPORT size_t strcspn(const char *s, const char *reject);
XENUS_IMPORT char *	strpbrk(const char *cs, const char *ct);
XENUS_IMPORT char *	strsep(char **s, const char *ct);
XENUS_IMPORT bool 	sysfs_streq(const char *s1, const char *s2);
XENUS_IMPORT int 	strtobool(const char *s, bool *res);
XENUS_IMPORT char *	strstr(const char *s1, const char *s2);
XENUS_IMPORT char *	strnstr(const char *s1, const char *s2, size_t len);
XENUS_IMPORT char * strcpy(char * destination, const char * source);

#include "___sys_strings.h"


static inline size_t snprintf(char *buf, size_t size, const char *fmt, ...)
{
    va_list ap;
    size_t retval;
    
    va_start(ap, fmt);
    retval = vsnprintf(buf, size, fmt, ap);
    va_end(ap);
    return retval;
}

static size_t sprintf(char *buf, const char *fmt, ...)
{
    va_list ap;
    size_t retval;
    
    va_start(ap, fmt);
    retval = vsprintf(buf, fmt, ap);
    va_end(ap);
    return retval;
}

XENUS_END_C