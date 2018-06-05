#pragma once

typedef void(*_pre_chain_dealloc)(void * buffer);

/*
    Double linked list with 64 bit hash | NULL <= x <=> y <=> z <=> a => NULL
    Usage:

    void * basekey;
    void * buffer_hax;
    void * buffer_hax_2;

    chain_allocate(NULL,    0x1337133713371337, 2, &basekey, &buffer_hax);
    chain_allocate(basekey, 0x7331733173317331, 2, NULL, &buffer_hax_2);

    chain_get(basekey, 0x1337133713371337, NULL, &buffer_hax);  //Note: bnext is the entry of the requested hash. use this as the basekey for next chain_get, if searching for duplicates, or if performance tweaking.
    chain_get(basekey, 0x7331733173317331, NULL, &buffer_hax_2);

    etc etc 
*/

XENUS_SYM error_t chain_allocate(void * bk, uint64_t hash, uint32_t length, void ** bkout, void ** out);
XENUS_SYM error_t chain_deallocate_ex(void * bk, uint64_t hash, _pre_chain_dealloc cb);
XENUS_SYM error_t chain_deallocate(void * bk, uint64_t hash);
XENUS_SYM error_t chain_get(void * bk, uint64_t hash, void ** bnext, void ** out);