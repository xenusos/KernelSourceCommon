/*
    Purpose: Linked list
    Author: Reece W.
    License: All Rights Reserved J. Reece Wilson (See License.txt)
    Depends on: xenus.h
*/
#pragma once

struct linked_list_entry_s;

typedef struct linked_list_head_s
{
    struct linked_list_entry_s * bottom; // head, idx = 0
    struct linked_list_entry_s * top;    // tail, idx = count - 1
    struct
    {
        /*
            If a list is designed to be populated once, then set a callback handler.
            Once the list is empty, the list is marked dead, and the callback handler is triggered.
            If no callback handler is present, the list WILL NOT BE MARKED DEAD, and will continue to operate normally as if it was a new list with zero entries.
        */
        bool dead;
        void(*cb_died)(struct linked_list_head_s * ctx);
    };
    size_t length;
} *linked_list_head_p, linked_list_head_t;

typedef struct linked_list_entry_s
{
    union
    {
        void * end_of_struct;
        void * data;
    };
    struct linked_list_entry_s * before;
    struct linked_list_entry_s * next;
    linked_list_head_p head;
} *linked_list_entry_p, linked_list_entry_t;

XENUS_SYM linked_list_head_p linked_list_create();
XENUS_SYM linked_list_entry_p linked_list_append(linked_list_head_p head, size_t buf_len);    // O(1)
XENUS_SYM error_t linked_list_remove(linked_list_entry_p entry);                              // O(1)
XENUS_SYM error_t linked_list_destroy(linked_list_head_p head);
