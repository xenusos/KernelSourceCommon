XENUS_IMPORT void lockref_get(lockref_k lockref);
XENUS_IMPORT l_int lockref_get_not_zero(lockref_k lockref);
XENUS_IMPORT l_int lockref_get_or_lock(lockref_k lockref);
XENUS_IMPORT l_int lockref_put_return(lockref_k lockref);
XENUS_IMPORT void lockref_mark_dead(lockref_k lockref);
XENUS_IMPORT l_int lockref_get_not_dead(lockref_k lockref);
XENUS_IMPORT l_int lockref_put_or_lock(lockref_k lockref);
