XENUS_IMPORT loff_t vfs_setpos(file_k file, loff_t offset, loff_t maxsize);
XENUS_IMPORT loff_t generic_file_llseek_size(file_k file, loff_t offset, l_int whence, loff_t maxsize, loff_t eof);
XENUS_IMPORT loff_t generic_file_llseek(file_k file, loff_t offset, l_int whence);
XENUS_IMPORT loff_t fixed_size_llseek(file_k file, loff_t offset, l_int whence, loff_t size);
XENUS_IMPORT loff_t no_seek_end_llseek(file_k file, loff_t offset, l_int whence);
XENUS_IMPORT loff_t no_seek_end_llseek_size(file_k file, loff_t offset, l_int whence, loff_t size);
XENUS_IMPORT loff_t noop_llseek(file_k file, loff_t offset, l_int whence);
XENUS_IMPORT loff_t no_llseek(file_k file, loff_t offset, l_int whence);
XENUS_IMPORT loff_t default_llseek(file_k file, loff_t offset, l_int whence);
XENUS_IMPORT loff_t vfs_llseek(file_k file, loff_t offset, l_int whence);
XENUS_IMPORT ssize_t kernel_read(file_k file, void * buf, size_t count, loff_t * pos);
XENUS_IMPORT ssize_t __kernel_write(file_k file, const void * buf, size_t count, loff_t * pos);
XENUS_IMPORT ssize_t kernel_write(file_k file, const void * buf, size_t count, loff_t * pos);
XENUS_IMPORT ssize_t vfs_iter_read(file_k file, iov_iter_k iter, loff_t * ppos, rwf_t flags);
XENUS_IMPORT ssize_t vfs_iter_write(file_k file, iov_iter_k iter, loff_t * ppos, rwf_t flags);
