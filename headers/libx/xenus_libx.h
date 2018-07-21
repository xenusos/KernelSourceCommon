/*
    Purpose:
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
	Depends: xenus.h
*/
#pragma once


XENUS_BEGIN_C
#include <libx\xenus_memory.h>
#include <libx\xenus_strings.h>
#include <libx\xenus_threads.h>
#include <libx\xenus_chain.h>
#include <libx\xenus_dynbuffer.h>
#include <libx\xenus_dynbuffer_ts.h>
#include <libx\xenus_list_dyn.h>
#include <libx\xenus_list_dyn_ts.h>
#include <libx\xenus_list_linked.h>
#include <libx\xenus_win_support.h>

#ifndef KERNEL
#include <libx\xenus_dbg.h> 
#else
// use stage2_sys.h
#endif

XENUS_END_C