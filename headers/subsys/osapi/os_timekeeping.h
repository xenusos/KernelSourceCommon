XENUS_IMPORT uint64_t ktime_get_mono_fast_ns();
XENUS_IMPORT uint64_t ktime_get_raw_fast_ns();
XENUS_IMPORT uint64_t  ktime_get_boot_fast_ns();
XENUS_IMPORT l_int pvclock_gtod_register_notifier(notifier_block_k nb);
XENUS_IMPORT l_int pvclock_gtod_unregister_notifier(notifier_block_k nb);
XENUS_IMPORT l_int __getnstimeofday64(timespec64_k ts);
XENUS_IMPORT void getnstimeofday64(timespec64_k ts);
XENUS_IMPORT ktime_t ktime_get();
XENUS_IMPORT uint32_t ktime_get_resolution_ns();
XENUS_IMPORT ktime_t ktime_get_with_offset(enum tk_offsets offs);
XENUS_IMPORT ktime_t ktime_mono_to_any(ktime_t tmono, enum tk_offsets offs);
XENUS_IMPORT ktime_t ktime_get_raw();
XENUS_IMPORT void ktime_get_ts64(timespec64_k ts);
XENUS_IMPORT time64_t ktime_get_seconds();
XENUS_IMPORT time64_t ktime_get_real_seconds();
XENUS_IMPORT void do_gettimeofday(timeval_k tv);
XENUS_IMPORT l_int do_settimeofday64(const timespec64_k ts);
XENUS_IMPORT void getrawmonotonic64(timespec64_k ts);