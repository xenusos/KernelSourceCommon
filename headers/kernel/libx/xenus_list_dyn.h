/*
    Purpose: Dynamic list
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
    Depends on: xenus.h
*/
#pragma once


#ifndef DYN_LIST_CONVERT
#define DYN_LIST_CONVERT(type, name)\
    (type *)(name->buffer)
#endif 

#ifndef DYN_LIST_CREATE
#define DYN_LIST_CREATE(type)\
    _dyn_list_create(sizeof(type))
#endif

#ifndef KERNEL
typedef void * dyn_list_head_p;
#else
typedef struct dyn_list_head_s
{
	uint32_t hash;
    size_t item_sizeof;/* size of the data type*/
    size_t entries;    /* entries in list. items[entries - 1] = last entry */
    size_t item_slots; /* size of buffer = item_slots * item_sizeof        */
    void * buffer;
} *dyn_list_head_p, dyn_list_head_t;
#endif

XENUS_SYM dyn_list_head_p _dyn_list_create(size_t length);
XENUS_SYM error_t dyn_list_entries(dyn_list_head_p head, size_t * out_size);
XENUS_SYM error_t dyn_list_append(dyn_list_head_p head, void ** out);                            // O(1)
XENUS_SYM error_t dyn_list_append_ex(dyn_list_head_p head, void ** out, size_t * idx);           // O(1)
XENUS_SYM error_t dyn_list_get_by_index(dyn_list_head_p head, size_t index, void ** entry);      // O(1) *
XENUS_SYM error_t dyn_list_get_by_buffer(dyn_list_head_p head, void * entry, size_t * index);    // O(n)   | returns XENUS_STATUS_LISTS_FOUND, or XENUS_STATUS_LISTS_NOT_FOUND. XENUS_STATUS_LISTS_NOT_FOUND IS NOT AN ERROR! use STRICTLY_OKAY(code = dyn_list_get_by_buffer(...))
XENUS_SYM error_t dyn_list_slice(dyn_list_head_p head, size_t index, size_t cnt);                // O(1)
XENUS_SYM error_t dyn_list_splice(dyn_list_head_p head, size_t index, void ** new_entity);       // O(1) *
XENUS_SYM error_t dyn_list_preappend(dyn_list_head_p head, void ** entry);                       // O(1) 
XENUS_SYM error_t dyn_list_remove(dyn_list_head_p head, size_t index);                           // O(1)  
XENUS_SYM error_t dyn_list_destory(dyn_list_head_p head);
XENUS_SYM error_t dyn_list_iterate(dyn_list_head_p head, void(*iterator)(void * buffer, void * ctx), void * ctx);
XENUS_SYM error_t dyn_list_reset(dyn_list_head_p head);


// * assuming relocation time is constant and/or other memory operations aren't required (ie: resize)