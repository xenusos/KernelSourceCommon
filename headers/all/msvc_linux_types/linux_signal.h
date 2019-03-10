
#define SIGHUP         1
#define SIGINT         2
#define SIGQUIT        3
#define SIGILL         4
#define SIGTRAP        5
#define SIGABRT        6
#define SIGIOT         6
#define SIGBUS         7
#define SIGFPE         8
#define SIGKILL        9
#define SIGUSR1        10
#define SIGSEGV        11
#define SIGUSR2        12
#define SIGPIPE        13
#define SIGALRM        14
#define SIGTERM        15
#define SIGSTKFLT      16
#define SIGCHLD        17
#define SIGCONT        18
#define SIGSTOP        19
#define SIGTSTP        20
#define SIGTTIN        21
#define SIGTTOU        22
#define SIGURG         23
#define SIGXCPU        24
#define SIGXFSZ        25
#define SIGVTALRM      26
#define SIGPROF        27
#define SIGWINCH       28
#define SIGIO          29
#define SIGPOLL        SIGIO
/*
#define SIGLOST        29
*/
#define SIGPWR         30
#define SIGSYS         31
#define    SIGUNUSED   31

/* These should not be considered constants from userland.  */
#define SIGRTMIN       32
#define SIGRTMAX       _NSIG


#define __SI_MASK      0xffff0000u
#define __SI_KILL      (0 << 16)
#define __SI_TIMER     (1 << 16)
#define __SI_POLL      (2 << 16)
#define __SI_FAULT     (3 << 16)
#define __SI_CHLD      (4 << 16)
#define __SI_RT        (5 << 16)
#define __SI_MESGQ     (6 << 16)
#define __SI_SYS       (7 << 16)
#define __SI_CODE(T,N) ((T) | ((N) & 0xffff))

/*
 * si_code values
 * Digital reserves positive values for kernel-generated signals.
 */
#define SI_USER        0         /* sent by kill, sigsend, raise */
#define SI_KERNEL      0x80      /* sent by the kernel from somewhere */
#define SI_QUEUE       -1        /* sent by sigqueue */
#define SI_TIMER __SI_CODE(__SI_TIMER,-2) /* sent by timer expiration */
#define SI_MESGQ __SI_CODE(__SI_MESGQ,-3) /* sent by real time mesq state change */
#define SI_ASYNCIO     -4        /* sent by AIO completion */
#define SI_SIGIO       -5        /* sent by queued SIGIO */
#define SI_TKILL       -6        /* sent by tkill system call */
#define SI_DETHREAD    -7        /* sent by execve() killing subsidiary threads */

#define SI_FROMUSER(siptr)    ((siptr)->si_code <= 0)
#define SI_FROMKERNEL(siptr)  ((siptr)->si_code > 0)

 /*
  * SIGILL si_codes
  */
#define ILL_ILLOPC    (__SI_FAULT|1)    /* illegal opcode */
#define ILL_ILLOPN    (__SI_FAULT|2)    /* illegal operand */
#define ILL_ILLADR    (__SI_FAULT|3)    /* illegal addressing mode */
#define ILL_ILLTRP    (__SI_FAULT|4)    /* illegal trap */
#define ILL_PRVOPC    (__SI_FAULT|5)    /* privileged opcode */
#define ILL_PRVREG    (__SI_FAULT|6)    /* privileged register */
#define ILL_COPROC    (__SI_FAULT|7)    /* coprocessor error */
#define ILL_BADSTK    (__SI_FAULT|8)    /* internal stack error */
#define NSIGILL        8

  /*
   * SIGFPE si_codes
   */
#define FPE_INTDIV    (__SI_FAULT|1)    /* integer divide by zero */
#define FPE_INTOVF    (__SI_FAULT|2)    /* integer overflow */
#define FPE_FLTDIV    (__SI_FAULT|3)    /* floating point divide by zero */
#define FPE_FLTOVF    (__SI_FAULT|4)    /* floating point overflow */
#define FPE_FLTUND    (__SI_FAULT|5)    /* floating point underflow */
#define FPE_FLTRES    (__SI_FAULT|6)    /* floating point inexact result */
#define FPE_FLTINV    (__SI_FAULT|7)    /* floating point invalid operation */
#define FPE_FLTSUB    (__SI_FAULT|8)    /* subscript out of range */
#define NSIGFPE        8

   /*
    * SIGSEGV si_codes
    */
#define SEGV_MAPERR    (__SI_FAULT|1)    /* address not mapped to object */
#define SEGV_ACCERR    (__SI_FAULT|2)    /* invalid permissions for mapped object */
#define SEGV_BNDERR    (__SI_FAULT|3)    /* failed address bound checks */
#define NSIGSEGV    3

    /*
     * SIGBUS si_codes
     */
#define BUS_ADRALN       (__SI_FAULT|1)    /* invalid address alignment */
#define BUS_ADRERR       (__SI_FAULT|2)    /* non-existent physical address */
#define BUS_OBJERR       (__SI_FAULT|3)    /* object specific hardware error */
     /* hardware memory error consumed on a machine check: action required */
#define BUS_MCEERR_AR    (__SI_FAULT|4)
/* hardware memory error detected in process but not consumed: action optional*/
#define BUS_MCEERR_AO    (__SI_FAULT|5)
#define NSIGBUS          5

/*
 * SIGTRAP si_codes
 */
#define TRAP_BRKPT       (__SI_FAULT|1)  /* process breakpoint */
#define TRAP_TRACE       (__SI_FAULT|2)  /* process trace trap */
#define TRAP_BRANCH      (__SI_FAULT|3)  /* process taken branch trap */
#define TRAP_HWBKPT      (__SI_FAULT|4)  /* hardware breakpoint/watchpoint */
#define NSIGTRAP         4
                         
 /*
  * SIGCHLD si_codes
  */
#define CLD_EXITED       (__SI_CHLD|1)    /* child has exited */
#define CLD_KILLED       (__SI_CHLD|2)    /* child was killed */
#define CLD_DUMPED       (__SI_CHLD|3)    /* child terminated abnormally */
#define CLD_TRAPPED      (__SI_CHLD|4)    /* traced child has trapped */
#define CLD_STOPPED      (__SI_CHLD|5)    /* child has stopped */
#define CLD_CONTINUED    (__SI_CHLD|6)    /* stopped child has continued */
#define NSIGCHLD         6

  /*
   * SIGPOLL si_codes
   */
#define POLL_IN        (__SI_POLL|1)    /* data input available */
#define POLL_OUT       (__SI_POLL|2)    /* output buffers available */
#define POLL_MSG       (__SI_POLL|3)    /* input message available */
#define POLL_ERR       (__SI_POLL|4)    /* i/o error */
#define POLL_PRI       (__SI_POLL|5)    /* high priority input available */
#define POLL_HUP       (__SI_POLL|6)    /* device disconnected */
#define NSIGPOLL       6

   /*
    * SIGSYS si_codes
    */
#define SYS_SECCOMP    (__SI_SYS|1)    /* seccomp triggered */
#define NSIGSYS        1

    /*
     * sigevent definitions
     *
     * It seems likely that SIGEV_THREAD will have to be handled from
     * userspace, libpthread transmuting it to SIGEV_SIGNAL, which the
     * thread manager then catches and does the appropriate nonsense.
     * However, everything is written out here so as to not get lost.
     */
#define SIGEV_SIGNAL    0    /* notify via signal */
#define SIGEV_NONE      1    /* other notification: meaningless */
#define SIGEV_THREAD    2    /* deliver via thread creation */
#define SIGEV_THREAD_ID 4    /* deliver to thread */
