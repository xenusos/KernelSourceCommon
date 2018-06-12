#pragma once
XENUS_SYM error_t xenus_load_module(char * friendly_name, char * mod, char * path, void ** handle);
XENUS_SYM error_t xenus_load_plugin(char * name, char * mod, char * path);