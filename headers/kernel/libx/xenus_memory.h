/*
    Purpose:
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
    Depends: xenus.h
*/
#pragma once


XENUS_SYM void alloc_increment_atomicity();
XENUS_SYM void alloc_decrement_atomicity();
XENUS_SYM uint32_t alloc_get_atomicity();

XENUS_SYM size_t alloc_get_kernel_usage();

XENUS_SYM void * malloc_atomic(size_t length);

XENUS_SYM void * malloc(size_t length);
XENUS_SYM void * zalloc(size_t length);
XENUS_SYM void free(void * s);
XENUS_SYM void * calloc(size_t num, size_t size);
XENUS_SYM void * calloc_nozero(size_t num, size_t size);
XENUS_SYM void * realloc(void * buf, size_t length);
XENUS_SYM void * realloc_zero(void * buf, size_t length);

XENUS_SYM size_t alloc_actual_size(void * s);
XENUS_SYM size_t alloc_requested_size(void * s);
XENUS_SYM void alloc_dbg_info(void * s);
