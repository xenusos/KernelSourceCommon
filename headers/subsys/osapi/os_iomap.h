XENUS_IMPORT void * ioremap_nocache(resource_size_t phys_addr, l_unsigned_long size);
XENUS_IMPORT void * ioremap_uc(resource_size_t phys_addr, l_unsigned_long size);
XENUS_IMPORT void * ioremap_wc(resource_size_t phys_addr, l_unsigned_long size);
XENUS_IMPORT void * ioremap_wt(resource_size_t phys_addr, l_unsigned_long size);
XENUS_IMPORT void * ioremap_cache(resource_size_t phys_addr, l_unsigned_long size);
XENUS_IMPORT void * ioremap_prot(resource_size_t phys_addr, l_unsigned_long size, l_unsigned_long prot_val);
XENUS_IMPORT void iounmap(void * addr);
