#pragma once


typedef void * sched_param_k; //source/kernel/sched l_internal structs
typedef void * sched_attr_k;

// current
XENUS_IMPORT void(*kernel_fpu_begin)							(void);	// UNSAFE!
XENUS_IMPORT void(*kernel_fpu_end)								(void); // UNSAFE!

XENUS_IMPORT task_k _current(void);
#define current _current()

//preemption
XENUS_IMPORT void preempt_enable(void);
XENUS_IMPORT void preempt_disable(void);

// core
XENUS_IMPORT l_int	set_cpus_allowed_ptr(task_k p, cpumask_k new_mask);
XENUS_IMPORT void	kick_process(task_k p);
XENUS_IMPORT l_int	wake_up_process(task_k p);
XENUS_IMPORT bool	single_task_running(void);
XENUS_IMPORT void	schedule(void);
XENUS_IMPORT l_int	default_wake_function(wait_queue_entry_k *curr, l_uint mode, l_int wake_flags, void *key);
XENUS_IMPORT void	set_user_nice(task_k p, long nice);
XENUS_IMPORT l_int	sched_setscheduler(task_k p, l_int policy, sched_param_k param);
XENUS_IMPORT l_int	sched_setattr(task_k p, sched_attr_k attr);
XENUS_IMPORT l_int	sched_setscheduler_nocheck(task_k p, l_int policy, sched_param_k param);
XENUS_IMPORT l_int	_cond_resched(void);
XENUS_IMPORT l_int	__cond_resched_lock(spinlock_t_k lock);
XENUS_IMPORT l_int	__cond_resched_softirq(void);
XENUS_IMPORT long	io_schedule_timeout(long timeout);
XENUS_IMPORT void	io_schedule(void);


//TODO: add preempt counter?
