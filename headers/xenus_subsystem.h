#if !(defined(XENUS_BUILD))
	#error XENUS_BUILD must be defined
#endif

#include <xenus_lazy.h> // load everything from kernel.lib/kernel.xdll
#include <libtypes.hpp> // enable usage of libostypes (each type must be included individually and seperately)
#include <libxenus.hpp> // enable usage of libos ("libxenus")
						// what does it even do? O.o