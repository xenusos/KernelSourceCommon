#pragma once

#define KENREL_DYNAMIC_EXPORTS

// #define KERNEL_THREADING_DBG_CSWITCHING

#define KERNEL_MODULE_IN_PE_LOADER 

#define PE_MAX_MODULE_LENGTH 20
#define PE_MAX_SYMBOL_LENGTH 100

// warning: increasing the following will result in significantly higher memory usage
#define TS_MAX_STRUCT_NAME_LENGTH	20
#define TS_MAX_MEMBER_LENGTH		20