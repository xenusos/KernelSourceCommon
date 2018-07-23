#pragma once

struct llist_head {
	struct llist_node *first;
};

struct llist_node {
	struct llist_node *next;
};


struct list_head {
	struct list_head *next, *prev;
};

struct hlist_head {
	struct hlist_node *first;
};

struct hlist_node {
	struct hlist_node *next, **pprev;
};
