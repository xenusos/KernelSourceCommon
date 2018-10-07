XENUS_IMPORT void * kmap(page_k page);
XENUS_IMPORT void kunmap(page_k page);
XENUS_IMPORT void * kmap_atomic(page_k page);
XENUS_IMPORT void * kmap_atomic_pfn(l_unsigned_long pfn);
XENUS_IMPORT void __kunmap_atomic(void * kvaddr);
XENUS_IMPORT page_k kmap_atomic_to_page(void * ptr);
