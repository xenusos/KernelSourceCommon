XENUS_IMPORT mutex_k     mutex_init();
XENUS_IMPORT void        mutex_lock(mutex_k mutex);
XENUS_IMPORT int         mutex_trylock(mutex_k mutex);
XENUS_IMPORT void        mutex_unlock(mutex_k mutex);
XENUS_IMPORT void        mutex_destroy(mutex_k mutex);
XENUS_IMPORT int         mutex_is_locked(mutex_k mutex);
#define mutex_create mutex_init