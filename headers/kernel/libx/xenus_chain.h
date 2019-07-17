/*
    Purpose:
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson (See License.txt)
    Depends: xenus.h
*/
#pragma once

typedef void(*chains_iterator_t)(uint64_t hash, void * buffer, void * ctx);

#ifndef DEFINED_IN_SOURCE_CHAIN
    typedef void(*chains_deallocation_notifier_t)(uint64_t hash, void * buffer);
    typedef void * chain_p;
    typedef void * link_p;
#endif

XENUS_SYM error_t chain_allocate(chain_p * chain);

XENUS_SYM error_t chain_allocate_link(
    chain_p  chain,
    uint64_t hash,                        // REQUIRED: arbitrary hash
    size_t length,                        // REQUIRED: length of the required buffer to allocate 
    chains_deallocation_notifier_t cb,    // OPTIONAL: deallocation notifier 
    link_p * out_link_handle,             // OPTIONAL / OUT: link handle
    void **  out_buffer);                 // OPTIONAL / OUT: requested buffer (REQUIRED / out)

XENUS_EXPORT error_t chain_get(
    chain_p   chain,                      // REQUIRED: link handle to begin searching from
    uint64_t  hash,                       // REQUIRED: hash to search for
    link_p *  out_link_handle,            // OPTIONAL: 
    void **   out_buffer);                // OPTIONAL: 

XENUS_EXPORT error_t chain_iterator(
    chain_p chain,
    chains_iterator_t iterator,
    void * ctx
);

XENUS_SYM error_t chain_deallocate_handle(link_p handle);
XENUS_SYM error_t chain_deallocate_search(chain_p chain, uint64_t hash);
XENUS_SYM error_t chain_destory(chain_p chain);