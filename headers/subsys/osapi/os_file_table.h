XENUS_IMPORT l_unsigned_long get_max_files();
XENUS_IMPORT file_k alloc_file(const path_k path, fmode_t mode, const file_operations_k fop);
XENUS_IMPORT void fput(file_k file);
