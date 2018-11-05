/*
    Purpose: 
    Author: Reece W. 
    License: All Rights Reserved J. Reece Wilson
*/  

#pragma once

#ifndef HAS_PE_HANDLE
#define HAS_PE_HANDLE
typedef void * pe_handle_h;
#endif

////////////////////////////////////////////////////////////////////////////////////////
// Loading
////////////////////////////////////////////////////////////////////////////////////////

XENUS_SYM error_t pe_loader_preload_init(pe_handle_h buffer, size_t length, const char * module_name, pe_handle_h* handle);		// alloc buffers
XENUS_SYM error_t pe_loader_preload_analyse(pe_handle_h handle);																// check pe FILE (not in memory image)
XENUS_SYM error_t pe_loader_preload_load(pe_handle_h handle);																// 
 
XENUS_SYM error_t pe_loader_load(void * buffer, size_t length, const char * module_name, pe_handle_h* handle);

////////////////////////////////////////////////////////////////////////////////////////
// Relocation
////////////////////////////////////////////////////////////////////////////////////////

XENUS_SYM error_t pe_loader_postload_config_reloc(pe_handle_h handle);

////////////////////////////////////////////////////////////////////////////////////////
// IAT
////////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
	const char * module;
	bool is_str;
	union
	{
		char * symbol;
		int idx;
	};
	bool found;
} *iat_patch_entry_p, *iat_patch_entry_ref, iat_patch_entry_t;

typedef struct
{
	size_t list_size;		    // to be populated by caller
	iat_patch_entry_ref list;   // to be populated by caller

	size_t entries_appended;    // to be populated by callee
	size_t entries_total;	    // to be populated by callee
} *iat_patch_result_p, *iat_patch_result_ref,  iat_patch_result_t;


XENUS_SYM error_t pe_loader_postload_iat_add_symbol_byname(pe_handle_h handle, const char * symbol, void * replacement);
//XENUS_SYM error_t pe_loader_postload_iat_swap_module			(pe_handle_h handle, const char * original, const char * replacement); // use this to fix, for instance, windows drivers that depend on HAL when such functions are implemented else where (ntoskrnl)
//XENUS_SYM error_t pe_loader_postload_iat_swap_symbol_byname		(pe_handle_h handle, const char * module,	const char * original, void *replacement); // or use this to redirect symbols
//XENUS_SYM error_t pe_loader_postload_iat_swap_symbol_byordinal	(pe_handle_h handle, const char * module,   int ordinal,           void *replacement); // or use this to redirect symbols

//implemented:
XENUS_SYM error_t pe_loader_postload_get_iat_length(pe_handle_h handle, uint64_t * length);

XENUS_SYM error_t pe_loader_postload_config_iat_legacy(pe_handle_h handle, size_t * unresolved_symbols, size_t * resolved_symbols); //this is slow and only really exists to not break legacy code.
XENUS_SYM error_t pe_loader_postload_config_iat_new(pe_handle_h handle, iat_patch_result_ref reference); 

#define pe_loader_postload_config_iat pe_loader_postload_config_iat_legacy


////////////////////////////////////////////////////////////////////////////////////////
// EXPORTS
////////////////////////////////////////////////////////////////////////////////////////

XENUS_SYM error_t pe_loader_find_symbol_bymodname  (const char * module, uint16_t ord, const char * name, bool byordinal, void ** data);
XENUS_SYM error_t pe_loader_find_symbol_bymodhandle(pe_handle_h module, uint16_t ord, const char * name, bool byordinal, void ** data);

////////////////////////////////////////////////////////////////////////////////////////
// Lookup/generic
////////////////////////////////////////////////////////////////////////////////////////

XENUS_SYM void* pe_loader_find_module(const char * name);
XENUS_SYM error_t pe_loader_get_headers(pe_handle_h handle, void ** dos, void ** nt, void ** opt, void ** segs);


// APIs i was considering adding in feb-ish before anything was implemented
// error_t pe_get_module_address(pe_handle_h handle, pe_handle_h virt_address, pe_handle_h* out_address);
// error_t pe_check_charactistic(pe_handle_h handle, size_t flag, bool ** state)
// error_t  pe_get_export_by_ordinal(pe_handle_h handle, uint16_t ord, char ** name, pe_handle_h* data_ptr)
// error_t  pe_get_export_by_name(pe_handle_h handle, char * name, uint16_t * ord,pe_handle_h* data_ptr)

////////////////////////////////////////////////////////////////////////////////////////
// Lists
////////////////////////////////////////////////////////////////////////////////////////
XENUS_SYM error_t pe_loader_iterate(void(*)(pe_handle_h, void *), void *);

////////////////////////////////////////////////////////////////////////////////////////
// Thread safety
////////////////////////////////////////////////////////////////////////////////////////
XENUS_SYM void pe_loader_enter_critical();
XENUS_SYM void pe_loader_leave_critical();

