/*
    Purpose:
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson (See License.txt)
    Depends: xenus.h
*/
#pragma once

typedef void(*node_iterator_t)(uint64_t hash, void * buffer, void * ctx);

#ifndef DEFINED_IN_SOURCE_BST
    typedef void(*node_deallocation_notifier_t)(uint64_t hash, void * buffer);

    typedef void * bst_p;
    typedef void * node_p;
#endif

XENUS_SYM error_t bst_allocate(bst_p * chain);
XENUS_SYM error_t bst_deallocate_search(bst_p chain, uint64_t hash);
XENUS_SYM error_t bst_destroy(bst_p chain);
XENUS_SYM error_t bst_deallocate_handle(node_p handle);
XENUS_SYM error_t bst_iterator(bst_p chain, node_iterator_t iterator, void * ctx);
XENUS_SYM error_t bst_get(bst_p chain, uint64_t hash,node_p *  out_link_handle, void **   out_buffer);
XENUS_SYM error_t bst_allocate_node(
    bst_p    bst,
    uint64_t hash,
    size_t   length,
    node_deallocation_notifier_t cb,
    node_p * out_link_handle,
    void **  out_buffer);