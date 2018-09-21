/*
    Purpose: list of error codes used by the xenus kernel
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once

#define STATUSES_NAME   xenus_errors
#define STATUSES_HEADER <all\_xenus_error_codes.h>
#include <deps/lib_statuses.h>

#define STRICTLY_OKAY(x)		((x) == XENUS_OKAY)
#define NO_ERROR(x)				((x) > 0)
#define ERROR(x)				((x) < 0)

#define LINUX_ERROR(x) ((l_ulong)(void *)(x) >= (l_ulong)-4095)


#define ASSERT(n, msg) {if (!(n)) {panic(msg);}}