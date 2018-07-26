typedef struct {
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
} linux_info_t,
 *linux_info_p,
 *linux_info_ref;

#if !defined(XENUS_PLATFORM_LINUX_KERNEL)
	XENUS_SYM linux_info_t linux_mem_types;
	#define OS_THREAD_SIZE_ORDER       linux_mem_types.LINUX_THREAD_SIZE_ORDER       
	#define OS_THREAD_SIZE             linux_mem_types.LINUX_THREAD_SIZE             
	#define OS_PAGE_SHIFT              linux_mem_types.LINUX_PAGE_SHIFT              
	#define OS_PAGE_SIZE               linux_mem_types.LINUX_PAGE_SIZE               
	#define OS_PAGE_MASK               linux_mem_types.LINUX_PAGE_MASK               
	#define OS_PMD_PAGE_SIZE           linux_mem_types.LINUX_PMD_PAGE_SIZE           
	#define OS_PMD_PAGE_MASK           linux_mem_types.LINUX_PMD_PAGE_MASK           
	#define OS_PUD_PAGE_SIZE           linux_mem_types.LINUX_PUD_PAGE_SIZE           
	#define OS_PUD_PAGE_MASK           linux_mem_types.LINUX_PUD_PAGE_MASK           
	#define OS___PHYSICAL_MASK         linux_mem_types.LINUX___PHYSICAL_MASK         
	#define OS___VIRTUAL_MASK          linux_mem_types.LINUX___VIRTUAL_MASK          
	#define OS_PHYSICAL_PAGE_MASK      linux_mem_types.LINUX_PHYSICAL_PAGE_MASK      
	#define OS_PHYSICAL_PMD_PAGE_MASK  linux_mem_types.LINUX_PHYSICAL_PMD_PAGE_MASK  
	#define OS_PHYSICAL_PUD_PAGE_MASK  linux_mem_types.LINUX_PHYSICAL_PUD_PAGE_MASK  
	#define OS_HPAGE_SHIFT             linux_mem_types.LINUX_HPAGE_SHIFT             
	#define OS_HPAGE_SIZE              linux_mem_types.LINUX_HPAGE_SIZE              
	#define OS_HPAGE_MASK              linux_mem_types.LINUX_HPAGE_MASK              
	#define OS_HUGETLB_PAGE_ORDER      linux_mem_types.LINUX_HUGETLB_PAGE_ORDER      
	#define OS_HUGE_MAX_HSTATE         linux_mem_types.LINUX_HUGE_MAX_HSTATE         
	#define OS_PAGE_OFFSET             linux_mem_types.LINUX_PAGE_OFFSET             
	#define OS___PHYSICAL_START        linux_mem_types.LINUX___PHYSICAL_START        
	#define OS___START_KERNEL          linux_mem_types.LINUX___START_KERNEL       
#endif