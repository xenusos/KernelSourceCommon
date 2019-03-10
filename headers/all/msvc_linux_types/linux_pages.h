typedef struct {
    uint64_t val;
} pfn_t;

typedef struct
{
    pteval_t pte;
} pte_t;

typedef struct pgprot
{
    pgprotval_t pgprot_;
} pgprot_t;
typedef struct { pgdval_t pgd; } pgd_t;


#define pgprot_val(x)    ((x).pgprot)

#define __pte(x)    ((pte_t) { (x) } )
#define __pgd(x)    ((pgd_t) { (x) } )
#ifndef __cplusplus
#define __pgprot(x)    ((pgprot_t) { (x) } )
#else
#define __pgprot(x)    { (x) }
#endif
#define __AC(X,Y)            (X##Y)
#define _AC(X,Y)            __AC(X,Y)
#define _AT(T,X)            ((T)(X))

#if defined(AMD64)
#if defined(DANGEROUS_PAGE_LOGIC)
enum page_cache_mode {
    _PAGE_CACHE_MODE_WB = 0,
    _PAGE_CACHE_MODE_WC = 1,
    _PAGE_CACHE_MODE_UC_MINUS = 2,
    _PAGE_CACHE_MODE_UC = 3,
    _PAGE_CACHE_MODE_WT = 4,
    _PAGE_CACHE_MODE_WP = 5,
    _PAGE_CACHE_MODE_NUM = 8
};

#define _PAGE_BIT_PRESENT    0    /* is present */
#define _PAGE_BIT_RW        1    /* writeable */
#define _PAGE_BIT_USER        2    /* userspace addressable */
#define _PAGE_BIT_PWT        3    /* page write through */
#define _PAGE_BIT_PCD        4    /* page cache disabled */
#define _PAGE_BIT_ACCESSED    5    /* was accessed (raised by CPU) */
#define _PAGE_BIT_DIRTY        6    /* was written to (raised by CPU) */
#define _PAGE_BIT_PSE        7    /* 4 MB (or 2MB) page */
#define _PAGE_BIT_PAT        7    /* on 4KB pages */
#define _PAGE_BIT_GLOBAL    8    /* Global TLB entry PPro+ */
#define _PAGE_BIT_SOFTW1    9    /* available for programmer */
#define _PAGE_BIT_SOFTW2    10    /* " */
#define _PAGE_BIT_SOFTW3    11    /* " */
#define _PAGE_BIT_PAT_LARGE    12    /* On 2MB or 1GB pages */
#define _PAGE_BIT_SOFTW4    58    /* available for programmer */
#define _PAGE_BIT_PKEY_BIT0    59    /* Protection Keys, bit 1/4 */
#define _PAGE_BIT_PKEY_BIT1    60    /* Protection Keys, bit 2/4 */
#define _PAGE_BIT_PKEY_BIT2    61    /* Protection Keys, bit 3/4 */
#define _PAGE_BIT_PKEY_BIT3    62    /* Protection Keys, bit 4/4 */
#define _PAGE_BIT_NX        63    /* No execute: only valid after cpuid check */

#define _PAGE_BIT_SPECIAL     _PAGE_BIT_SOFTW1
#define _PAGE_BIT_CPA_TEST     _PAGE_BIT_SOFTW1
#define _PAGE_BIT_SOFT_DIRTY _PAGE_BIT_SOFTW3
#define _PAGE_BIT_DEVMAP     _PAGE_BIT_SOFTW4

#define _PAGE_BIT_PROTNONE  _PAGE_BIT_GLOBAL

#define _PAGE_PRESENT    (_AT(pteval_t, 1) << _PAGE_BIT_PRESENT)
#define _PAGE_RW    (_AT(pteval_t, 1) << _PAGE_BIT_RW)
#define _PAGE_USER    (_AT(pteval_t, 1) << _PAGE_BIT_USER)
#define _PAGE_PWT    (_AT(pteval_t, 1) << _PAGE_BIT_PWT)
#define _PAGE_PCD    (_AT(pteval_t, 1) << _PAGE_BIT_PCD)
#define _PAGE_ACCESSED    (_AT(pteval_t, 1) << _PAGE_BIT_ACCESSED)
#define _PAGE_DIRTY    (_AT(pteval_t, 1) << _PAGE_BIT_DIRTY)
#define _PAGE_PSE    (_AT(pteval_t, 1) << _PAGE_BIT_PSE)
#define _PAGE_GLOBAL    (_AT(pteval_t, 1) << _PAGE_BIT_GLOBAL)
#define _PAGE_SOFTW1    (_AT(pteval_t, 1) << _PAGE_BIT_SOFTW1)
#define _PAGE_SOFTW2    (_AT(pteval_t, 1) << _PAGE_BIT_SOFTW2)
#define _PAGE_PAT    (_AT(pteval_t, 1) << _PAGE_BIT_PAT)
#define _PAGE_PAT_LARGE (_AT(pteval_t, 1) << _PAGE_BIT_PAT_LARGE)
#define _PAGE_SPECIAL    (_AT(pteval_t, 1) << _PAGE_BIT_SPECIAL)
#define _PAGE_CPA_TEST    (_AT(pteval_t, 1) << _PAGE_BIT_CPA_TEST)

#define _PAGE_NX    (_AT(pteval_t, 1) << _PAGE_BIT_NX)
#define _PAGE_DEVMAP    (_AT(u64, 1) << _PAGE_BIT_DEVMAP)
#define __HAVE_ARCH_PTE_DEVMAP

#define _PAGE_PROTNONE    (_AT(pteval_t, 1) << _PAGE_BIT_PROTNONE)

#define _PAGE_TABLE_NOENC    (_PAGE_PRESENT | _PAGE_RW | _PAGE_USER |\
                 _PAGE_ACCESSED | _PAGE_DIRTY)
#define _KERNPG_TABLE_NOENC    (_PAGE_PRESENT | _PAGE_RW |        \
                 _PAGE_ACCESSED | _PAGE_DIRTY)

#define _PAGE_CACHE_MASK    (_PAGE_PAT | _PAGE_PCD | _PAGE_PWT)

#define PAGE_NONE    __pgprot(_PAGE_PROTNONE | _PAGE_ACCESSED)
#define PAGE_SHARED    __pgprot(_PAGE_PRESENT | _PAGE_RW | _PAGE_USER |  _PAGE_ACCESSED | _PAGE_NX)
#endif

#define PAGE_SHIFT            (OS_PAGE_SHIFT)
#define PAGE_SIZE            (_AC(1,ULL) << PAGE_SHIFT)
#define PAGE_MASK            (~(PAGE_SIZE-1))

#define PFN_ALIGN(x)        (((unsigned long)(x) + (PAGE_SIZE - 1)) & PAGE_MASK)
#define PFN_UP(x)            (((x) + PAGE_SIZE-1) >> PAGE_SHIFT)
#define PFN_DOWN(x)            ((x) >> PAGE_SHIFT)
#define PFN_PHYS(x)            ((phys_addr_t)(x) << PAGE_SHIFT)
#define PHYS_PFN(x)            ((unsigned long)((x) >> PAGE_SHIFT))

#endif