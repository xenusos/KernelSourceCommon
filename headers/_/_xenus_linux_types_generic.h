/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once

// these are structs !
// these should not be treated like regular pointers !
// to allocate on stack, use PS_ALLOC_STRUCT_ON_STACK


//_k = unknown (K)ernel type
// general
typedef void *	unknown_k;
typedef void *	kobject_k;

typedef void *  resource_k;

// processes
typedef void * task_k;
typedef void * thread_info_k;
typedef void * thread_struct_k;
typedef void * pid_k;
typedef void * mutex_k;
typedef void * pid_link_k;
//TODO: more sched related types

// file io
typedef void * file_operations_k;
typedef void * proc_dir_entry_k;
typedef void * kstat_k;
typedef void * file_k;
typedef void * path_k;
typedef void * inode_k;
typedef void * iattr_k;
typedef void * address_space_operations_k;
typedef void * address_space_k;
typedef void * block_device_k;
typedef void * fown_struct_k;
typedef void * file_ra_state_k;
typedef void * file_lock_k;
typedef void * file_lock_operations_k;
typedef void * lock_manager_operations_k;
typedef void * lock_manager_k;
typedef void * fasync_struct_k;
typedef void * sb_writers_k;
typedef void * super_block_k;
typedef void * dir_context_k;
typedef void * inode_operations_k;
typedef void * super_operations_k;
typedef void * file_system_type_k;
typedef void * filename_k;

// memory
typedef void * vm_area_struct_k;
typedef void * mm_struct_k;
typedef void * vm_region_k;
typedef void * vm_operations_struct_k;
typedef void * vm_fault;
typedef void * page_k;
typedef void * scatterlist_k;


// some usb stuff
typedef void * usb_interface_descriptor_k;
typedef void * usb_host_endpoint_k;
typedef void * usb_bus_k;
typedef void * usb_interface_k;
typedef void * usb_host_interface_k;
typedef void * usb_device_k;
typedef void * usb_driver_k;
typedef void * usb_device_driver_k;
typedef void * usb_anchor_k;
typedef void * usb_iso_packet_descriptor_k;
typedef void * usb_sg_request_k;
typedef void * usb_interface_cache_k;
typedef void * usb_host_config_k;
typedef void * usb_host_bos_k;
typedef void * urb_k;
typedef void * usb_ss_ep_comp_descriptor_k;
typedef void * usb_ssp_isoc_ep_comp_descriptor_k;
typedef void * usb_interface_assoc_descriptor_k;
typedef void * usb_endpoint_descriptor_k;
typedef void * usb_config_descriptor_k;

// notifier
typedef void * notifier_block_k;
typedef void * atomic_notifier_head_k;
typedef void * blocking_notifier_head_k;
typedef void * raw_notifier_head_k;
typedef void * srcu_notifier_head_k;


// pci
typedef void * pci_driver_k;
typedef void * pci_device_id_k;
typedef void * pci_bus_k;
typedef void * pci_slot_k;
typedef void * pci_dev_k;
typedef void * pci_error_handlers_k;
typedef void * pci_dynids_k;
typedef void * pci_bus_region_k;
typedef void * pci_host_bridge_k;
typedef void * pci_ops_k;
typedef void * pci_saved_state_k;
typedef void * pci_cap_saved_state_k;

// devices
typedef void * device_k;
typedef void * device_type_k;
typedef void * dev_links_info_k;
typedef void * device_driver_k;
typedef void * dev_ext_attribute_k;
typedef void * device_node_k;
typedef void * device_attribute_k;
typedef void * device_link_k;

typedef void * class_k;
typedef void * class_dev_iter_k;
typedef void * class_interface_k;
typedef void * class_attribute_string_k;
typedef void * class_attribute_k;
typedef void * bus_type_k;
typedef void * bus_attribute_k;

typedef void * irq_domain_k;

typedef void * attribute_group_k;
typedef void * bin_attribute_k;
typedef void * sysfs_ops_k;

typedef void * cdev_k;

typedef void * dev_pm_ops_k;
typedef void * dev_pm_info_k;
typedef void * dev_pm_domain_k;
typedef void * pm_subsys_data_k;

typedef void * lock_class_key_k;
typedef void * lockdep_subclass_key_k;
typedef void * lock_class_k;
typedef void * lock_time_k;
typedef void * lock_class_stats_k;
typedef void * lockdep_map_k;
typedef void * lock_list_k;
typedef void * lock_chain_k;
typedef void * held_lock_k;

//
typedef void * module_k;
typedef void * module_attribute_k;
typedef void * module_kobject_k;
typedef void * module_version_attribute_k;
typedef void * module_use_k;
typedef void * mod_tree_node_k;
typedef void * module_layout_k;
typedef void * mod_kallsyms_k;


typedef void * dma_map_ops_k;

//seq files
typedef void * seq_file_k;
typedef void * seq_operations_k;

//dcache
typedef void * qstr_k;
typedef void * dentry_stat_t_k; //wtf linux devs
typedef void * dentry_k;
typedef void * dentry_operations_k;

typedef void * sched_attr_k;



struct llist_head {
	struct llist_node *first;
};

struct llist_node {
	struct llist_node *next;
};

struct callback_head {
	struct callback_head *next;
	void(*func)(struct callback_head *head);
}/*__attribute__((aligned(sizeof(void *))));*/;


enum pid_type
{
	PIDTYPE_PID,
	PIDTYPE_PGID,
	PIDTYPE_SID,
	PIDTYPE_MAX,
	/* only valid to __task_pid_nr_ns() */
	__PIDTYPE_TGID
};



struct rb_node {
	unsigned long  __rb_parent_color;
	struct rb_node *rb_right;
	struct rb_node *rb_left;
};

struct rb_root {
	struct rb_node *rb_node;
};

/*
* Leftmost-cached rbtrees.
*
* We do not cache the rightmost node based on footprint
* size vs number of potential users that could benefit
* from O(1) rb_last(). Just not worth it, users that want
* this feature can always implement the logic explicitly.
* Furthermore, users that want to cache both pointers may
* find it a bit asymmetric, but that's ok.
*/
struct rb_root_cached {
	struct rb_root rb_root;
	struct rb_node *rb_leftmost;
};

enum vtime_state {
	/* Task is sleeping or running in a CPU with VTIME inactive: */
	VTIME_INACTIVE = 0,
	/* Task runs in userspace in a CPU with VTIME active: */
	VTIME_USER,
	/* Task runs in kernelspace in a CPU with VTIME active: */
	VTIME_SYS,
};

typedef struct {
	uint64_t val;
} pfn_t;

struct list_head {
	struct list_head *next, *prev;
};

struct hlist_head {
	struct hlist_node *first;
};

struct hlist_node {
	struct hlist_node *next, **pprev;
};

typedef struct {
	int counter;
} atomic_t;



typedef int					pci_power_t;


typedef uint64_t			cpumask; //TODO: int 128
typedef cpumask *			cpumask_k;


typedef long long			__kernel_long_t;
typedef unsigned long long	__kernel_ulong_t;
#define __kernel_long_t		__kernel_long_t

typedef __kernel_long_t		__kernel_off_t;
typedef long long			__kernel_loff_t;
typedef __kernel_long_t		__kernel_time_t;
typedef __kernel_long_t		__kernel_clock_t;
typedef int					__kernel_timer_t;
typedef int					__kernel_clockid_t;
typedef char *				__kernel_caddr_t;
typedef unsigned short		__kernel_uid16_t;
typedef unsigned short		__kernel_gid16_t;
typedef __kernel_long_t		__kernel_suseconds_t;
typedef int					__kernel_daddr_t;
typedef unsigned int		__kernel_uid32_t;
typedef unsigned int		__kernel_gid32_t;
typedef unsigned int		__kernel_uid_t;
typedef int					__kernel_pid_t;
typedef unsigned int		__kernel_mode_t;
typedef unsigned int		__kernel_gid_t;


typedef __kernel_loff_t				loff_t;
typedef __kernel_off_t				off_t;
typedef __kernel_loff_t				loff_t;
typedef __kernel_time_t				time_t;
typedef __kernel_clock_t			clock_t;
typedef __kernel_timer_t			timer_t;
typedef __kernel_clockid_t			clockid_t;
typedef __kernel_caddr_t			caddr_t;
typedef __kernel_uid16_t			uid16_t;
typedef __kernel_gid16_t			gid16_t;
typedef __kernel_suseconds_t		suseconds_t;
typedef __kernel_daddr_t			daddr_t;
typedef __kernel_uid32_t			uid32_t;
typedef __kernel_gid32_t			gid32_t;
typedef __kernel_uid_t				uid_t;
typedef __kernel_pid_t				pid_t;
typedef __kernel_mode_t				mode_t;
typedef __kernel_gid_t				gid_t;
typedef size_t						dev_t;

typedef physical_address_t resource_size_t;
typedef physical_address_t dma_addr_t;
typedef physical_address_t pci_bus_addr_t;

typedef unsigned long	pteval_t;
typedef unsigned long	pmdval_t;
typedef unsigned long	pudval_t;
typedef unsigned long	p4dval_t;
typedef unsigned long	pgdval_t;
typedef unsigned long	pgprotval_t;

typedef struct { pteval_t pte; } pte_t;
typedef struct pgprot { pgprotval_t pgprot; } pgprot_t;
typedef struct { pgdval_t pgd; } pgd_t;


#define __AC(X,Y)			(X##Y)
#define _AC(X,Y)			__AC(X,Y)
#define _AT(T,X)			((T)(X))

#define PAGE_SHIFT			12
#define PAGE_SIZE			(_AC(1,UL) << PAGE_SHIFT)
#define PAGE_MASK			(~(PAGE_SIZE-1))

#define PFN_ALIGN(x)		(((unsigned long)(x) + (PAGE_SIZE - 1)) & PAGE_MASK)
#define PFN_UP(x)			(((x) + PAGE_SIZE-1) >> PAGE_SHIFT)
#define PFN_DOWN(x)			((x) >> PAGE_SHIFT)
#define PFN_PHYS(x)			((physical_address_t)(x) << PAGE_SHIFT)
#define PHYS_PFN(x)			((unsigned long)((x) >> PAGE_SHIFT))


typedef unsigned short umode_t;

typedef struct {
	uid_t val;
} kuid_t;


typedef struct {
	gid_t val;
} kgid_t;

//typedef int(*filldir_t)(struct dir_context *, const char *, int, loff_t, u64,
//	unsigned);
typedef void * filldir_t;