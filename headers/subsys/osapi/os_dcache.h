XENUS_IMPORT void __d_drop(dentry_k dentry);
XENUS_IMPORT void d_drop(dentry_k dentry);
XENUS_IMPORT void dput(dentry_k dentry);
XENUS_IMPORT dentry_k dget_parent(dentry_k dentry);
XENUS_IMPORT dentry_k d_find_alias(inode_k inode);
XENUS_IMPORT void d_prune_aliases(inode_k inode);
XENUS_IMPORT void shrink_dcache_sb(super_block_k sb);
XENUS_IMPORT l_int path_has_submounts(const path_k parent);
XENUS_IMPORT void shrink_dcache_parent(dentry_k parent);
XENUS_IMPORT void d_invalidate(dentry_k dentry);
XENUS_IMPORT dentry_k d_alloc(dentry_k parent, const qstr_k name);
XENUS_IMPORT dentry_k d_alloc_pseudo(super_block_k sb, const qstr_k name);
XENUS_IMPORT dentry_k d_alloc_name(dentry_k parent, const char * name);
XENUS_IMPORT void d_set_d_op(dentry_k dentry, const dentry_operations_k op);
XENUS_IMPORT void d_set_fallthru(dentry_k dentry);
XENUS_IMPORT void d_instantiate(dentry_k entry, inode_k inode);
XENUS_IMPORT void d_instantiate_new(dentry_k entry, inode_k inode);
XENUS_IMPORT l_int d_instantiate_no_diralias(dentry_k entry, inode_k inode);
XENUS_IMPORT dentry_k d_make_root(inode_k root_inode);
XENUS_IMPORT dentry_k __d_find_any_alias(inode_k inode);
XENUS_IMPORT dentry_k d_find_any_alias(inode_k inode);
XENUS_IMPORT dentry_k d_obtain_alias(inode_k inode);
XENUS_IMPORT dentry_k d_obtain_root(inode_k inode);
XENUS_IMPORT dentry_k d_add_ci(dentry_k dentry, inode_k inode, qstr_k name);
XENUS_IMPORT dentry_k d_lookup(const dentry_k parent, const qstr_k name);
XENUS_IMPORT dentry_k d_hash_and_lookup(dentry_k dir, qstr_k name);
XENUS_IMPORT void d_delete(dentry_k dentry);
XENUS_IMPORT void d_rehash(dentry_k entry);
XENUS_IMPORT dentry_k d_alloc_parallel(void ** TODO);
XENUS_IMPORT void __d_lookup_done(dentry_k dentry);
XENUS_IMPORT void d_add(dentry_k entry, inode_k inode);
XENUS_IMPORT dentry_k d_exact_alias(dentry_k entry, inode_k inode);
XENUS_IMPORT void dentry_update_name_case(dentry_k dentry, const qstr_k name);
XENUS_IMPORT void d_move(dentry_k dentry, dentry_k target);
XENUS_IMPORT dentry_k d_splice_alias(inode_k inode, dentry_k dentry);
XENUS_IMPORT char * d_path(const path_k path, char * buf, l_int buflen);
XENUS_IMPORT char * simple_dname(dentry_k dentry, char * buffer, l_int buflen);
XENUS_IMPORT char * dentry_path_raw(dentry_k dentry, char * buf, l_int buflen);
XENUS_IMPORT void d_tmpfile(dentry_k dentry, inode_k inode);
