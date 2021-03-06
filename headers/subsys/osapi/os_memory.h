XENUS_IMPORT l_int zap_vma_ptes(vm_area_struct_k vma, l_unsigned_long address, l_unsigned_long size);
XENUS_IMPORT l_int vm_insert_page(vm_area_struct_k vma, l_unsigned_long addr, page_k page);
XENUS_IMPORT l_int vm_insert_pfn(vm_area_struct_k vma, l_unsigned_long addr, l_unsigned_long pfn);
XENUS_IMPORT l_int vm_insert_pfn_prot(vm_area_struct_k vma, l_unsigned_long addr, l_unsigned_long pfn, pgprot_t pgprot);
XENUS_IMPORT l_int vm_insert_mixed(vm_area_struct_k vma, l_unsigned_long addr, pfn_t pfn);
XENUS_IMPORT l_int vm_insert_mixed_mkwrite(vm_area_struct_k vma, l_unsigned_long addr, pfn_t pfn);
XENUS_IMPORT l_int remap_pfn_range(vm_area_struct_k vma, l_unsigned_long addr, l_unsigned_long pfn, l_unsigned_long size, pgprot_t prot);
XENUS_IMPORT l_int vm_iomap_memory(vm_area_struct_k vma, phys_addr_t start, l_unsigned_long len);
XENUS_IMPORT l_int apply_to_page_range(mm_struct_k mm, l_unsigned_long addr, l_unsigned_long size, pte_fn_t fn, void * data);
XENUS_IMPORT void unmap_mapping_range(address_space_k mapping, loff_t const holebegin, loff_t const holelen, l_int even_cows);
XENUS_IMPORT l_int handle_mm_fault(vm_area_struct_k vma, l_unsigned_long address, l_unsigned_int flags);
XENUS_IMPORT l_int follow_pfn(vm_area_struct_k vma, l_unsigned_long address, l_unsigned_long * pfn);
XENUS_IMPORT l_int generic_access_phys(vm_area_struct_k vma, l_unsigned_long addr, void * buf, l_int len, l_int write);
XENUS_IMPORT l_int access_process_vm(task_k tsk, l_unsigned_long addr, void * buf, l_int len, l_unsigned_int gup_flags);
