/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once


// Atomic words

typedef __declspec(align(8)) struct // force struct alignment, if retardly placed into a packed struct
{
    uint64_t  counter;
} atomic64_t;

typedef __declspec(align(4)) struct // force struct alignment, if retardly placed into a packed struct
{
    uint32_t  counter;
} atomic32_t, atomic_t;

//typedef int32_t atomic_t;
typedef uint32_t atomic_int_t;
typedef uint32_t atomic32_int_t;
typedef uint64_t atomic64_int_t;


// Linux size specific types

typedef uint64_t    u64;
typedef int64_t        s64;

typedef uint32_t    u32;
typedef int32_t        s32;

typedef uint16_t    u16;
typedef int16_t        s16;

typedef uint8_t        u8;
typedef int8_t        s8;


// Linux GCC 8 type mapping for AMD64

typedef u64            l_u64;
typedef s64            l_s64;

typedef u32            l_u32;
typedef s32            l_s32;

typedef u16            l_u16;
typedef s16            l_s16;

typedef u8            l_u8;
typedef s8            l_s8;

typedef int16_t        l_short;
typedef uint16_t    l_ushort;
typedef uint16_t    l_u_short;
typedef uint16_t    l_unsignedshort;
typedef uint16_t    l_unsigned_short;

typedef int64_t        l_long;
typedef uint64_t    l_ulong;
typedef uint64_t    l_u_long;
typedef uint64_t    l_unsignedlong;
typedef uint64_t    l_unsigned_long;

typedef int64_t        l_signedlong;
typedef int64_t        l_signed_long;

typedef int64_t        l_longlong;
typedef int64_t        l_long_long;
typedef uint64_t    l_ulonglong;
typedef uint64_t    l_u_long_long;
typedef uint64_t    l_unsignedlonglong;
typedef uint64_t    l_unsigned_long_long;

typedef int32_t        l_int;
typedef uint32_t    l_uint;


typedef int32_t        l_signed;
typedef int32_t        l_s;
typedef uint32_t    l_unsigned;
typedef uint32_t    l_u;

typedef int32_t        l_signed_int;
typedef uint32_t    l_unsigned_int;

