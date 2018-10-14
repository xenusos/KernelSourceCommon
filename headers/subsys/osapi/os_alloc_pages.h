XENUS_IMPORT void split_page(page_k page, l_unsigned_int order);
XENUS_IMPORT page_k __alloc_pages_nodemask(gfp_t gfp_mask, l_unsigned_int order, l_int preferred_nid, nodemask_t * nodemask);
XENUS_IMPORT l_unsigned_long __get_free_pages(gfp_t gfp_mask, l_unsigned_int order);
XENUS_IMPORT l_unsigned_long get_zeroed_page(gfp_t gfp_mask);
XENUS_IMPORT void __free_pages(page_k page, l_unsigned_int order);
XENUS_IMPORT void free_pages(l_unsigned_long addr, l_unsigned_int order);
XENUS_IMPORT void __page_frag_cache_drain(page_k page, l_unsigned_int count);
XENUS_IMPORT void * page_frag_alloc(page_frag_cache_k nc, l_unsigned_int fragsz, gfp_t gfp_mask);
XENUS_IMPORT void page_frag_free(void * addr);
XENUS_IMPORT void * alloc_pages_exact(size_t size, gfp_t gfp_mask);
XENUS_IMPORT void free_pages_exact(void * virt, size_t size);
XENUS_IMPORT l_unsigned_long nr_free_buffer_pages();
XENUS_IMPORT l_long si_mem_available();
XENUS_IMPORT void si_meminfo(sysinfo_k val);
XENUS_IMPORT void adjust_managed_page_count(page_k page, l_long count);
XENUS_IMPORT l_unsigned_long free_reserved_area(void * start, void * end, l_int poison, char * s);
