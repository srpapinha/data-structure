#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#ifndef _LIMITS_H___
#include <limits.h>
#endif

#ifndef _INC_STDLIB
#include <stdlib.h>
#endif

typedef struct Node {
    struct Node * previous;
    struct Node * next;
    int data;
} Node;

typedef struct LinkedList {
    struct Node * first;
    struct Node * last;
    int size;
} LinkedList;

Node * initNode(Node * previous, Node * next, int data);
LinkedList * initLinkedList(void);
void linkedlist_add(LinkedList * list, int data);
Node * linkedlist_node(LinkedList * list, int index);
int linkedlist_get(LinkedList * list, int index);
void linkedlist_remove(LinkedList * list, int index);
void linkedlist_destroy(LinkedList * list);
#endif