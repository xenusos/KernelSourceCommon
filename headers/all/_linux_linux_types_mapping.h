/*
    Purpose:
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson (See License.txt)
*/

typedef struct cpumask *  cpumask_k;
typedef void *            unknown_k;

#define DEFINE_TYPE(y, x) typedef y *            x ## _k;
#include "_unknown_types.macros"
#undef DEFINE_TYPE

//TODO: types 