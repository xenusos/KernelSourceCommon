XENUS_IMPORT void kernel_sigaction(l_int sig, __sighandler_t action);
XENUS_IMPORT void recalc_sigpending();
XENUS_IMPORT l_int dequeue_signal(task_k tsk, sigset_t * mask, siginfo_t * info);
XENUS_IMPORT void flush_signals(task_k t);
XENUS_IMPORT void force_sig(l_int sig, task_k p);
XENUS_IMPORT l_int send_sig(l_int sig, task_k p, l_int priv);
XENUS_IMPORT l_int send_sig_info(l_int sig, siginfo_k info, task_k p);
XENUS_IMPORT l_int sigprocmask(l_int how, sigset_t * set, sigset_t * oldset);
XENUS_IMPORT l_int kill_pgrp(pid_k pid, l_int sig, l_int priv);
XENUS_IMPORT l_int kill_pid(pid_k pid, l_int sig, l_int priv);
XENUS_IMPORT l_int kill_pid_info_as_cred(l_int sig, siginfo_k info, pid_k pid, const cred_k cred);
