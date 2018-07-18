#pragma once

typedef void * fl_owner_t; //legacy typedef, should be nulled // /* legacy typedef, should eventually be removed */ - Linux Kernel source

// open
XENUS_IMPORT long vfs_truncate(path_k path, loff_t length);
XENUS_IMPORT l_int vfs_fallocate(file_k file, l_int mode, loff_t offset, loff_t len);
XENUS_IMPORT l_int finish_open(file_k file, dentry_k dentry, void * sys_v_open_callback, l_int *opened);
XENUS_IMPORT l_int finish_no_open(file_k file, dentry_k dentry);

XENUS_IMPORT char *file_path(file_k filp, char *buf, l_int buflen);

XENUS_IMPORT file_k dentry_open(const struct path *path, l_int flags, const struct cred *cred);
XENUS_IMPORT file_k filp_open(const char *filename, uint64_t flags, umode_t mode);

XENUS_IMPORT file_k file_open_root(dentry_k dentry, vfsmount_k mnt, const char *filename, l_int flags, umode_t mode);
XENUS_IMPORT l_int filp_close(file_k filp, fl_owner_t id);
XENUS_IMPORT l_int generic_file_open(inode_k  inode, file_k  filp);
XENUS_IMPORT l_int nonseekable_open(inode_k inode, file_k filp);

//namei
XENUS_IMPORT l_int generic_permission(inode_k inode, l_int mask);
XENUS_IMPORT l_int __inode_permission(inode_k inode, l_int mask);
XENUS_IMPORT l_int inode_permission(inode_k inode, l_int mask);

XENUS_IMPORT void path_get(const path_k path);
XENUS_IMPORT void path_put(const path_k path);

XENUS_IMPORT l_int follow_up(path_k path);
XENUS_IMPORT l_int follow_down_one(path_k path);
XENUS_IMPORT l_int follow_down(path_k path);

XENUS_IMPORT l_uint full_name_hash(const void *salt, const char *name, l_uint len);
XENUS_IMPORT uint64_t hashlen_string(const void *salt, const char *name);

XENUS_IMPORT l_int kern_path(const char *name, l_uint flags, path_k path);

XENUS_IMPORT dentry_k lookup_one_len(const char *name, dentry_k base, l_int len);
XENUS_IMPORT dentry_k lookup_one_len_unlocked(const char *name, dentry_k base, l_int len);

XENUS_IMPORT l_int user_path_at_empty(l_int dfd, const char __user *name, unsigned flags, path_k path, l_int *empty);
XENUS_IMPORT l_int kern_path_mountpoint(l_int dfd, const char *name, path_k path, l_uint flags);

XENUS_IMPORT l_int __check_sticky(inode_k dir, inode_k inode);

XENUS_IMPORT dentry_k lock_rename(dentry_k p1, dentry_k p2);
XENUS_IMPORT void unlock_rename(dentry_k p1, dentry_k p2);

XENUS_IMPORT dentry_k kern_path_create(l_int dfd, const char *pathname, path_k path, l_uint lookup_flags);
XENUS_IMPORT void done_path_create(path_k path, dentry_k dentry);
XENUS_IMPORT dentry_k user_path_create(l_int dfd, const char __user *pathname, path_k path, l_uint lookup_flags);

XENUS_IMPORT l_int vfs_path_lookup(dentry_k dentry, vfsmount_k mnt, const char *name, l_uint flags, path_k path);
XENUS_IMPORT l_int vfs_create(inode_k dir, dentry_k dentry, umode_t mode, bool want_excl);
XENUS_IMPORT dentry_k vfs_tmpfile(dentry_k dentry, umode_t mode, l_int open_flag);
XENUS_IMPORT l_int vfs_mknod(inode_k dir, dentry_k dentry, umode_t mode, dev_t dev);
XENUS_IMPORT l_int vfs_mkdir(inode_k dir, dentry_k dentry, umode_t mode);
XENUS_IMPORT l_int vfs_rmdir(inode_k dir, dentry_k dentry);
XENUS_IMPORT l_int vfs_unlink(inode_k dir, dentry_k dentry, inode_k *delegated_inode);
XENUS_IMPORT l_int vfs_symlink(inode_k dir, dentry_k dentry, const char *oldname);
XENUS_IMPORT l_int vfs_link(dentry_k old_dentry, inode_k dir, dentry_k new_dentry, inode_k *delegated_inode);
XENUS_IMPORT l_int vfs_rename(inode_k old_dir, dentry_k old_dentry, inode_k new_dir, dentry_k new_dentry, inode_k *delegated_inode, l_uint flags);
XENUS_IMPORT l_int vfs_whiteout(inode_k dir, dentry_k dentry);
XENUS_IMPORT l_int vfs_readlink(dentry_k dentry, char __user *buffer, l_int buflen);
XENUS_IMPORT const char *vfs_get_link(dentry_k dentry, delayed_call_k done);
XENUS_IMPORT l_int page_symlink(inode_k inode, const char *symname, l_int len);
XENUS_IMPORT l_int __page_symlink(inode_k inode, const char *symname, l_int len, l_int nofs);

XENUS_IMPORT const char *page_get_link(dentry_k dentry, inode_k inode, delayed_call_k callback);
XENUS_IMPORT void page_put_link(void *arg);
XENUS_IMPORT l_int page_readlink(dentry_k dentry, char __user *buffer, l_int buflen);


XENUS_IMPORT int_t kernel_write(file_k file, const void *buf, size_t count, loff_t *pos);
XENUS_IMPORT int_t kernel_read(file_k file, void *buf, size_t count, loff_t *pos);
