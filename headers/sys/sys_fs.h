#pragma once

typedef void * fl_owner_t; //legacy typedef, should be nulled // /* legacy typedef, should eventually be removed */ - Linux Kernel source

// open
XENUS_IMPORT long vfs_truncate(path_k path, loff_t length);
XENUS_IMPORT int vfs_fallocate(file_k file, int mode, loff_t offset, loff_t len);
XENUS_IMPORT int finish_open(file_k file, dentry_k dentry, void * sys_v_open_callback, int *opened);
XENUS_IMPORT int finish_no_open(file_k file, dentry_k dentry);

XENUS_IMPORT char *file_path(file_k filp, char *buf, int buflen);

XENUS_IMPORT file_k dentry_open(const struct path *path, int flags, const struct cred *cred);
XENUS_IMPORT file_k filp_open(const char *filename, int flags, umode_t mode);

XENUS_IMPORT file_k file_open_root(dentry_k dentry, vfsmount_k mnt, const char *filename, int flags, umode_t mode);
XENUS_IMPORT int filp_close(file_k filp, fl_owner_t id);
XENUS_IMPORT int generic_file_open(inode_k  inode, file_k  filp);
XENUS_IMPORT int nonseekable_open(inode_k inode, file_k filp);

//namei

//TODO: finish this
XENUS_IMPORT int vfs_link(dentry_k old_dentry, inode_k dir, dentry_k new_dentry, inode_k *delegated_inode);
XENUS_IMPORT int vfs_unlink(inode_k dir, dentry_k dentry, inode_k *delegated_inode);
XENUS_IMPORT int vfs_rename(inode_k old_dir, dentry_k old_dentry, inode_k new_dir, dentry_k new_dentry, inode_k *delegated_inode, unsigned int flags);
XENUS_IMPORT int vfs_rmdir(inode_k dir, dentry_k dentry);
XENUS_IMPORT int vfs_create(inode_k dir, dentry_k dentry, umode_t mode, bool want_excl);
// read_write

//TODO: finish this
XENUS_IMPORT int_t kernel_write(file_k file, const void *buf, size_t count, loff_t *pos);
XENUS_IMPORT int_t kernel_read(file_k file, void *buf, size_t count, loff_t *pos);