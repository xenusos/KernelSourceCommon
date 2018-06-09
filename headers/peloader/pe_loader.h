/*
    Purpose: 
    Author: Reece W. 
    License: All Rights Reserved J. Reece Wilson
*/  

#pragma once

XENUS_SYM error_t pe_loader_preload_init(void * buffer, size_t length, char * module_name, void ** handle);				// alloc buffers
XENUS_SYM error_t pe_loader_preload_analyse(void * handle);																// check pe
XENUS_SYM error_t pe_loader_preload_load(void * handle);																// 
 
XENUS_SYM error_t pe_loader_load(void * buffer, size_t length, char * module_name, void ** handle);
 
XENUS_SYM error_t pe_loader_postload_config_reloc(void * handle);
XENUS_SYM error_t pe_loader_postload_config_iat(void * handle, size_t * unresolved_symbols, size_t * resolved_symbols);

XENUS_SYM void* pe_loader_find_module(char * name);
XENUS_SYM error_t pe_loader_find_symbol (char * module, uint16_t ord, char * name, bool byordinal, void ** function_ptr);
XENUS_SYM error_t pe_loader_get_sym     (void * mod_, uint16_t ord, char * name, bool byordinal, void ** function_ptr);
XENUS_SYM error_t pe_loader_get_headers(void * handle, void ** dos, void ** nt, void ** opt, void ** segs);
// error_t pe_get_module_address(void * handle, void * virt_address, void ** out_address);
// error_t pe_check_charactistic(void * handle, size_t flag, bool ** state)
// error_t  pe_get_export_by_ordinal(void * handle, uint16_t ord, char ** name, void ** data_ptr)
// error_t  pe_get_export_by_name(void * handle, char * name, uint16_t * ord,void ** data_ptr)