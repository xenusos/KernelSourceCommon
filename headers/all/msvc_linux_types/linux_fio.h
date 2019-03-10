#pragma once

typedef l_int rwf_t;

//#define PATH_MAX        4096    
#define PATH_MAX 256 
// this is a nasty hack - we shouldn't be using a FS that uses names greater than 256
// prevent stack overflows and large memory foot prints etc etc
// TODO:

#define O_ACCMODE    00000003
#define O_RDONLY    00000000
#define O_WRONLY    00000001
#define O_RDWR        00000002
#ifndef O_CREAT
#define O_CREAT        00000100    /* not fcntl */
#endif
#ifndef O_EXCL
#define O_EXCL        00000200    /* not fcntl */
#endif
#ifndef O_NOCTTY
#define O_NOCTTY    00000400    /* not fcntl */
#endif
#ifndef O_TRUNC
#define O_TRUNC        00001000    /* not fcntl */
#endif
#ifndef O_APPEND
#define O_APPEND    00002000
#endif
#ifndef O_NONBLOCK
#define O_NONBLOCK    00004000
#endif
#ifndef O_DSYNC
#define O_DSYNC        00010000    /* used to be O_SYNC, see below */
#endif
#ifndef FASYNC
#define FASYNC        00020000    /* fcntl, for BSD compatibility */
#endif
#ifndef O_DIRECT
#define O_DIRECT    00040000    /* direct disk access hint */
#endif
#ifndef O_LARGEFILE
#define O_LARGEFILE    00100000
#endif
#ifndef O_DIRECTORY
#define O_DIRECTORY    00200000    /* must be a directory */
#endif
#ifndef O_NOFOLLOW
#define O_NOFOLLOW    00400000    /* don't follow links */
#endif
#ifndef O_NOATIME
#define O_NOATIME    01000000
#endif
#ifndef O_CLOEXEC
#define O_CLOEXEC    02000000    /* set close_on_exec */
#endif

/*
* Before Linux 2.6.33 only O_DSYNC semantics were implemented, but using
* the O_SYNC flag.  We continue to use the existing numerical value
* for O_DSYNC semantics now, but using the correct symbolic name for it.
* This new value is used to request true Posix O_SYNC semantics.  It is
* defined in this strange way to make sure applications compiled against
* new headers get at least O_DSYNC semantics on older kernels.
*
* This has the nice side-effect that we can simply test for O_DSYNC
* wherever we do not care if O_DSYNC or O_SYNC is used.
*
* Note: __O_SYNC must never be used directly.
*/
#ifndef O_SYNC
#define __O_SYNC    04000000
#define O_SYNC        (__O_SYNC|O_DSYNC)
#endif

#ifndef O_PATH
#define O_PATH        010000000
#endif

#ifndef __O_TMPFILE
#define __O_TMPFILE    020000000
#endif

/* a horrid kludge trying to make sure that this will fail on old kernels */
#define O_TMPFILE (__O_TMPFILE | O_DIRECTORY)
#define O_TMPFILE_MASK (__O_TMPFILE | O_DIRECTORY | O_CREAT)      

#ifndef O_NDELAY
#define O_NDELAY    O_NONBLOCK
#endif

#define F_DUPFD        0    /* dup */
#define F_GETFD        1    /* get close_on_exec */
#define F_SETFD        2    /* set/clear close_on_exec */
#define F_GETFL        3    /* get file->f_flags */
#define F_SETFL        4    /* set file->f_flags */
#ifndef F_GETLK
#define F_GETLK        5
#define F_SETLK        6
#define F_SETLKW    7
#endif
#ifndef F_SETOWN
#define F_SETOWN    8    /* for sockets. */
#define F_GETOWN    9    /* for sockets. */
#endif
#ifndef F_SETSIG
#define F_SETSIG    10    /* for sockets. */
#define F_GETSIG    11    /* for sockets. */
#endif

#ifndef CONFIG_64BIT
#ifndef F_GETLK64
#define F_GETLK64    12    /*  using 'struct flock64' */
#define F_SETLK64    13
#define F_SETLKW64    14
#endif
#endif

#ifndef F_SETOWN_EX
#define F_SETOWN_EX    15
#define F_GETOWN_EX    16
#endif

#ifndef F_GETOWNER_UIDS
#define F_GETOWNER_UIDS    17
#endif

/*
* Open File Description Locks
*
* Usually record locks held by a process are released on *any* close and are
* not inherited across a fork().
*
* These cmd values will set locks that conflict with process-associated
* record  locks, but are "owned" by the open file description, not the
* process. This means that they are inherited across fork() like BSD (flock)
* locks, and they are only released automatically when the last reference to
* the the open file against which they were acquired is put.
*/
#define F_OFD_GETLK    36
#define F_OFD_SETLK    37
#define F_OFD_SETLKW    38

#define F_OWNER_TID    0
#define F_OWNER_PID    1
#define F_OWNER_PGRP    2

/* for F_[GET|SET]FL */
#define FD_CLOEXEC    1    /* actually anything with low bit set goes */

/* for posix fcntl() and lockf() */
#ifndef F_RDLCK
#define F_RDLCK        0
#define F_WRLCK        1
#define F_UNLCK        2
#endif

/* for old implementation of bsd flock () */
#ifndef F_EXLCK
#define F_EXLCK        4    /* or 3 */
#define F_SHLCK        8    /* or 4 */
#endif

/* operations for bsd flock(), also used by the kernel implementation */
#define LOCK_SH        1    /* shared lock */
#define LOCK_EX        2    /* exclusive lock */
#define LOCK_NB        4    /* or'd with one of the above to prevent blocking */
#define LOCK_UN        8    /* remove lock */

#define LOCK_MAND    32    /* This is a mandatory flock ... */
#define LOCK_READ    64    /* which allows concurrent read operations */
#define LOCK_WRITE    128    /* which allows concurrent write operations */
#define LOCK_RW        192    /* which allows concurrent read & write ops */

#define F_LINUX_SPECIFIC_BASE    1024



#define LOOKUP_FOLLOW        0x0001
#define LOOKUP_DIRECTORY    0x0002
#define LOOKUP_AUTOMOUNT    0x0004

#define LOOKUP_PARENT        0x0010
#define LOOKUP_REVAL        0x0020
#define LOOKUP_RCU            0x0040
#define LOOKUP_NO_REVAL        0x0080

/*
* Intent data
*/
#define LOOKUP_OPEN                0x0100
#define LOOKUP_CREATE            0x0200
#define LOOKUP_EXCL                0x0400
#define LOOKUP_RENAME_TARGET    0x0800

#define LOOKUP_JUMPED        0x1000
#define LOOKUP_ROOT            0x2000
#define LOOKUP_EMPTY        0x4000
#define LOOKUP_DOWN            0x8000

#define _INC_FCNTL //winsdk

#define STATX_TYPE            0x00000001U    /* Want/got stx_mode & S_IFMT */
#define STATX_MODE            0x00000002U    /* Want/got stx_mode & ~S_IFMT */
#define STATX_NLINK            0x00000004U    /* Want/got stx_nlink */
#define STATX_UID            0x00000008U    /* Want/got stx_uid */
#define STATX_GID            0x00000010U    /* Want/got stx_gid */
#define STATX_ATIME            0x00000020U    /* Want/got stx_atime */
#define STATX_MTIME            0x00000040U    /* Want/got stx_mtime */
#define STATX_CTIME            0x00000080U    /* Want/got stx_ctime */
#define STATX_INO            0x00000100U    /* Want/got stx_ino */
#define STATX_SIZE            0x00000200U    /* Want/got stx_size */
#define STATX_BLOCKS        0x00000400U    /* Want/got stx_blocks */
#define STATX_BASIC_STATS    0x000007ffU    /* The stuff in the normal stat struct */
#define STATX_BTIME            0x00000800U    /* Want/got stx_btime */
#define STATX_ALL            0x00000fffU    /* All currently supported flags */
#define STATX__RESERVED        0x80000000U    /* Reserved for future struct statx expansion */

/*
* Attributes to be found in stx_attributes and masked in stx_attributes_mask.
*
* These give information about the features or the state of a file that might
* be of use to ordinary userspace programs such as GUIs or ls rather than
* specialised tools.
*
* Note that the flags marked [I] correspond to generic FS_IOC_FLAGS
* semantically.  Where possible, the numerical value is picked to correspond
* also.
*/
#define STATX_ATTR_COMPRESSED        0x00000004 /* [I] File is compressed by the fs */
#define STATX_ATTR_IMMUTABLE        0x00000010 /* [I] File is marked immutable */
#define STATX_ATTR_APPEND            0x00000020 /* [I] File is append-only */
#define STATX_ATTR_NODUMP            0x00000040 /* [I] File is not to be dumped */
#define STATX_ATTR_ENCRYPTED        0x00000800 /* [I] File requires key to decrypt in fs */

#define STATX_ATTR_AUTOMOUNT        0x00001000 /* Dir: Automount trigger */


typedef void * fl_owner_t;


//typedef int(*filldir_t)(struct dir_context *, const char *, int, loff_t, u64,
//    unsigned);
typedef void * filldir_t;


typedef l_unsigned gfp_t;
typedef l_unsigned fmode_t;
