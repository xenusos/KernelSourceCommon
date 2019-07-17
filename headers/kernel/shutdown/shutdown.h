/*
    Purpose:
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson (See License.txt)
    Depends: xenus.h
*/
#pragma once

typedef void(*shutdown_handler_p)();

XENUS_SYM void shutdown_add_hook(shutdown_handler_p hook);