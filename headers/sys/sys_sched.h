#pragma once


// current
XENUS_IMPORT void(*kernel_fpu_begin)							(void);	// UNSAFE!
XENUS_IMPORT void(*kernel_fpu_end)								(void); // UNSAFE!

XENUS_IMPORT task_k _current(void);

//preemption
XENUS_IMPORT void preempt_enable(void);
XENUS_IMPORT void preempt_disable(void);

// core
XENUS_IMPORT int	set_cpus_allowed_ptr(task_k p, cpumask_k new_mask);
XENUS_IMPORT void	kick_process(task_k p);
XENUS_IMPORT int	wake_up_process(task_k p);
XENUS_IMPORT bool	single_task_running(void);
XENUS_IMPORT void	schedule(void);
XENUS_IMPORT int	default_wake_function(wait_queue_entry_t_k *curr, unsigned mode, int wake_flags, void *key);
XENUS_IMPORT void	set_user_nice(task_k p, long nice);
XENUS_IMPORT int	sched_setscheduler(task_k p, int policy, sched_param_k param);
XENUS_IMPORT int	sched_setattr(task_k p, sched_attr_k attr);
XENUS_IMPORT int	sched_setscheduler_nocheck(task_k p, int policy, sched_param_k param);
XENUS_IMPORT int	_cond_resched(void);
XENUS_IMPORT int	__cond_resched_lock(spinlock_t_k lock);
XENUS_IMPORT int	__cond_resched_softirq(void);
XENUS_IMPORT long	io_schedule_timeout(long timeout);
XENUS_IMPORT void	io_schedule(void);


//TODO: add preempt counter?