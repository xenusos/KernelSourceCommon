/*
    Purpose: 
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson
*/
#pragma once

typedef struct
{
	char * key;
	char * value;
} mod_options_t;

typedef struct
{
	void * pe_handle;           // FROM KRN
	void * plugin_handle;       // FROM KRN

	const char * name;			// TO KRNL : name of dependency  
	const char * module;        // TO KRNL : name in IAT 
	const char * path;          // TO KRNL : path of executable
	bool soft_dependency;		// TO KRNL : is dependency soft or hard? 
	bool present;				// FROM KRN: in the "init" callback, use this member to check the state of your soft dependency. if you happen to depend on DIR_IMPORT & IAT for resolving and calling symbols, you'll find yourself panicing unless you check me :)
} *mod_dependency_opt_p, mod_dependency_opt_t;

typedef struct
{
	mod_dependency_opt_p dependencies;		// IN:
	uint32_t count;							// IN:
} *mod_dependency_list_p, mod_dependency_list_t;

typedef struct
{
	bool has_started;                                                      // OUT: KERN -> MOD, KERN -> KERN
	bool has_init;                                                         // OUT: KERN -> MOD, KERN -> KERN
	int status_code;													   // OUT: KERN -> MOD, KERN -> KERN, = xenus_entrypoint_ctx_t##init()

	void * pe_handle;
	void * plugin_handle;
} *mod_global_data_p, mod_global_data_t;

typedef struct
{
	size_t size;	
	bool (*init)(mod_dependency_list_p deps);								// IN: KERN <- MOD	| return false on error
	int (*start)(void);												    	// IN: KERN <- MOD	| return status code
	void (*shutdown)(void);													// IN: KERN <- MOD
	const char * description;														// IN: KERN <- MOD
	const char * copyright;														// IN: KERN <- MOD
	mod_dependency_list_t dependencies;										// IN: KERN <- MOD
	mod_global_data_p static_data;                                          // IN: KERN <- MOD (this is just a pointer to a struct within some section of your modules pe)
} *xenus_entrypoint_ctx_p, xenus_entrypoint_ctx_t;

typedef void(*entrypoint_t)(xenus_entrypoint_ctx_p context);