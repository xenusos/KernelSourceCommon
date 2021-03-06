XENUS_IMPORT device_link_k device_link_add(device_k consumer, device_k supplier, uint32_t flags);
XENUS_IMPORT void device_link_del(device_link_k link);
XENUS_IMPORT const char * dev_driver_string(const device_k dev);
XENUS_IMPORT ssize_t device_store_ulong(device_k dev, device_attribute_k attr, const char * buf, size_t size);
XENUS_IMPORT ssize_t device_show_ulong(device_k dev, device_attribute_k attr, char * buf);
XENUS_IMPORT ssize_t device_store_int(device_k dev, device_attribute_k attr, const char * buf, size_t size);
XENUS_IMPORT ssize_t device_show_int(device_k dev, device_attribute_k attr, char * buf);
XENUS_IMPORT ssize_t device_store_bool(device_k dev, device_attribute_k attr, const char * buf, size_t size);
XENUS_IMPORT ssize_t device_show_bool(device_k dev, device_attribute_k attr, char * buf);
XENUS_IMPORT l_int device_add_groups(device_k dev, const attribute_group_k * groups);
XENUS_IMPORT void device_remove_groups(device_k dev, const attribute_group_k * groups);
XENUS_IMPORT l_int devm_device_add_group(device_k dev, const attribute_group_k grp);
XENUS_IMPORT void devm_device_remove_group(device_k dev, const attribute_group_k grp);
XENUS_IMPORT l_int devm_device_add_groups(device_k dev, const attribute_group_k * groups);
XENUS_IMPORT void devm_device_remove_groups(device_k dev, const attribute_group_k * groups);
XENUS_IMPORT l_int device_create_file(device_k dev, const device_attribute_k attr);
XENUS_IMPORT void device_remove_file(device_k dev, const device_attribute_k attr);
XENUS_IMPORT bool device_remove_file_self(device_k dev, const device_attribute_k attr);
XENUS_IMPORT l_int device_create_bin_file(device_k dev, const bin_attribute_k attr);
XENUS_IMPORT void device_remove_bin_file(device_k dev, const bin_attribute_k attr);
XENUS_IMPORT void device_initialize(device_k dev);
XENUS_IMPORT l_int device_add(device_k dev);
XENUS_IMPORT l_int device_register(device_k dev);
XENUS_IMPORT device_k get_device(device_k dev);
XENUS_IMPORT void put_device(device_k dev);
XENUS_IMPORT void device_del(device_k dev);
XENUS_IMPORT void device_unregister(device_k dev);
XENUS_IMPORT l_int device_for_each_child(device_k parent, void * data, sysv_fptr_t stub);
XENUS_IMPORT l_int device_for_each_child_reverse(device_k parent, void * data, sysv_fptr_t stub);
XENUS_IMPORT device_k device_find_child(device_k parent, void * data, sysv_fptr_t stub);
XENUS_IMPORT device_k __root_device_register(const char * name, module_k owner);
XENUS_IMPORT void root_device_unregister(device_k dev);
XENUS_IMPORT device_k device_create(class_k clazz, device_k parent, dev_t devt, void * drvdata, const char * fmt);
XENUS_IMPORT device_k device_create_with_groups(class_k clazz, device_k parent, dev_t devt, void * drvdata, const attribute_group_k * groups, const char * fmt);
XENUS_IMPORT void device_destroy(class_k clazz, dev_t devt);
XENUS_IMPORT l_int device_rename(device_k dev, const char * new_name);
XENUS_IMPORT l_int dev_printk_emit(l_int level, const device_k dev, const char * fmt);
XENUS_IMPORT void dev_emerg(const device_k dev, const char * fmt);
XENUS_IMPORT void dev_alert(const device_k dev, const char * fmt);
XENUS_IMPORT void dev_crit(const device_k dev, const char * fmt);
XENUS_IMPORT void dev_err(const device_k dev, const char * fmt);
XENUS_IMPORT void dev_warn(const device_k dev, const char * fmt);
XENUS_IMPORT void dev_notice(const device_k dev, const char * fmt);
XENUS_IMPORT void _dev_info(const device_k dev, const char * fmt);
XENUS_IMPORT void set_primary_fwnode(device_k dev, fwnode_handle_k fwnode);
XENUS_IMPORT void device_set_of_node_from_dev(device_k dev, const device_k dev2);
