/*
    Purpose:
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson (See License.txt)
    Depends: xenus.h
*/
#pragma once

XENUS_SYM_VAR unsigned char _ctype[];

// String formatting:
XENUS_SYM size_t vsnprintf(char *buf, size_t size, const char *fmt, va_list ap);
XENUS_SYM size_t vsprintf(char *buf, const char *fmt, va_list ap);

static inline size_t snprintf(char *buf, size_t size, const char *fmt, ...)
{
    va_list ap;
    size_t retval;

    va_start(ap, fmt);
    retval = vsnprintf(buf, size, fmt, ap);
    va_end(ap);
    return retval;
}

#define __U    0x01    /* upper */
#define __L    0x02    /* lower */
#define __D    0x04    /* digit */
#define __C    0x08    /* cntrl */
#define __P    0x10    /* punct */
#define __S    0x20    /* white space (space/lf/tab) */
#define __X    0x40    /* hex digit */
#define __SP   0x80    /* hard space (0x20) */

#define __ismask(x) (_ctype[(int)(unsigned char)(x)])

#define isalnum(c)    ((__ismask(c)&(__U|__L|__D)) != 0)
#define isalpha(c)    ((__ismask(c)&(__U|__L)) != 0)
#define iscntrl(c)    ((__ismask(c)&(__C)) != 0)
#define isdigit(c)    ((__ismask(c)&(__D)) != 0)
#define isgraph(c)    ((__ismask(c)&(__P|__U|__L|__D)) != 0)
#define islower(c)    ((__ismask(c)&(__L)) != 0)
#define isprint(c)    ((__ismask(c)&(__P|__U|__L|__D|__SP)) != 0)
#define ispunct(c)    ((__ismask(c)&(__P)) != 0)
/* Note: isspace() must return false for %NUL-terminator */
#define isspace(c)    ((__ismask(c)&(__S)) != 0)
#define isupper(c)    ((__ismask(c)&(__U)) != 0)
#define isxdigit(c)   ((__ismask(c)&(__D|__X)) != 0)

#define isascii(c) (((unsigned char)(c))<=0x7f)
#define toascii(c) (((unsigned char)(c))&0x7f)

static inline unsigned char __tolower(unsigned char c)
{
    if (isupper(c))
        c -= 'A'-'a';
    return c;
}

static inline unsigned char __toupper(unsigned char c)
{
    if (islower(c))
        c -= 'a'-'A';
    return c;
}

#define tolower(c) __tolower(c)
#define toupper(c) __toupper(c)