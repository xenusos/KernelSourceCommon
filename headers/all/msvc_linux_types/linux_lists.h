#pragma once

typedef struct llist_head {
	struct llist_node *first;
} *llist_head_k;

typedef struct llist_node {
	struct llist_node *next;
}*llist_node_k;


typedef struct list_head {
	struct list_head *next, *prev;
} *list_head_k;

typedef struct hlist_head {
	struct hlist_node *first;
} *hlist_head_k;

typedef struct hlist_node {
	struct hlist_node *next, **pprev;
} *hlist_node_k;
