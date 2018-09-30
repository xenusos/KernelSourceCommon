/*
    Purpose: list of error codes used by the xenus kernel
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once

#define STATUSES_NAME   xenus_errors
#define STATUSES_DEBUG_ENABLED 1
#define STATUSES_ERRORS   <all\errors\errors.macros>
#define STATUSES_STATUSES <all\errors\statuses.macros>
#include <deps/lib_statuses.h>

#define STRICTLY_OKAY(x)		((x) == XENUS_OKAY)
#define NO_ERROR(x)				((x) > 0)
#define ERROR(x)				((x) < 0)

#define LINUX_ERROR(x) ((l_ulong)(void *)(x) >= (l_ulong)-4095)


#define ASSERT(n, msg, ...) {if (!(n)) {panicf(msg, __VA_ARGS__);}}