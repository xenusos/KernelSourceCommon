#pragma once

XENUS_BEGIN_C
#ifndef MALLOC_PREDEFINED
XENUS_SYM void * malloc(size_t length);
#define MALLOC_PREDEFINED
#endif
XENUS_SYM void free(void * s);
XENUS_SYM void * calloc(size_t num, size_t size);
XENUS_SYM void * realloc(void * buf, size_t length);

XENUS_SYM size_t alloc_actual_size(void * s);
XENUS_SYM size_t alloc_requested_size(void * s);
XENUS_SYM void alloc_dbg_info(void * s);
XENUS_END_C