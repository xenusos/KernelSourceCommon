
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
#include <linux/of.h>


typedef struct cpumask *							cpumask_k;
typedef void *										unknown_k;

#define DEFINE_TYPE(x) typedef struct x *			x ## _k;
#include "_unknown_types.macros"
#undef DEFINE_TYPE