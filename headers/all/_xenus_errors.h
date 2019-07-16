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

#define STRICTLY_OKAY(x)        ((x) == XENUS_OKAY)
#define NO_ERROR(x)             ((x) >= XENUS_OKAY)
#define ERROR(x)                ((x) < XENUS_OKAY)

#define LINUX_PTR_ERROR(x) ((l_ulong)(void *)(x) >= (l_ulong)-4095)
#define LINUX_INT_ERROR(x) (x < 0)

#define ASSERT(n, msg, ...) {if (!(n)) {panicf("ASSERTION FAILED at " __FUNCTION__ ", %s (%i) \r\n " msg " \r\n", __FILE__, __LINE__, __VA_ARGS__);}}