XENUS_IMPORT l_int do_mprotect_pkey(task_k task, l_unsigned_long start, size_t len, l_unsigned_long prot, l_int pkey);
XENUS_IMPORT l_int do_pkey_free(task_k task, l_int pkey);
XENUS_IMPORT l_int do_pkey_alloc(task_k task, l_unsigned_long flags, l_unsigned_long init_val);
