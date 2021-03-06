#pragma once

// Note:
// For now, the kernel can't shutdown because im too lazy to create a shutdown callback
// Even if we could, odds are, we're just going to leak memory.
// For now, we're just not going to support the reloading of modules.

// Note 2: 
// You must create the linked list, not expect one
// You must understand that entry->data, or entry + sizeof(entry struct) = handle 
// You are responsible for the life span of the array and subsequent handles
// You must acknowledge that when you free the array, you will not free any of the modules (if possible, the pe loader api will do that)


#ifndef HAS_PLE_HANDLE
#define HAS_PL_HANDLE
typedef void * plugin_handle_h;
#endif

// recommended load function
XENUS_SYM error_t xenus_load_module(const char * friendly_name, const char * mod, const  char * path, pe_handle_h * pe_handle);
XENUS_SYM error_t plugins_load(const char * name, const char * mod, const char * path, linked_list_head_p plugins, pe_handle_h * root_pe_handle, plugin_handle_h* root_plugin_handle); // load plugin, patch iat, etc
                                                                                                                                                                                       // thread safe


// internal load functions - in order
XENUS_SYM error_t plugins_iterative_load(linked_list_head_p list, const char * mod, const char * name, const char * path, bool soft_dep, pe_handle_h * pe_handle_out, plugin_handle_h* plugin_handle_out);
XENUS_SYM void    plugins_initialize(linked_list_head_p list);
XENUS_SYM void    plugins_start(linked_list_head_p list);

XENUS_SYM error_t plugins_get_state             (plugin_handle_h handle);
XENUS_SYM error_t plugins_get_hard              (plugin_handle_h handle);
XENUS_SYM error_t plugins_get_status            (plugin_handle_h handle, size_t * status);
XENUS_SYM error_t plugins_has_init              (plugin_handle_h handle, bool * init);
XENUS_SYM error_t plugins_get_iat_module_name   (plugin_handle_h handle, const char ** name);
XENUS_SYM error_t plugins_get_friendly_name     (plugin_handle_h handle, const char ** name);
XENUS_SYM error_t plugins_get_path              (plugin_handle_h handle, const char ** path);
