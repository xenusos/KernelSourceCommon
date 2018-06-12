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
	const char * module;        // IN : name in IAT 
	const char * path;          // IN : path of executable
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
	//char * name;															// OUT:KERN -> MOD
	//char * module;															// OUT:KERN -> MOD
	void (*init)(mod_dependency_list_p deps);								// IN: KERN <- MOD
	void (*start)(void);													// IN: KERN <- MOD
	void (*shutdown)(void);													// IN: KERN <- MOD
	char * description;														// IN: KERN <- MOD
	char * copyright;														// IN: KERN <- MOD
	mod_dependency_list_t dependencies;										// IN: KERN <- MOD
} *xenus_entrypoint_ctx_p, xenus_entrypoint_ctx_t;

typedef void(*entrypoint_t)(xenus_entrypoint_ctx_p context);