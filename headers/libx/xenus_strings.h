#pragma once

XENUS_SYM size_t vsnprintf(char *buf, size_t size, const char *fmt, va_list ap);
XENUS_SYM size_t vsprintf(char *buf, const char *fmt, va_list ap);