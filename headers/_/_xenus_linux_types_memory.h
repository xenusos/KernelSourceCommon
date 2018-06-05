#pragma once

//old:
//#define __GFP_HIGH		0x20u
//#define __GFP_IO		0x40u
//#define __GFP_FS		0x80u
//#define __GFP_ATOMIC		0x80000u
//#define __GFP_DIRECT_RECLAIM 0x400000
//#define __GFP_KSWAPD_RECLAIM 0x1000000
//
//#define __GFP_RECLAIM (__GFP_DIRECT_RECLAIM | __GFP_KSWAPD_RECLAIM)
//
//#define GFP_KERNEL	(__GFP_RECLAIM | __GFP_IO | __GFP_FS)
//#define GFP_ATOMIC	(__GFP_HIGH|__GFP_ATOMIC|__GFP_KSWAPD_RECLAIM)


#define __GFP_DMA			0x01u
#define __GFP_HIGHMEM		0x02u
#define __GFP_DMA32			0x04u
#define __GFP_MOVABLE		0x08u
#define __GFP_RECLAIMABLE	0x10u
#define __GFP_HIGH			0x20u
#define __GFP_IO			0x40u
#define __GFP_FS			0x80u
#define __GFP_NOWARN		0x200u
#define __GFP_RETRY_MAYFAIL	0x400u
#define __GFP_NOFAIL		0x800u
#define __GFP_NORETRY		0x1000u
#define __GFP_MEMALLOC		0x2000u
#define __GFP_COMP			0x4000u
#define __GFP_ZERO			0x8000u
#define __GFP_NOMEMALLOC	0x10000u
#define __GFP_HARDWALL		0x20000u
#define __GFP_THISNODE		0x40000u
#define __GFP_ATOMIC		0x80000u
#define __GFP_ACCOUNT		0x100000u
#define __GFP_DIRECT_RECLAIM	0x400000u
#define __GFP_WRITE			0x800000u
#define __GFP_KSWAPD_RECLAIM	0x1000000u
#ifdef CONFIG_LOCKDEP
#define __GFP_NOLOCKDEP	0x2000000u
#else
#define __GFP_NOLOCKDEP	0
#endif
/* If the above are modified, __GFP_BITS_SHIFT may need updating */

/*
 * Physical address zone modifiers (see linux/mmzone.h - low four bits)
 *
 * Do not put any conditional on these. If necessary modify the definitions
 * without the underscores and use them consistently. The definitions here may
 * be used in bit comparisons.
 */ 
#define GFP_ZONEMASK	(__GFP_DMA|__GFP_HIGHMEM|__GFP_DMA32|__GFP_MOVABLE)

#define __GFP_RECLAIM ((__GFP_DIRECT_RECLAIM|__GFP_KSWAPD_RECLAIM))

/* Room for N __GFP_FOO bits */
//#define __GFP_BITS_SHIFT (25 + IS_ENABLED(CONFIG_LOCKDEP))
//#define __GFP_BITS_MASK ((__force gfp_t)((1 << __GFP_BITS_SHIFT) - 1))


#define GFP_ATOMIC              (__GFP_HIGH|__GFP_ATOMIC|__GFP_KSWAPD_RECLAIM)
#define GFP_KERNEL              (__GFP_RECLAIM | __GFP_IO | __GFP_FS)
#define GFP_KERNEL_ACCOUNT      (GFP_KERNEL | __GFP_ACCOUNT)
#define GFP_NOWAIT              (__GFP_KSWAPD_RECLAIM)
#define GFP_NOIO                (__GFP_RECLAIM)
#define GFP_NOFS                (__GFP_RECLAIM | __GFP_IO)
#define GFP_USER                (__GFP_RECLAIM | __GFP_IO | __GFP_FS | __GFP_HARDWALL)
#define GFP_DMA                 __GFP_DMA
#define GFP_DMA32               __GFP_DMA32
#define GFP_HIGHUSER            (GFP_USER | __GFP_HIGHMEM)
#define GFP_HIGHUSER_MOVABLE    (GFP_HIGHUSER | __GFP_MOVABLE)
#define GFP_TRANSHUGE_LIGHT     ((GFP_HIGHUSER_MOVABLE | __GFP_COMP | __GFP_NOMEMALLOC | __GFP_NOWARN) & ~__GFP_RECLAIM)
#define GFP_TRANSHUGE           (GFP_TRANSHUGE_LIGHT | __GFP_DIRECT_RECLAIM)


/*
 * Page mobility and placement hints
 *
 * These flags provide hints about how mobile the page is. Pages with similar
 * mobility are placed within the same pageblocks to minimise problems due
 * to external fragmentation.
 *
 * __GFP_MOVABLE (also a zone modifier) indicates that the page can be
 *   moved by page migration during memory compaction or can be reclaimed.
 *
 * __GFP_RECLAIMABLE is used for slab allocations that specify
 *   SLAB_RECLAIM_ACCOUNT and whose pages can be freed via shrinkers.
 *
 * __GFP_WRITE indicates the caller intends to dirty the page. Where possible,
 *   these pages will be spread between local zones to avoid all the dirty
 *   pages being in one zone (fair zone allocation policy).
 *
 * __GFP_HARDWALL enforces the cpuset memory allocation policy.
 *
 * __GFP_THISNODE forces the allocation to be satisified from the requested
 *   node with no fallbacks or placement policy enforcements.
 *
 * __GFP_ACCOUNT causes the allocation to be accounted to kmemcg.
 */
/*
 * Watermark modifiers -- controls access to emergency reserves
 *
 * __GFP_HIGH indicates that the caller is high-priority and that granting
 *   the request is necessary before the system can make forward progress.
 *   For example, creating an IO context to clean pages.
 *
 * __GFP_ATOMIC indicates that the caller cannot reclaim or sleep and is
 *   high priority. Users are typically interrupt handlers. This may be
 *   used in conjunction with __GFP_HIGH
 *
 * __GFP_MEMALLOC allows access to all memory. This should only be used when
 *   the caller guarantees the allocation will allow more memory to be freed
 *   very shortly e.g. process exiting or swapping. Users either should
 *   be the MM or co-ordinating closely with the VM (e.g. swap over NFS).
 *
 * __GFP_NOMEMALLOC is used to explicitly forbid access to emergency reserves.
 *   This takes precedence over the __GFP_MEMALLOC flag if both are set.
 */
/*
 * Reclaim modifiers
 *
 * __GFP_IO can start physical IO.
 *
 * __GFP_FS can call down to the low-level FS. Clearing the flag avoids the
 *   allocator recursing into the filesystem which might already be holding
 *   locks.
 *
 * __GFP_DIRECT_RECLAIM indicates that the caller may enter direct reclaim.
 *   This flag can be cleared to avoid unnecessary delays when a fallback
 *   option is available.
 *
 * __GFP_KSWAPD_RECLAIM indicates that the caller wants to wake kswapd when
 *   the low watermark is reached and have it reclaim pages until the high
 *   watermark is reached. A caller may wish to clear this flag when fallback
 *   options are available and the reclaim is likely to disrupt the system. The
 *   canonical example is THP allocation where a fallback is cheap but
 *   reclaim/compaction may cause indirect stalls.
 *
 * __GFP_RECLAIM is shorthand to allow/forbid both direct and kswapd reclaim.
 *
 * The default allocator behavior depends on the request size. We have a concept
 * of so called costly allocations (with order > PAGE_ALLOC_COSTLY_ORDER).
 * !costly allocations are too essential to fail so they are implicitly
 * non-failing by default (with some exceptions like OOM victims might fail so
 * the caller still has to check for failures) while costly requests try to be
 * not disruptive and back off even without invoking the OOM killer.
 * The following three modifiers might be used to override some of these
 * implicit rules
 *
 * __GFP_NORETRY: The VM implementation will try only very lightweight
 *   memory direct reclaim to get some memory under memory pressure (thus
 *   it can sleep). It will avoid disruptive actions like OOM killer. The
 *   caller must handle the failure which is quite likely to happen under
 *   heavy memory pressure. The flag is suitable when failure can easily be
 *   handled at small cost, such as reduced throughput
 *
 * __GFP_RETRY_MAYFAIL: The VM implementation will retry memory reclaim
 *   procedures that have previously failed if there is some indication
 *   that progress has been made else where.  It can wait for other
 *   tasks to attempt high level approaches to freeing memory such as
 *   compaction (which removes fragmentation) and page-out.
 *   There is still a definite limit to the number of retries, but it is
 *   a larger limit than with __GFP_NORETRY.
 *   Allocations with this flag may fail, but only when there is
 *   genuinely little unused memory. While these allocations do not
 *   directly trigger the OOM killer, their failure indicates that
 *   the system is likely to need to use the OOM killer soon.  The
 *   caller must handle failure, but can reasonably do so by failing
 *   a higher-level request, or completing it only in a much less
 *   efficient manner.
 *   If the allocation does fail, and the caller is in a position to
 *   free some non-essential memory, doing so could benefit the system
 *   as a whole.
 *
 * __GFP_NOFAIL: The VM implementation _must_ retry infinitely: the caller
 *   cannot handle allocation failures. The allocation could block
 *   indefinitely but will never return with failure. Testing for
 *   failure is pointless.
 *   New users should be evaluated carefully (and the flag should be
 *   used only when there is no reasonable failure policy) but it is
 *   definitely preferable to use the flag rather than opencode endless
 *   loop around allocator.
 *   Using this flag for costly allocations is _highly_ discouraged.
 */
 /*
 * Action modifiers
 *
 * __GFP_NOWARN suppresses allocation failure reports.
 *
 * __GFP_COMP address compound page metadata.
 *
 * __GFP_ZERO returns a zeroed page on success.
 */
/*
 * Useful GFP flag combinations that are commonly used. It is recommended
 * that subsystems start with one of these combinations and then set/clear
 * __GFP_FOO flags as necessary.
 *
 * GFP_ATOMIC users can not sleep and need the allocation to succeed. A lower
 *   watermark is applied to allow access to "atomic reserves"
 *
 * GFP_KERNEL is typical for kernel-internal allocations. The caller requires
 *   ZONE_NORMAL or a lower zone for direct access but can direct reclaim.
 *
 * GFP_KERNEL_ACCOUNT is the same as GFP_KERNEL, except the allocation is
 *   accounted to kmemcg.
 *
 * GFP_NOWAIT is for kernel allocations that should not stall for direct
 *   reclaim, start physical IO or use any filesystem callback.
 *
 * GFP_NOIO will use direct reclaim to discard clean pages or slab pages
 *   that do not require the starting of any physical IO.
 *   Please try to avoid using this flag directly and instead use
 *   memalloc_noio_{save,restore} to mark the whole scope which cannot
 *   perform any IO with a short explanation why. All allocation requests
 *   will inherit GFP_NOIO implicitly.
 *
 * GFP_NOFS will use direct reclaim but will not use any filesystem interfaces.
 *   Please try to avoid using this flag directly and instead use
 *   memalloc_nofs_{save,restore} to mark the whole scope which cannot/shouldn't
 *   recurse into the FS layer with a short explanation why. All allocation
 *   requests will inherit GFP_NOFS implicitly.
 *
 * GFP_USER is for userspace allocations that also need to be directly
 *   accessibly by the kernel or hardware. It is typically used by hardware
 *   for buffers that are mapped to userspace (e.g. graphics) that hardware
 *   still must DMA to. cpuset limits are enforced for these allocations.
 *
 * GFP_DMA exists for historical reasons and should be avoided where possible.
 *   The flags indicates that the caller requires that the lowest zone be
 *   used (ZONE_DMA or 16M on x86-64). Ideally, this would be removed but
 *   it would require careful auditing as some users really require it and
 *   others use the flag to avoid lowmem reserves in ZONE_DMA and treat the
 *   lowest zone as a type of emergency reserve.
 *
 * GFP_DMA32 is similar to GFP_DMA except that the caller requires a 32-bit
 *   address.
 *
 * GFP_HIGHUSER is for userspace allocations that may be mapped to userspace,
 *   do not need to be directly accessible by the kernel but that cannot
 *   move once in use. An example may be a hardware allocation that maps
 *   data directly into userspace but has no addressing limitations.
 *
 * GFP_HIGHUSER_MOVABLE is for userspace allocations that the kernel does not
 *   need direct access to but can use kmap() when access is required. They
 *   are expected to be movable via page reclaim or page migration. Typically,
 *   pages on the LRU would also be allocated with GFP_HIGHUSER_MOVABLE.
 *
 * GFP_TRANSHUGE and GFP_TRANSHUGE_LIGHT are used for THP allocations. They are
 *   compound allocations that will generally fail quickly if memory is not
 *   available and will not wake kswapd/kcompactd on failure. The _LIGHT
 *   version does not attempt reclaim/compaction at all and is by default used
 *   in page fault path, while the non-light is used by khugepaged.
 */


#define FOLL_WRITE	0x01	/* check pte is writable */
#define FOLL_TOUCH	0x02	/* mark page accessed */
#define FOLL_GET	0x04	/* do get_page on page */
#define FOLL_DUMP	0x08	/* give error on hole if it would be zero */
#define FOLL_FORCE	0x10	/* get_user_pages read/write w/o permission */
#define FOLL_NOWAIT	0x20	/* if a disk transfer is needed, start the IO
 * and return without waiting upon it */
#define FOLL_POPULATE	0x40	/* fault in page */
#define FOLL_SPLIT	0x80	/* don't return transhuge pages, split them */
#define FOLL_HWPOISON	0x100	/* check page is hwpoisoned */
#define FOLL_NUMA	0x200	/* force NUMA hinting page fault */
#define FOLL_MIGRATION	0x400	/* wait for page to replace migration entry */
#define FOLL_TRIED	0x800	/* a retry, previous pass started an IO */
#define FOLL_MLOCK	0x1000	/* lock present pages */
#define FOLL_REMOTE	0x2000	/* we are working on non-current tsk/mm */
#define FOLL_COW	0x4000	/* internal GUP flag */

#define VM_NONE		0x00000000

#define VM_READ		0x00000001	/* currently active flags */
#define VM_WRITE	0x00000002
#define VM_EXEC		0x00000004
#define VM_SHARED	0x00000008

 /* mprotect() hardcodes VM_MAYREAD >> 4 == VM_READ, and so for r/w/x bits. */
#define VM_MAYREAD	0x00000010	/* limits for mprotect() etc */
#define VM_MAYWRITE	0x00000020
#define VM_MAYEXEC	0x00000040
#define VM_MAYSHARE	0x00000080

#define VM_GROWSDOWN	0x00000100	/* general info on the segment */
#define VM_UFFD_MISSING	0x00000200	/* missing pages tracking */
#define VM_PFNMAP	0x00000400	/* Page-ranges managed without "struct page", just pure PFN */
#define VM_DENYWRITE	0x00000800	/* ETXTBSY on write attempts.. */
#define VM_UFFD_WP	0x00001000	/* wrprotect pages tracking */

#define VM_LOCKED	0x00002000
#define VM_IO           0x00004000	/* Memory mapped I/O or similar */

 /* Used by sys_madvise() */
#define VM_SEQ_READ	0x00008000	/* App will access data sequentially */
#define VM_RAND_READ	0x00010000	/* App will not benefit from clustered reads */

#define VM_DONTCOPY	0x00020000      /* Do not copy this vma on fork */
#define VM_DONTEXPAND	0x00040000	/* Cannot expand with mremap() */
#define VM_LOCKONFAULT	0x00080000	/* Lock the pages covered when they are faulted in */
#define VM_ACCOUNT	0x00100000	/* Is a VM accounted object */
#define VM_NORESERVE	0x00200000	/* should the VM suppress accounting */
#define VM_HUGETLB	0x00400000	/* Huge TLB Page VM */
#define VM_SYNC		0x00800000	/* Synchronous page faults */
#define VM_ARCH_1	0x01000000	/* Architecture-specific flag */
#define VM_WIPEONFORK	0x02000000	/* Wipe VMA contents in child. */
#define VM_DONTDUMP	0x04000000	/* Do not include in the core dump */

#ifdef CONFIG_MEM_SOFT_DIRTY
# define VM_SOFTDIRTY	0x08000000	/* Not soft dirty clean area */
#else
# define VM_SOFTDIRTY	0
#endif

#define VM_MIXEDMAP	0x10000000	/* Can contain "struct page" and pure PFN pages */
#define VM_HUGEPAGE	0x20000000	/* MADV_HUGEPAGE marked this vma */
#define VM_NOHUGEPAGE	0x40000000	/* MADV_NOHUGEPAGE marked this vma */
#define VM_MERGEABLE	0x80000000	/* KSM may merge identical pages */

# define VM_GROWSUP	VM_NONE

 /* Bits set in the VMA until the stack is in its final location */
#define VM_STACK_INCOMPLETE_SETUP	(VM_RAND_READ | VM_SEQ_READ)

#ifndef VM_STACK_DEFAULT_FLAGS		/* arch can override this */
#define VM_STACK_DEFAULT_FLAGS VM_DATA_DEFAULT_FLAGS
#endif

#define VM_STACK	VM_GROWSDOWN

#define VM_STACK_FLAGS	(VM_STACK | VM_STACK_DEFAULT_FLAGS | VM_ACCOUNT)

 /*
 * Special vmas that are non-mergable, non-mlock()able.
 * Note: mm/huge_memory.c VM_NO_THP depends on this definition.
 */
#define VM_SPECIAL (VM_IO | VM_DONTEXPAND | VM_PFNMAP | VM_MIXEDMAP)

 /* This mask defines which mm->def_flags a process can inherit its parent */
#define VM_INIT_DEF_MASK	VM_NOHUGEPAGE

 /* This mask is used to clear all the VMA flags used by mlock */
#define VM_LOCKED_CLEAR_MASK	(~(VM_LOCKED | VM_LOCKONFAULT))

 /*
 * mapping from the currently active vm_flags protection bits (the
 * low four bits) to a page protection mask..
 */

#define FAULT_FLAG_WRITE	0x01	/* Fault was a write access */
#define FAULT_FLAG_MKWRITE	0x02	/* Fault was mkwrite of existing pte */
#define FAULT_FLAG_ALLOW_RETRY	0x04	/* Retry fault if blocking */
#define FAULT_FLAG_RETRY_NOWAIT	0x08	/* Don't drop mmap_sem and wait when retrying */
#define FAULT_FLAG_KILLABLE	0x10	/* The fault task is in SIGKILL killable region */
#define FAULT_FLAG_TRIED	0x20	/* Second try */
#define FAULT_FLAG_USER		0x40	/* The fault originated in userspace */
#define FAULT_FLAG_REMOTE	0x80	/* faulting for non current tsk/mm */
#define FAULT_FLAG_INSTRUCTION  0x100	/* The fault was during an instruction fetch */

#define FAULT_FLAG_TRACE \
	{ FAULT_FLAG_WRITE,			"WRITE" }, \
	{ FAULT_FLAG_MKWRITE,		"MKWRITE" }, \
	{ FAULT_FLAG_ALLOW_RETRY,	"ALLOW_RETRY" }, \
	{ FAULT_FLAG_RETRY_NOWAIT,	"RETRY_NOWAIT" }, \
	{ FAULT_FLAG_KILLABLE,		"KILLABLE" }, \
	{ FAULT_FLAG_TRIED,			"TRIED" }, \
	{ FAULT_FLAG_USER,			"USER" }, \
	{ FAULT_FLAG_REMOTE,		"REMOTE" }, \
	{ FAULT_FLAG_INSTRUCTION,	"INSTRUCTION" }


enum dma_data_direction {
	DMA_BIDIRECTIONAL = 0,
	DMA_TO_DEVICE = 1,
	DMA_FROM_DEVICE = 2,
	DMA_NONE = 3,
};


enum tlb_flush_reason {
	TLB_FLUSH_ON_TASK_SWITCH,
	TLB_REMOTE_SHOOTDOWN,
	TLB_LOCAL_SHOOTDOWN,
	TLB_LOCAL_MM_SHOOTDOWN,
	TLB_REMOTE_SEND_IPI,
	NR_TLB_FLUSH_REASONS,
};

#define MNT_NOSUID	0x01
#define MNT_NODEV	0x02
#define MNT_NOEXEC	0x04
#define MNT_NOATIME	0x08
#define MNT_NODIRATIME	0x10
#define MNT_RELATIME	0x20
#define MNT_READONLY	0x40	/* does the user want this to be r/o? */

#define MNT_SHRINKABLE	0x100
#define MNT_WRITE_HOLD	0x200

#define MNT_SHARED	0x1000	/* if the vfsmount is a shared mount */
#define MNT_UNBINDABLE	0x2000	/* if the vfsmount is a unbindable mount */
/*
* MNT_SHARED_MASK is the set of flags that should be cleared when a
* mount becomes shared.  Currently, this is only the flag that says a
* mount cannot be bind mounted, since this is how we create a mount
* that shares events with another mount.  If you add a new MNT_*
* flag, consider how it interacts with shared mounts.
*/
#define MNT_SHARED_MASK	(MNT_UNBINDABLE)
#define MNT_USER_SETTABLE_MASK  (MNT_NOSUID | MNT_NODEV | MNT_NOEXEC \
				 | MNT_NOATIME | MNT_NODIRATIME | MNT_RELATIME \
				 | MNT_READONLY)
#define MNT_ATIME_MASK (MNT_NOATIME | MNT_NODIRATIME | MNT_RELATIME )

#define MNT_INTERNAL_FLAGS (MNT_SHARED | MNT_WRITE_HOLD | MNT_INTERNAL | \
			    MNT_DOOMED | MNT_SYNC_UMOUNT | MNT_MARKED)

#define MNT_INTERNAL	0x4000

#define MNT_LOCK_ATIME		0x040000
#define MNT_LOCK_NOEXEC		0x080000
#define MNT_LOCK_NOSUID		0x100000
#define MNT_LOCK_NODEV		0x200000
#define MNT_LOCK_READONLY	0x400000
#define MNT_LOCKED		0x800000
#define MNT_DOOMED		0x1000000
#define MNT_SYNC_UMOUNT		0x2000000
#define MNT_MARKED		0x4000000
#define MNT_UMOUNT		0x8000000

