XENUS_IMPORT void put_pid(pid_k pid);
XENUS_IMPORT pid_k find_pid_ns(l_int nr, pid_namespace_k ns);
XENUS_IMPORT pid_k find_vpid(l_int nr);
XENUS_IMPORT task_k pid_task(pid_k pid, enum pid_type type);
XENUS_IMPORT pid_k get_task_pid(task_k task, enum pid_type type);
XENUS_IMPORT task_k get_pid_task(pid_k pid, enum pid_type type);
XENUS_IMPORT pid_k find_get_pid(pid_t nr);
XENUS_IMPORT pid_t pid_nr_ns(pid_k pid, pid_namespace_k ns);
XENUS_IMPORT pid_t pid_vnr(pid_k pid);
XENUS_IMPORT pid_namespace_k task_active_pid_ns(task_k tsk);