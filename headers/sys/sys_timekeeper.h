#pragma once

XENUS_IMPORT uint64_t(ktime_get)();			// returns nanoseconds
XENUS_IMPORT uint64_t(ktime_get_real)();		// returns nanoseconds
XENUS_IMPORT uint64_t(ktime_get_boottime)(); 	// returns nanoseconds