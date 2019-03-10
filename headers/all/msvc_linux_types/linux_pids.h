#pragma once

enum pid_type
{
    PIDTYPE_PID,
    PIDTYPE_PGID,
    PIDTYPE_SID,
    PIDTYPE_MAX,
    /* only valid to __task_pid_nr_ns() */
    __PIDTYPE_TGID
};
