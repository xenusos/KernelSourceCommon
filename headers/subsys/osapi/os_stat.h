XENUS_IMPORT void generic_fillattr(inode_k inode, kstat_k stat);
XENUS_IMPORT l_int vfs_getattr_nosec(const path_k path, kstat_k stat, uint32_t request_mask, l_unsigned_int query_flags);
XENUS_IMPORT l_int vfs_getattr(const path_k path, kstat_k stat, uint32_t request_mask, l_unsigned_int query_flags);
XENUS_IMPORT l_int vfs_statx_fd(l_unsigned_int fd, kstat_k stat, uint32_t request_mask, l_unsigned_int query_flags);
XENUS_IMPORT l_int vfs_statx(l_int dfd, user_addr_t filename, l_int flags, kstat_k stat, uint32_t request_mask);
XENUS_IMPORT void __inode_add_bytes(inode_k inode, loff_t bytes);
XENUS_IMPORT void inode_add_bytes(inode_k inode, loff_t bytes);
XENUS_IMPORT void __inode_sub_bytes(inode_k inode, loff_t bytes);
XENUS_IMPORT void inode_sub_bytes(inode_k inode, loff_t bytes);
XENUS_IMPORT loff_t inode_get_bytes(inode_k inode);
XENUS_IMPORT void inode_set_bytes(inode_k inode, loff_t bytes);
