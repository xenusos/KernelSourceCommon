#pragma once

typedef struct rb_node {
	unsigned long  __rb_parent_color;
	struct rb_node *rb_right;
	struct rb_node *rb_left;
} *rb_node_k;


typedef struct rb_root {
	struct rb_node *rb_node;
} *rb_root_k;

/*
* Leftmost-cached rbtrees.
*
* We do not cache the rightmost node based on footprint
* size vs number of potential users that could benefit
* from O(1) rb_last(). Just not worth it, users that want
* this feature can always implement the logic explicitly.
* Furthermore, users that want to cache both pointers may
* find it a bit asymmetric, but that's ok.
*/
typedef struct rb_root_cached {
	struct rb_root rb_root;
	struct rb_node *rb_leftmost;
} *rb_root_cached_k;
