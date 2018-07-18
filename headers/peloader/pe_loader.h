/*
    Purpose: 
    Author: Reece W. 
    License: All Rights Reserved J. Reece Wilson
*/  

#pragma once

////////////////////////////////////////////////////////////////////////////////////////
// Loading
////////////////////////////////////////////////////////////////////////////////////////

XENUS_SYM error_t pe_loader_preload_init(void * buffer, size_t length, char * module_name, void ** handle);				// alloc buffers
XENUS_SYM error_t pe_loader_preload_analyse(void * handle);																// check pe FILE (not in memory image)
XENUS_SYM error_t pe_loader_preload_load(void * handle);																// 
 
XENUS_SYM error_t pe_loader_load(void * buffer, size_t length, char * module_name, void ** handle);

////////////////////////////////////////////////////////////////////////////////////////
// Relocation
////////////////////////////////////////////////////////////////////////////////////////

XENUS_SYM error_t pe_loader_postload_config_reloc(void * handle);

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


XENUS_SYM error_t pe_loader_postload_iat_swap_module			(void * handle,	char * original, char * replacement); // use this to fix, for instance, windows drivers that depend on HAL when such functions are implemented else where (ntoskrnl)
XENUS_SYM error_t pe_loader_postload_iat_swap_symbol_byname		(void * handle, char * module,	char * original, char * replacement); // or use this to redirect symbols
XENUS_SYM error_t pe_loader_postload_iat_swap_symbol_byordinal	(void * handle, char * module, int ordinal, char * replacement); // or use this to redirect symbols


XENUS_SYM error_t pe_loader_postload_get_iat_length(void * handle, uint64_t * length);


XENUS_SYM error_t pe_loader_postload_config_iat_legacy(void * handle, size_t * unresolved_symbols, size_t * resolved_symbols); //this is slow and only really exists to not break legacy code.
XENUS_SYM error_t pe_loader_postload_config_iat_new(void * handle, iat_patch_result_ref reference); 

#define pe_loader_postload_config_iat pe_loader_postload_config_iat_legacy


////////////////////////////////////////////////////////////////////////////////////////
// EXPORTS
////////////////////////////////////////////////////////////////////////////////////////

XENUS_SYM error_t pe_loader_find_symbol_bymodname	(char * module, uint16_t ord, char * name, bool byordinal, void ** function_ptr);
XENUS_SYM error_t pe_loader_find_symbol_bymodhandle(void * module, uint16_t ord, char * name, bool byordinal, void ** function_ptr);



////////////////////////////////////////////////////////////////////////////////////////
// Lookup/generic
////////////////////////////////////////////////////////////////////////////////////////

XENUS_SYM void* pe_loader_find_module(char * name);
XENUS_SYM error_t pe_loader_get_headers(void * handle, void ** dos, void ** nt, void ** opt, void ** segs);


// APIs i was considering adding in feb-ish before anything was implemented
// error_t pe_get_module_address(void * handle, void * virt_address, void ** out_address);
// error_t pe_check_charactistic(void * handle, size_t flag, bool ** state)
// error_t  pe_get_export_by_ordinal(void * handle, uint16_t ord, char ** name, void ** data_ptr)
// error_t  pe_get_export_by_name(void * handle, char * name, uint16_t * ord,void ** data_ptr)