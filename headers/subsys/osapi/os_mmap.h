XENUS_IMPORT pgprot_t vm_get_page_prot(l_unsigned_long vm_flags);
XENUS_IMPORT l_unsigned_long get_unmapped_area(file_k file, l_unsigned_long addr, l_unsigned_long len, l_unsigned_long pgoff, l_unsigned_long flags);
XENUS_IMPORT vm_area_struct_k find_vma(mm_struct_k mm, l_unsigned_long addr);
XENUS_IMPORT vm_area_struct_k find_extend_vma(mm_struct_k mm, l_unsigned_long addr);
XENUS_IMPORT l_int vm_munmap(l_unsigned_long start, size_t len);
XENUS_IMPORT l_int vm_brk_flags(l_unsigned_long addr, l_unsigned_long len, l_unsigned_long flags);
XENUS_IMPORT l_int vm_brk(l_unsigned_long addr, l_unsigned_long len);
XENUS_IMPORT l_unsigned_long unmapped_area(vm_unmapped_area_info_k info);
