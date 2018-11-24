typedef struct 
{
	uint64_t	LINUX_THREAD_SIZE_ORDER;
	uint64_t	LINUX_THREAD_SIZE;
	uint64_t	LINUX_PAGE_SHIFT;
	uint64_t	LINUX_PAGE_SIZE;
	uint64_t	LINUX_PAGE_MASK;
	uint64_t	LINUX_PMD_PAGE_SIZE;
	uint64_t	LINUX_PMD_PAGE_MASK;
	uint64_t	LINUX_PUD_PAGE_SIZE;
	uint64_t	LINUX_PUD_PAGE_MASK;
	uint64_t	LINUX___PHYSICAL_MASK;
	uint64_t	LINUX___VIRTUAL_MASK;
	signed long	LINUX_PHYSICAL_PAGE_MASK;
	signed long	LINUX_PHYSICAL_PMD_PAGE_MASK;
	signed long	LINUX_PHYSICAL_PUD_PAGE_MASK;
	uint64_t	LINUX_HPAGE_SHIFT;
	uint64_t	LINUX_HPAGE_SIZE;
	uint64_t	LINUX_HPAGE_MASK;
	uint64_t	LINUX_HUGETLB_PAGE_ORDER;
	uint64_t	LINUX_HUGE_MAX_HSTATE;
	uint64_t	LINUX_PAGE_OFFSET;
	uint64_t	LINUX___PHYSICAL_START;
	uint64_t	LINUX___START_KERNEL;

    uint64_t    LINUX_VMALLOC_START;
    uint64_t    LINUX_VMALLOC_END;
    uint64_t    LINUX_VMALLOC_SIZE_TB;
    uint64_t    LINUX_LDT_PGD_ENTRY_L4;
    uint64_t    LINUX_LDT_PGD_ENTRY_L5;
    uint64_t    LINUX_LDT_PGD_ENTRY;
    uint64_t    LINUX_LDT_BASE_ADDR;

    int64_t     KERNEL_FREQUENCY;
} linux_info_t,
 *linux_info_p,
 *linux_info_ref;

#if !defined(XENUS_PLATFORM_LINUX_KERNEL)
	#define OS_THREAD_SIZE_ORDER       kernel_information.LINUX_THREAD_SIZE_ORDER       
	#define OS_THREAD_SIZE             kernel_information.LINUX_THREAD_SIZE             
	#define OS_PAGE_SHIFT              kernel_information.LINUX_PAGE_SHIFT              
	#define OS_PAGE_SIZE               kernel_information.LINUX_PAGE_SIZE               
	#define OS_PAGE_MASK               kernel_information.LINUX_PAGE_MASK               
	#define OS_PMD_PAGE_SIZE           kernel_information.LINUX_PMD_PAGE_SIZE           
	#define OS_PMD_PAGE_MASK           kernel_information.LINUX_PMD_PAGE_MASK           
	#define OS_PUD_PAGE_SIZE           kernel_information.LINUX_PUD_PAGE_SIZE           
	#define OS_PUD_PAGE_MASK           kernel_information.LINUX_PUD_PAGE_MASK           
	#define OS___PHYSICAL_MASK         kernel_information.LINUX___PHYSICAL_MASK         
	#define OS___VIRTUAL_MASK          kernel_information.LINUX___VIRTUAL_MASK          
	#define OS_PHYSICAL_PAGE_MASK      kernel_information.LINUX_PHYSICAL_PAGE_MASK      
	#define OS_PHYSICAL_PMD_PAGE_MASK  kernel_information.LINUX_PHYSICAL_PMD_PAGE_MASK  
	#define OS_PHYSICAL_PUD_PAGE_MASK  kernel_information.LINUX_PHYSICAL_PUD_PAGE_MASK  
	#define OS_HPAGE_SHIFT             kernel_information.LINUX_HPAGE_SHIFT             
	#define OS_HPAGE_SIZE              kernel_information.LINUX_HPAGE_SIZE              
	#define OS_HPAGE_MASK              kernel_information.LINUX_HPAGE_MASK              
	#define OS_HUGETLB_PAGE_ORDER      kernel_information.LINUX_HUGETLB_PAGE_ORDER      
	#define OS_HUGE_MAX_HSTATE         kernel_information.LINUX_HUGE_MAX_HSTATE         
	#define OS_PAGE_OFFSET             kernel_information.LINUX_PAGE_OFFSET             
	#define OS___PHYSICAL_START        kernel_information.LINUX___PHYSICAL_START        
	#define OS___START_KERNEL          kernel_information.LINUX___START_KERNEL       
#endif