XENUS_IMPORT void downgrade_write(rw_semaphore_k sem);
XENUS_IMPORT void up_write(rw_semaphore_k sem);
XENUS_IMPORT void up_read(rw_semaphore_k sem);
XENUS_IMPORT l_int down_write_trylock(rw_semaphore_k sem);
XENUS_IMPORT l_int down_write_killable(rw_semaphore_k sem);
XENUS_IMPORT void down_write(rw_semaphore_k sem);
XENUS_IMPORT l_int down_read_trylock(rw_semaphore_k sem);
XENUS_IMPORT void down_read(rw_semaphore_k sem);
