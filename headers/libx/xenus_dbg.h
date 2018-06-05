#pragma once

//#include <sys/sys_dbg.h>

static int printf(const char *fmt, ...)
{
	char msg[2049];
	va_list ap;

	msg[0] = 0;

	va_start(ap, fmt);
	vsnprintf(msg, 2048, fmt, ap); //TODO check response
	va_end(ap);

	return print(msg);
}

static void panicf(const char *fmt, ...)
{
	char msg[2049];
	va_list ap;

	msg[0] = 0;

	va_start(ap, fmt);
	vsnprintf(msg, 2048, fmt, ap); //TODO check response
	va_end(ap);

	panic(msg);
}

//int atexit(void(*func)(void));
