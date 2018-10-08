XENUS_IMPORT l_int fixup_user_fault(task_k tsk, mm_struct_k mm, l_unsigned_long address, l_unsigned_int fault_flags, bool * unlocked);
XENUS_IMPORT l_long get_user_pages_locked(l_unsigned_long start, l_unsigned_long nr_pages, l_unsigned_int gup_flags, page_k * pages, l_int * locked);
XENUS_IMPORT l_long get_user_pages_unlocked(l_unsigned_long start, l_unsigned_long nr_pages, page_k * pages, l_unsigned_int gup_flags);
XENUS_IMPORT l_long get_user_pages_remote(task_k tsk, mm_struct_k mm, l_unsigned_long start, l_unsigned_long nr_pages, l_unsigned_int gup_flags, page_k * pages, vm_area_struct_k * vmas, l_int * locked);
XENUS_IMPORT l_long get_user_pages(l_unsigned_long start, l_unsigned_long nr_pages, l_unsigned_int gup_flags, page_k * pages, vm_area_struct_k * vmas);
XENUS_IMPORT l_long get_user_pages_longterm(l_unsigned_long start, l_unsigned_long nr_pages, l_unsigned_int gup_flags, page_k * pages, vm_area_struct_k * vmas_arg);
