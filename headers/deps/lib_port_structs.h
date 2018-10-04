/*
	Purpose: During compile time, this aids reading/writing to undefined structs with structural information that can only be provided at runtime.
	unsupported arbitrary modifiers, types, and other characteristics across compilers, networks, and/or processes are often a pain to deal with.
	Author: Reece W. (reece.sx)
	License: All Rights Reserved (2018)  J. Reece Wilson. Released under the MIT License.
*/
#pragma once

#ifndef __H_LIB_PORT_STRUCTS__
#define __H_LIB_PORT_STRUCTS__

#if defined(_MSC_VER) && _MSC_VER && !defined(_INC_MALLOC) && defined(XENUS_BUILD)
	//Xenus MSVC hack: _alloca is just an intrinsic function for sub rsp, x (plus clean up) - NOT APART OF MSCRT!
	void * _alloca(size_t len);
	#define alloca _alloca 
	#define _INC_MALLOC 1
 #endif

#define __PS_OFFSET_OF(type, name)		            	    (size_t) ((((((&((type *)(NULL))->name))))))
#define __PS_SIZEOF_MEM_OF(type, name)		        	    (size_t) sizeof(((type *)(NULL))->name)

#define PS_HEADER_GLOBAL_START typedef struct {
#define PS_HEADER_GLOBAL_END } ps_global_t; XENUS_BEGIN_C XENUS_SYM_VAR ps_global_t ps_global; XENUS_END_C

#define PS_HEADER_TYPE_START struct { uint16_t length; char name[TS_MAX_STRUCT_NAME_LENGTH];
#define PS_HEADER_TYPE_END(type, type_name) } ps_type_ ## type_name;


#define PS_HEADER_MEMBER(member, member_name) struct { uint16_t length; uint16_t offset; char name[TS_MAX_MEMBER_LENGTH];  } ps_member_ ## member_name;


#define PS_SRC_FUNC_START ps_global_t ps_global = { 0 };  void ps_initialize(void) { memset(&ps_global, 0, sizeof(ps_global));
#define PS_SRC_FUNC_END   }

#define __PS_SRC_FUNC_ADD_TYPE(type, type_name) strncat(ps_global.ps_type_ ## type_name.name, #type_name, TS_MAX_STRUCT_NAME_LENGTH);  ps_global.ps_type_ ## type_name.length = sizeof(type);
#define __PS_SRC_FUNC_ADD_TYPE_MEMBER(type, type_name, member, member_name)  strncat(ps_global.ps_type_ ## type_name.ps_member_ ## member_name.name , #member, TS_MAX_MEMBER_LENGTH); \
                                                                                     ps_global.ps_type_ ## type_name.ps_member_ ## member_name.length = __PS_SIZEOF_MEM_OF(type, member); \
                                                                                     ps_global.ps_type_ ## type_name.ps_member_ ## member_name.offset = __PS_OFFSET_OF(type, member);

#if defined PS_EXPORTING
	#define PS_SRC_FUNC_ADD_TYPE               __PS_SRC_FUNC_ADD_TYPE     
	#define PS_SRC_FUNC_ADD_TYPE_MEMBER        __PS_SRC_FUNC_ADD_TYPE_MEMBER       
#elif defined(PS_IMPORTING)
	#define PS_SRC_FUNC_ADD_TYPE(x, y)
	#define PS_SRC_FUNC_ADD_TYPE_MEMBER(x, y, z, a)
#endif

#define PS_HEADER_INIT_TYPE(type_name)\
static inline type_name ## _k  type_name ## _allocate()\
{\
    return zalloc(ps_global.ps_type_ ## type_name .length);\
}\
static inline void type_name ## _free(void * ptr)\
{\
    free(ptr);\
}\
static inline uint64_t type_name ## _size()\
{\
    return ps_global.ps_type_ ## type_name .length;\
}

#define PS_HEADER_INIT_MEMBER(type_name, member/*_name*/)\
static inline size_t type_name ## _sizeof_ ## member()\
{\
    return ps_global.ps_type_ ## type_name .ps_member_ ## member .length;\
}\
static inline void * type_name ## _get_ ## member (void * ptr) \
{\
    return (void *)((uint8_t *)ptr + (ps_global.ps_type_ ## type_name .ps_member_ ## member .offset));\
}\
static inline void type_name ## _set_ ## member(void * ptr, void * src)\
{\
    memcpy(type_name ## _get_ ## member(ptr), src, ps_global.ps_type_ ## type_name .ps_member_ ## member .offset);\
}\
static inline void type_name ## _set_ ## member ## _size_t(void * ptr, size_t set)\
{\
    *(size_t *)(type_name ## _get_ ## member(ptr)) = set;\
}\
static inline void type_name ## _set_ ## member ## _ssize_t(void * ptr, ssize_t set)\
{\
    *(ssize_t *)(type_name ## _get_ ## member(ptr)) = set;\
}\
static inline void type_name ## _set_ ## member ## _int64(void * ptr, int64_t set)\
{\
    *(int64_t *)(type_name ## _get_ ## member(ptr)) = set;\
}\
static inline void type_name ## _set_ ## member ## _uint64(void * ptr, uint64_t set)\
{\
    *(uint64_t *)(type_name ## _get_ ## member(ptr)) = set;\
}\
static inline void type_name ## _set_ ## member ## _int32(void * ptr, int32_t set)\
{\
    *(int32_t *)(type_name ## _get_ ## member(ptr)) = set;\
}\
static inline void type_name ## _set_ ## member ## _uint32(void * ptr, uint32_t set)\
{\
    *(uint32_t *)(type_name ## _get_ ## member(ptr)) = set;\
}\
static inline void type_name ## _set_ ## member ## _int16(void * ptr, int16_t set)\
{\
    *(int16_t *)(type_name ## _get_ ## member(ptr)) = set;\
}\
static inline void type_name ## _set_ ## member ## _uint16(void * ptr, uint16_t set)\
{\
    *(uint16_t *)(type_name ## _get_ ## member(ptr)) = set;\
}\
static inline void type_name ## _set_ ## member ## _int8(void * ptr, int8_t set)\
{\
    *(int8_t *)(type_name ## _get_ ## member(ptr)) = set;\
}\
static inline void type_name ## _set_ ## member ## _uint8(void * ptr, uint8_t set)\
{\
    *(uint8_t *)(type_name ## _get_ ## member(ptr)) = set;\
}\
static inline int64_t type_name ## _get_ ## member ## _int64(void * ptr)\
{\
    return *(int64_t *)(type_name ## _get_ ## member(ptr));\
}\
static inline uint64_t type_name ## _get_ ## member ## _uint64(void * ptr)\
{\
    return *(uint64_t *)(type_name ## _get_ ## member(ptr));\
}\
static inline int32_t type_name ## _get_ ## member ## _int32(void * ptr)\
{\
    return *(int32_t *)(type_name ## _get_ ## member(ptr));\
}\
static inline uint32_t type_name ## _get_ ## member ## _uint32(void * ptr)\
{\
    return *(uint32_t *)(type_name ## _get_ ## member(ptr));\
}\
static inline int16_t type_name ## _get_ ## member ## _int16(void * ptr)\
{\
    return *(int16_t *)(type_name ## _get_ ## member(ptr));\
}\
static inline uint16_t type_name ## _get_ ## member ## _uint16(void * ptr)\
{\
    return *(uint16_t *)(type_name ## _get_ ## member(ptr));\
}\
static inline int8_t type_name ## _get_ ## member ## _int8(void * ptr)\
{\
    return *(int8_t *)(type_name ## _get_ ## member(ptr));\
}\
static inline uint8_t type_name ## _get_ ## member ## _uint8(void * ptr)\
{\
    return *(uint8_t *)(type_name ## _get_ ## member(ptr));\
}\
static inline size_t type_name ## _get_ ## member ## _size_t(void * ptr)\
{\
    return *(size_t *)(type_name ## _get_ ## member(ptr));\
}\
static inline ssize_t type_name ## _get_ ## member ## _ssize_t(void * ptr)\
{\
    return *(ssize_t *)(type_name ## _get_ ## member(ptr));\
}

// Why do we do this?
// I think there was some issue with predecleration and/or i wanted this to be in a source file but wanted it all in a header. 


#ifdef PS_EXPORTING
	int ps_buffer_dump		(void * buffer, uint64_t size);
#elif defined(PS_IMPORTING)
	int ps_buffer_configure	(void * buffer, uint64_t length);
#endif
void	ps_initialize	(void);
int		ps_buffer_length(void);

#define __PS_HEADER_MAGIC	*(uint64_t*)("PORTTYPE")
#define __PS_LENGTH			sizeof(uint64_t) + sizeof(uint64_t) + sizeof(ps_global);

#ifdef PS_EXPORTING
	#define PS_SRC_DEFINE_STUBS														 \
		int ps_buffer_length()                                                       \
		{                                                                            \
		    return __PS_LENGTH;                                                      \
		}                                                                            \
		                                                                             \
		int ps_buffer_dump(void * buffer, uint64_t size)                             \
		{                                                                            \
		    size_t min_size;                                                         \
		                                                                             \
		    min_size = __PS_LENGTH;                                                  \
		                                                                             \
		    if (min_size > size)                                                     \
		        return 0;                                                            \
		                                                                             \
		    *((uint64_t*)buffer + 0) = __PS_HEADER_MAGIC;                            \
		    *((uint64_t*)buffer + 1) = sizeof(ps_global);                            \
		                                                                             \
		    memcpy((void *)((uint64_t*)buffer + 2),                                  \
		        (void *)&ps_global,                                                  \
		        sizeof(ps_global));                                                  \
		                                                                             \
		    return 1;                                                                \
		}

#elif defined(PS_IMPORTING)

	#define PS_SRC_DEFINE_STUBS														 \
		int ps_buffer_length()                                                       \
		{                                                                            \
		    return __PS_LENGTH;                                                      \
		}                                                                            \
															                         \
		int ps_buffer_configure(void * buffer, uint64_t length)	                     \
		{                                                                            \
		    size_t size;                                                             \
		                                                                             \
		    if (length == 0) return 1;                                               \
		                                                                             \
		    size = __PS_LENGTH;                                                      \
		                                                                             \
		    if (size > length)                                                       \
		        return 0;                                                            \
		                                                                             \
		    if (*((uint64_t*)buffer + 0) != __PS_HEADER_MAGIC)                       \
		        return 0;                                                            \
		                                                                             \
		    if (*((uint64_t*)buffer + 1) != sizeof(ps_global))                       \
		        return 0;                                                            \
		                                                                             \
		    memcpy((void *)&ps_global,                                               \
		        (void *)((uint64_t*)buffer + 2),                                     \
		        sizeof(ps_global));                                                  \
		                                                                             \
		    return 1;                                                                \
		}
#endif

#endif //!__H_LIB_PORT_STRUCTS__