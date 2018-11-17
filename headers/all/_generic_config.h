#pragma once

// #define KENREL_DYNAMIC_EXPORTS			| deprecated
// #define KERNEL_MODULE_IN_PE_LOADER		| deprecated

#define KERNEL_BOOTSTRAP_FUNCTIONS_AMD64SYSV

// #define KERNEL_THREADING_DBG_CSWITCHING
// #define CONFIG_DBG_LIBCOM_MEM

#define PRINTF_MAX_STRING_LENGTH  2048 * 2

#define C_NULL_CHAR 1
#define PE_MAX_MODULE_LENGTH 20  + C_NULL_CHAR
#define PE_MAX_SYMBOL_LENGTH 100 + C_NULL_CHAR

#define CONFIG_PANIC_DBG

// warning: increasing the following will result in significantly higher memory usage
#define TS_MAX_STRUCT_NAME_LENGTH	20
#define TS_MAX_MEMBER_LENGTH		20


#define DYNAMIC_TYPES_CHECK_LENGTH 1

#ifndef LISTS_MIN_APPEND_SIZE
#define LISTS_MIN_APPEND_SIZE 10
// [] = reserved block, [x] allocated block 
//
// []  []  []  []  []  []  []  []  []  [] = 10
// [X] []  []  []  []  []  []  []  []  [] 
// [X] [X] []  []  []  []  []  []  []  [] 
// [X] [X] [X] []  []  []  []  []  []  [] 
// [X] [X] [X] [X] []  []  []  []  []  [] 
// [X] [X] [X] [X] [X] []  []  []  []  [] 
// [X] [X] [X] [X] [X] [X] []  []  []  [] 
// [X] [X] [X] [X] [X] [X] [X] []  []  [] 
// [X] [X] [X] [X] [X] [X] [X] [X] []  [] 
// [X] [X] [X] [X] [X] [X] [X] [X] [X] [] 
// [X] [X] [X] [X] [X] [X] [X] [X] [X] [X] []  []  []  []  []  []  []  []  []  [] 
// [X] [X] [X] [X] [X] [X] [X] [X] [X] [X] [X] []  []  []  []  []  []  []  []  [] 
#endif

#define STDOUT_BUFFER_LENGTH 2048
#define STDOUT_BUFFER_LENGTH_W_NULL 2049


#define BOOTSTRAP_DLL "/Xenus/Kernel/Kernel.xdll"

#define TGT_KRN_LINUX 1

// enable the following is stack size becomes an issue
