/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
    Depends on: xenus.h
*/
#pragma once

// VM ALLOC w/ exec
XENUS_IMPORT void * execalloc(size_t length);
XENUS_IMPORT void   execfree(void * ptr);

// generic linux kernel allocation functions
XENUS_IMPORT void * kmalloc(size_t length, size_t flags);
XENUS_IMPORT void * vmalloc(size_t length);
XENUS_IMPORT void   kfree(void * ptr);
XENUS_IMPORT void   vfree(void * ptr);

//generic functions
XENUS_IMPORT void *	memcpy(void * dest, const void * src, size_t length);
XENUS_IMPORT void *	memset(void * dest, int c, size_t length);
XENUS_IMPORT void *	memmove(void *dest, const void *src, size_t count);
XENUS_IMPORT int	memcmp(const void *cs, const void *ct, size_t count);
XENUS_IMPORT void *	memscan(void *addr, l_int c, size_t size);

