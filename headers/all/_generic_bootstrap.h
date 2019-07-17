/*
    Purpose: Bootstrapped functions of the Linux Kernel for IO and general operations within the Xenos Kernel
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson (See License.txt)
    Depends on: xenus.h, xenus_types_kernel_(.*).h
*/
#pragma once

typedef struct 
{
    void (*test_function)                (size_t a_1, size_t a_2, size_t a_3, size_t a_4, size_t a_5, size_t a_6, size_t a_7, size_t a_8, size_t a_9, size_t a_10, size_t a_11, size_t a_12);
    int  (*print)                        (const char *fmt);
    void (*panic)                        (const char *fmt);
    void (* reload)                      (void(XENUS_MS_ABI * callback)(void));
} bootstrap_dbg_t;

typedef struct 
{
    void *    (* execalloc)              (size_t size);
    void      (* execfree)               (void * ptr);
    void *    (* kmalloc)                (size_t size, int flags);
    void *    (* vmalloc)                (size_t size);
    void      (* kfree)                  (void * ptr);
    void      (* vfree)                  (void * ptr);
    size_t    (* ksize)                  (const void * ptr);
    void *    (* memcpy)                 (void * dest, const void * src, size_t length);
    void *    (* memset)                 (void * dest, int c, size_t length);
    void *    (* memmove)                (void *dest, const void *src, size_t count);
    int       (* memcmp)                 (const void *cs, const void *ct, size_t count);
    void *    (* memscan)                (void *addr, int c, size_t size);
    uint64_t  (*linux_page_to_pfn)       (void * page_k_struct); // linux only nibbas
    void *    (*linux_pfn_to_page)       (uint64_t pfn); // linux only nibbas
} bootstrap_memory_t;

typedef struct {
    int       (* strcasecmp)             (const char *s1, const char *s2);
    int       (* strncasecmp)            (const char *s1, const char *s2, size_t n);
    char *    (* strncpy)                (char *dest, const char *src, size_t count);
    size_t    (* strlcpy)                (char *dest, const char *src, size_t size);
    char *    (* strcat)                 (char *dest, const char *src);
    char *    (* strncat)                (char *dest, const char *src, size_t count);
    size_t    (* strlcat)                (char *dest, const char *src, size_t count);
    int       (* strcmp)                 (const char * x, const char * y);
    int       (* strncmp)                (const char *cs, const char *ct, size_t count);
    char *    (* strchr)                 (const char *s, int c);
    char *    (* strrchr)                (const char *s, int c);
    char *    (* strnchr)                (const char *s, size_t count, int c);
    char *    (* skip_spaces)            (const char *str);
    char *    (* strim)                  (char *s);
    int       (* strlen)                 (const char * source);
    size_t    (* strnlen)                (const char *s, size_t count);
    size_t    (* strspn)                 (const char *s, const char *accept);
    size_t    (* strcspn)                (const char *s, const char *reject);
    char *    (* strpbrk)                (const char *cs, const char *ct);
    char *    (* strsep)                 (char **s, const char *ct);
    bool      (* sysfs_streq)            (const char *s1, const char *s2);
    int       (* strtobool)              (const char *s, bool *res);
    char *    (* strstr)                 (const char *s1, const char *s2);
    char *    (* strnstr)                (const char *s1, const char *s2, size_t len);
    char *    (* strcpy)                 (char * destination, const char * source);
} bootstrap_string_t;


typedef struct
{
    mutex_k   (* mutex_init)             (void);
    void      (* mutex_lock)             (mutex_k mutex);
    int       (* mutex_trylock)          (mutex_k mutex);
    void      (* mutex_unlock)           (mutex_k mutex);
    void      (* mutex_destroy)          (mutex_k mutex);
    int       (* mutex_is_locked)        (mutex_k mutex);
} bootstrap_mutex_t;                    

typedef struct
{
    void    (* kernel_fpu_begin)         (void); 
    void    (* kernel_fpu_end)           (void);
    void    (* __kernel_fpu_begin)       (void); 
    void    (* __kernel_fpu_end)         (void);

    task_k  (* create_thread_unsafe)     (thread_callback_t callback, void * data, const char * name, bool run);


    uint64_t (*    get_current_pid)      (void);
    task_k   (*    _current)             (void);
    
    thread_storage_data_p(* tls)         (void);

    void(*preempt_enable)                (void);
    void(*preempt_enable_reseched)       (void);
    void(*preempt_disable)               (void);
    
} bootstrap_cpu_t;


typedef struct
{
    void *(*file_open)                   (const char *path, int flags, int rights);

    void *(*file_open_readonly)          (const char *path);
    void *(*file_open_readwrite)         (const char *path);
    void *(*file_open_append)            (const char *path);

    int  (*file_read)                    (void *file, unsigned long long offset, unsigned char *data, size_t size);
    int  (*file_write)                   (void *file, unsigned long long offset, unsigned char *data, size_t size);
    long (*file_mode)                    (const char * file);
    long (*file_length)                  (const char * file);

    size_t (*file_mt)                    (const char * file);
    size_t (*file_ct)                    (const char * file);
    size_t (*file_at)                    (const char * file);

    int (*file_sync)                     (void *file);

    int (*file_close)                    (void *file);
} bootstrap_fio_helper_t;

typedef struct
{
    void *(*kallsyms_lookup_name)        (const char *name);
    void *(*__symbol_get)                (const char *name);
} bootstrap_symbols_t;

typedef struct 
{
    bootstrap_dbg_t           dbg;
    bootstrap_memory_t        memory;
    bootstrap_string_t        string;
    bootstrap_mutex_t         mutex;
    bootstrap_cpu_t           cpu;
    bootstrap_symbols_t       symbols;
    bootstrap_fio_helper_t    fio;
} bootstrap_t;

#define START_POINT(name) ssize_t name(void *xenos_start, bootstrap_t * bootstrap, void *  security, uint32_t sec_len, void * port_structs, uint32_t port_structs_length, linux_info_ref info)
//#if defined(COMMUNISM_COMPILER)
//    typedef ssize_t(__attribute__((ms_abi)) *kernel_startpoint_t)(void *xenos_start, bootstrap_t * bootstrap, void *  security, uint32_t sec_len, void * port_structs, uint32_t port_structs_length, linux_info_ref info);
//#else
    typedef ssize_t(XENUS_MS_ABI * kernel_startpoint_t)(void *xenos_start, bootstrap_t * bootstrap, void *  security, uint32_t sec_len, void * port_structs, uint32_t port_structs_length, linux_info_ref info);
//#endif

    

#define STAGE_ZERO_ERR    (0 + 1)
#define STAGE_ONE_ERR     (1 + 1)
#define STAGE_TWO_ERR     (2 + 1)
#define STAGE_THREE_ERR   (3 + 1)
#define STAGE_FOUR_ERR    (4 + 1)
#define STAGE_FIVE_ERR    (5 + 1)
