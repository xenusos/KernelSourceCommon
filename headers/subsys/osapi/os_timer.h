XENUS_IMPORT l_unsigned_long round_jiffies(l_unsigned_long j);
XENUS_IMPORT l_unsigned_long round_jiffies_relative(l_unsigned_long j);
XENUS_IMPORT l_unsigned_long __round_jiffies_up(l_unsigned_long j, l_int cpu);
XENUS_IMPORT l_unsigned_long round_jiffies_up(l_unsigned_long j);
XENUS_IMPORT l_unsigned_long round_jiffies_up_relative(l_unsigned_long j);
XENUS_IMPORT void msleep(l_unsigned_int msecs);
XENUS_IMPORT l_unsigned_long msleep_interruptible(l_unsigned_int msecs);
XENUS_IMPORT void  usleep_range(l_unsigned_long min, l_unsigned_long max);
