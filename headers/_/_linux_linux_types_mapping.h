
#include <linux/module.h>
#include <linux/cpumask.h>
#include <linux/kobject.h>
#include <linux/ioport.h>
#include <linux/sched.h>
#include <linux/rwsem.h>
#include <linux/workqueue.h>
#include <linux/fwnode.h>
#include <asm/thread_info.h>
#include <linux/pid.h>
#include <linux/pid_namespace.h>
#include <linux/fs.h>
#include <linux/dcache.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/sysfs.h>
#include <linux/pci.h>
#include <linux/usb/ch9.h>
#include <linux/usb/cdc.h>
#include <linux/usb/composite.h>
#include <linux/mm_types.h>
#include <linux/lockdep.h>
#include <linux/notifier.h>

 
//typedef int			pid_t;


// general

typedef struct cpumask *							cpumask_k;
typedef void *										unknown_k;


typedef struct refcount_struct *					refcount_struct_k;
typedef struct kref *								kref_k;
typedef struct kobject *							kobject_k;

typedef struct resource *							resource_k;

// processes
typedef struct sched_info *							sched_info_k;
typedef struct vtime *								vtime_k;
typedef struct rt_rq *								rt_rq_k;
typedef struct rt_prio_array *						rt_prio_array_k;
typedef struct prev_cputime *						prev_cputime_k;
typedef struct load_weight *						load_weight_k;
typedef struct sched_avg *							sched_avg_k;
typedef struct sched_statistics *					sched_statistics_k;
typedef struct sched_entity  *						sched_entity_k;
typedef struct sched_rt_entity *					sched_rt_entity_k;
typedef struct sched_dl_entity *					sched_dl_entity_k;
typedef struct sched_class *						sched_class_k;
typedef struct wake_q_node *						wake_q_node_k;
typedef struct task_group *							task_group_k;
typedef struct task_struct *						task_k;
typedef struct cfs_bandwidth*						cfs_bandwidth_k;
typedef struct cfs_rq *								cfs_rq_k;

typedef struct autogroup *							autogroup_k;


typedef struct rw_semaphore *						rw_semaphore_k;

// TODO creds

// TODO user


//TODO
typedef struct work_struct *						work_struct_k;
typedef struct fwnode_handle *						fwnode_handle_k;



// arch dependent stuff
typedef struct thread_info *						thread_info_k;
typedef struct thread_struct *						thread_struct_k;

typedef struct pid_namespace *						pid_namespace_k;

typedef struct upid *								upid_k;
typedef struct pid *								pid_k;
typedef struct pid_link *							pid_link_k;

typedef struct mutex *								mutex_k;
typedef struct mutex_waiter *						mutex_waiter_k; //worker?

//TODO: more sched related types

// file io
typedef struct file_operations *					file_operations_k;
typedef struct proc_dir_entry *						proc_dir_entry_k;
typedef struct kstat *								kstat_k;
typedef struct kstatfs *							kstatfs_k;
typedef struct file *								file_k;
typedef struct path *								path_k;
typedef struct inode *								inode_k;
typedef struct iattr *								iattr_k;
typedef struct address_space_operations *			address_space_operations_k;
typedef struct address_space *						address_space_k;
typedef struct block_device *						block_device_k;
typedef struct fown_struct *						fown_struct_k;
typedef struct file_ra_state *						file_ra_state_k;
typedef struct file_lock *							file_lock_k;
typedef struct file_lock_operations  *				file_lock_operations_k;
typedef struct lock_manager_operations  *			lock_manager_operations_k;
typedef struct lock_manager  *						lock_manager_k;
typedef struct fasync_struct *						fasync_struct_k;
typedef struct sb_writers *							sb_writers_k;
typedef struct super_block *						super_block_k;
typedef struct dir_context *						dir_context_k;
typedef struct inode_operations  *					inode_operations_k;
typedef struct super_operations  *					super_operations_k;
typedef struct file_system_type  *					file_system_type_k;
typedef struct filename  *							filename_k;
typedef struct vfsmount *							vfsmount_k;

// greenary 
typedef struct rcu_node *							rcu_node_k;
typedef struct rcu_noqs *							rcu_noqs_k;
typedef struct rcu_data *							rcu_data_k;

// memory
typedef struct core_state *							core_state_k;
typedef struct core_thread *						core_thread_k;
typedef struct vm_area_struct *						vm_area_struct_k;
typedef struct mm_struct *							mm_struct_k;
typedef struct vm_region *							vm_region_k;
typedef struct vm_fault *							vm_fault;
typedef struct vm_operations_struct *				vm_operations_struct_k;
typedef struct vm_special_mapping *					vm_special_mapping_k;
typedef struct page  *								page_k;
typedef struct scatterlist *						scatterlist_k;


// some usb stuff
typedef struct usb_interface_descriptor *			usb_interface_descriptor_k;
typedef struct usb_host_endpoint *					usb_host_endpoint_k;
typedef struct usb_bus *							usb_bus_k;
typedef struct usb_interface *						usb_interface_k;
typedef struct usb_host_interface *					usb_host_interface_k;
typedef struct usb_device *							usb_device_k;
typedef struct usb_driver *							usb_driver_k;
typedef struct usb_device_driver *					usb_device_driver_k;
typedef struct usb_anchor *							usb_anchor_k;
typedef struct usb_iso_packet_descriptor  *			usb_iso_packet_descriptor_k;
typedef struct usb_sg_request  *					usb_sg_request_k;
typedef struct usb_interface_cache   *				usb_interface_cache_k;
typedef struct usb_host_config   *					usb_host_config_k;
typedef struct usb_host_bos   *						usb_host_bos_k;
typedef struct urb   *								urb_k;
typedef struct usb_ss_ep_comp_descriptor *			usb_ss_ep_comp_descriptor_k;
typedef struct usb_ssp_isoc_ep_comp_descriptor *	usb_ssp_isoc_ep_comp_descriptor_k;
typedef struct usb_interface_assoc_descriptor *		usb_interface_assoc_descriptor_k;
typedef struct usb_endpoint_descriptor *			usb_endpoint_descriptor_k;
typedef struct usb_config_descriptor *				usb_config_descriptor_k;

// notifier
typedef struct notifier_block *						notifier_block_k;
typedef struct atomic_notifier_head *				atomic_notifier_head_k;
typedef struct blocking_notifier_head *				blocking_notifier_head_k;
typedef struct raw_notifier_head  *					raw_notifier_head_k;
typedef struct srcu_notifier_head   *				srcu_notifier_head_k;


// pci
typedef struct pci_driver *							pci_driver_k;
typedef struct pci_device_id *						pci_device_id_k;
typedef struct pci_bus *							pci_bus_k;
typedef struct pci_slot *							pci_slot_k;
typedef struct pci_dev *							pci_dev_k;
typedef struct pci_error_handlers *					pci_error_handlers_k;
typedef struct pci_dynids *							pci_dynids_k;
typedef struct pci_bus_region  *					pci_bus_region_k;
typedef struct pci_host_bridge *					pci_host_bridge_k;
typedef struct pci_ops *							pci_ops_k;
typedef struct pci_saved_state *					pci_saved_state_k;
typedef struct pci_cap_saved_state *				pci_cap_saved_state_k;

// devices
typedef struct device *								device_k;
typedef struct device_type *						device_type_k;
typedef struct dev_links_info *						dev_links_info_k;
typedef struct device_driver *						device_driver_k;
typedef struct dev_ext_attribute *					dev_ext_attribute_k;
typedef struct device_node *						device_node_k;
typedef struct device_attribute *					device_attribute_k;
typedef struct device_link *						device_link_k;

typedef struct class *								class_k;
typedef struct class_dev_iter*						class_dev_iter_k;
typedef struct class_interface  *					class_interface_k;
typedef struct class_attribute_string *				class_attribute_string_k;
typedef struct class_attribute  *					class_attribute_k;
typedef struct bus_type *							bus_type_k;
typedef struct bus_attribute *						bus_attribute_k;

typedef struct irq_domain *							irq_domain_k;

typedef struct attribute_group *					attribute_group_k;
typedef struct bin_attribute  *						bin_attribute_k;
typedef struct sysfs_ops  *							sysfs_ops_k;

typedef struct cdev *								cdev_k;

typedef struct dev_pm_ops*							dev_pm_ops_k;
typedef struct dev_pm_info *						dev_pm_info_k;
typedef struct dev_pm_domain*						dev_pm_domain_k;
typedef struct pm_subsys_data *						pm_subsys_data_k;

typedef struct lock_class_key *						lock_class_key_k;
typedef struct lockdep_subclass_key *				lockdep_subclass_key_k;
typedef struct lock_class *							lock_class_k;
typedef struct lock_time *							lock_time_k;
typedef struct lock_class_stats *					lock_class_stats_k;
typedef struct lockdep_map *						lockdep_map_k;
typedef struct lock_list *							lock_list_k;
typedef struct lock_chain *							lock_chain_k;
typedef struct held_lock *							held_lock_k;

//
typedef struct module *								module_k;
typedef struct module_attribute *					module_attribute_k;
typedef struct module_kobject *						module_kobject_k;
typedef struct module_version_attribute *			module_version_attribute_k;
typedef struct module_use *							module_use_k;
typedef struct mod_tree_node *						mod_tree_node_k;
typedef struct module_layout *						module_layout_k;
typedef struct mod_kallsyms *						mod_kallsyms_k;


typedef struct dma_map_ops *						dma_map_ops_k;

//seq files
typedef struct seq_file *							seq_file_k;
typedef struct seq_operations *						seq_operations_k;

//dcache
typedef struct qstr *								qstr_k;
typedef struct dentry *								dentry_k;
typedef struct dentry_operations  *					dentry_operations_k;
typedef struct dentry_stat_t *						dentry_stat_t_k; //wtf linux devs

typedef struct sched_attr *							sched_attr_k;

//TODO:
//Typedef long long			__kernel_long_t;
//Typedef unsigned long long	__kernel_ulong_t;
//Tdefine __kernel_long_t		__kernel_long_t
//T
//Typedef __kernel_long_t		__kernel_off_t;
//Typedef long long			__kernel_loff_t;
//Typedef __kernel_long_t		__kernel_time_t;
//Typedef __kernel_long_t		__kernel_clock_t;
//Typedef int					__kernel_timer_t;
//Typedef int					__kernel_clockid_t;
//Typedef char *				__kernel_caddr_t;
//Typedef unsigned short		__kernel_uid16_t;
//Typedef unsigned short		__kernel_gid16_t;
//Typedef __kernel_long_t		__kernel_suseconds_t;
//Typedef int					__kernel_daddr_t;
//Typedef unsigned int		__kernel_uid32_t;
//Typedef unsigned int		__kernel_gid32_t;
//Typedef unsigned int		__kernel_uid_t;
//Typedef int					__kernel_pid_t;
//Typedef unsigned int		__kernel_mode_t;
//Typedef unsigned int		__kernel_gid_t;
