/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#if !(defined(XENUS_BUILD))
    #error XENUS_BUILD must be defined
#endif

#include <xenus_lazy.h> // load everything from kernel.lib/kernel.xdll
#include <libtypes.hpp> // enable usage of libostypes (each type must be included individually and seperately)
#include <libcompiler.hpp>
#include <libos.hpp> 