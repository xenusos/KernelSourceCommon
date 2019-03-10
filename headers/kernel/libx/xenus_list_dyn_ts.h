/*
    Purpose: Thread safe dynamic list
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
    Depends on: xenus.h
*/
#pragma once

#ifndef LISTS_MIN_APPEND_SIZE
#define LISTS_MIN_APPEND_SIZE 10
#endif

#ifndef DYN_LIST_CONVERT
#define DYN_LIST_CONVERT(type, name)\
    (type *)(name->buffer)
#endif 

#ifndef DYN_LIST_CREATE
#define DYN_LIST_CREATE(type)\
    _dyn_list_create(sizeof(type))
#endif

#ifndef KERNEL
typedef void * dyn_list_ts_head_p;
#else
typedef struct dyn_list_ts_head_s
{
    uint32_t hash;
    size_t item_sizeof;/* size of the data type*/
    size_t entries;    /* entries in list. items[entries - 1] = last entry */
    size_t item_slots; /* size of buffer = item_slots * item_sizeof        */
    mutex_k mutex;
    bool lock_cache;
    void * buffer;
} *dyn_list_ts_head_p, dyn_list_ts_head_t;
#endif


// ADDITIONAL THREAD SAFETY 
XENUS_SYM error_t dyn_list_ts_lock(dyn_list_ts_head_p head);   // wrap an entire scope around these for a) extra performance and b) to ensure that no other thread can access the list. 
XENUS_SYM error_t dyn_list_ts_unlock(dyn_list_ts_head_p head); // wrap an entire scope around these for a) extra performance and b) to ensure that no other thread can access the list. 

// GET PROPERTIES 
XENUS_SYM error_t dyn_list_ts_entries(dyn_list_ts_head_p head, size_t * out_size);

// SET PROPERTIES

// SEARCHING
XENUS_SYM error_t dyn_list_ts_get_by_index(dyn_list_ts_head_p head, size_t index, void ** entry);

// APPENDING AND PREPENDING
XENUS_SYM error_t dyn_list_ts_append(dyn_list_ts_head_p head, void ** out);
XENUS_SYM error_t dyn_list_ts_preappend(dyn_list_ts_head_p head, void ** entry);

// ADD/REMOVE AT INDEX
XENUS_SYM error_t dyn_list_ts_slice(dyn_list_ts_head_p head, size_t index, size_t cnt);
XENUS_SYM error_t dyn_list_ts_splice(dyn_list_ts_head_p head, size_t index, void ** new_entity);
XENUS_SYM error_t dyn_list_ts_remove(dyn_list_ts_head_p head, size_t index);

// DESTRUCTION
XENUS_SYM error_t dyn_list_ts_destory(dyn_list_ts_head_p head);
// INTERNAL CONSTRUCTOR 
XENUS_SYM dyn_list_ts_head_p _dyn_list_ts_create(size_t length);