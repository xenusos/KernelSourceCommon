XENUS_IMPORT dma_addr_t memex_page_to_phys(page_k page);
XENUS_IMPORT void * memex_page_to_virt(page_k page);
XENUS_IMPORT void memex_get_prot(enum page_cache_mode pcm, pgprot_t * out);
