#pragma once

typedef struct llist_head {
	struct llist_node *first;
} *llist_head_k;

typedef struct llist_node {
	struct llist_node *next;
}*llist_node_k;


typedef struct list_head {
    volatile struct list_head *next, *prev; 
} *list_head_k;

typedef struct hlist_head {
	struct hlist_node *first;
} *hlist_head_k;

typedef struct hlist_node {
	struct hlist_node *next, **pprev;
} *hlist_node_k;


#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({			\
	const typeof(((type *)0)->member) * __mptr = (ptr);	\
	(type *)((char *)__mptr - offsetof(type, member)); })


#define READ_ONCE(ptr) ptr

#define list_entry_rcu(ptr, type, member) \
	container_of(READ_ONCE(ptr), type, member)