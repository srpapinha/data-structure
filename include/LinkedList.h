#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    struct Node * previous;
    struct Node * next;
    void * data;
} Node;

typedef struct LinkedList {
    struct Node * first;
    struct Node * last;
    size_t data_size;
    int size;
} LinkedList;

LinkedList * initLinkedList(size_t data_size);
Node * initNode(Node * previous, Node * next, void * data);
void linkedlist_add(LinkedList * list, void * data);
void linkedlist_copy(LinkedList * list, void * data);
Node * linkedlist_node(LinkedList * list, int index);
void * linkedlist_get(LinkedList * list, int index);
void * linkedlist_remove(LinkedList * list, int index);
int linkedlist_empty(LinkedList * list);
void * linkedlist_pop(LinkedList * list);
void * linkedlist_peek(LinkedList * list);
void * linkedlist_dequeue(LinkedList * list);
void * linkedlist_head(LinkedList * list);
void * linkedlist_array(LinkedList * list);
void linkedlist_destroy(LinkedList * list);
#endif