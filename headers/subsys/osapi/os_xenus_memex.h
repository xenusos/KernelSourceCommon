XENUS_IMPORT page_k memex_allocate_page(bool allow_high, bool allow_sleep);
XENUS_IMPORT void memex_free_page(page_k page);
XENUS_IMPORT dma_addr_t memex_page_to_phys(page_k page);
XENUS_IMPORT void * memex_page_to_virt(page_k page);
XENUS_IMPORT void * memex_premap(l_int length, void ** handle);
XENUS_IMPORT void * memex_map_pages(page_k * pages, l_int count, pgprot_t prot, void ** handle);
XENUS_IMPORT l_int memex_map_page(void * handle, l_int offset, page_k pge, pgprot_t prot);
XENUS_IMPORT l_int memex_unmap_pages(void * handle);
XENUS_IMPORT void memex_get_prot(enum page_cache_mode pcm, pgprot_t * out);
