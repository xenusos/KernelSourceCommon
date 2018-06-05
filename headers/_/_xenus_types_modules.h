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
	const char * name;			// IN : name of dependency  
	bool soft_dependency;		// IN : is dependency soft or hard? 
	bool present;				// OUT: in the "init" callback, use this member to check the state of your soft dependency. if you happen to depend on DIR_IMPORT & IAT for resolving and calling symbols, you'll find yourself panicing unless you check me :)
} *mod_dependency_opt_p, mod_dependency_opt_t;

typedef struct
{
	mod_dependency_opt_p dependencies;		// IN:
	uint32_t count;							// IN:
} *mod_dependency_list_p, mod_dependency_list_t;

typedef struct
{
	void(*init)(mod_dependency_list_p deps, mod_options_t *args, uint32_t argsc);		// IN: 
	void(*start)(void);																	// IN: 
	void(*shutdown)(void);																// IN: 
	char * name;																		// IN: 
	char * description;																	// IN: 
	char * copyright;																	// IN: 
	mod_dependency_list_t dependencies;													// IN: 
} *xenus_entrypoint_ctx_p, xenus_entrypoint_ctx_t;

typedef void(*entrypoint_t)(xenus_entrypoint_ctx_p context);