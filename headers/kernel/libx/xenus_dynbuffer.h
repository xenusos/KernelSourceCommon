/*
    Purpose: Dynamic buffers (this probably wont be used anymore)
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
	Depends: xenus.h
*/
#pragma once

#ifndef KERNEL
typedef void * dynbuffer_p;
#else
typedef struct
{
    uint32_t magic;
    uint_t length;
    void * buffer;
} *dynbuffer_p, dynbuffer_t;
#endif

XENUS_SYM error_t buffer_alloc(uint_t length, dynbuffer_p * outdynbuffer);
XENUS_SYM error_t buffer_free(dynbuffer_p dynbuf);
XENUS_SYM error_t buffer_resize(dynbuffer_p dynbuf, uint_t length);
XENUS_SYM error_t buffer_shrink(dynbuffer_p dynbuf, uint_t subtract);
XENUS_SYM error_t buffer_expand(dynbuffer_p dynbuf, uint_t add);
XENUS_SYM error_t buffer_memcpy(dynbuffer_p dynbuf, uint_t index, void * src, uint_t length);
XENUS_SYM error_t buffer_memset(dynbuffer_p dynbuf, uint_t index, uint8_t c, uint_t length);
XENUS_SYM error_t buffer_fill(dynbuffer_p dynbuf, uint8_t c);
XENUS_SYM error_t buffer_memcmp(dynbuffer_p dynbuf, uint_t index, void * buffer, uint_t length);
XENUS_SYM error_t buffer_slice(dynbuffer_p dynbuf, uint_t start, uint_t end);
XENUS_SYM error_t buffer_copy(dynbuffer_p dynbuf, uint_t index, dynbuffer_p dynsrc, uint_t srcindx, uint_t length);
XENUS_SYM error_t buffer_compare(dynbuffer_p dynbuf, uint_t index, dynbuffer_p dynsrc, uint_t srcindx, uint_t length);
XENUS_SYM error_t buffer_get(dynbuffer_p dynbuf, uint_t index, void * outbuffer, uint_t length);
XENUS_SYM error_t buffer_length(dynbuffer_p dynbuf, int_t * length);
XENUS_SYM error_t buffer_unsafe_get(dynbuffer_p dynbuf, uint8_t ** out);