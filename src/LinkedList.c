#include "linkedlist.h"

Node * initNode(Node * previous, Node * next, void * data) {
    Node * node = (Node*) malloc(sizeof(Node));
    node->previous = previous;
    node->next = next;
    node->data = data;
    return node;
}

LinkedList * initLinkedList(void) {
    return (LinkedList*) calloc(1, sizeof(LinkedList));
}

void linkedlist_add(LinkedList * list, void * data) {
    if(list->size == 0) {
        list->first = initNode(NULL, NULL, data);
        list->last = list->first;
    } else {
        list->last->next = initNode(list->last, NULL, data);
        list->last = list->last->next;
    }
    list->size++;
}

Node * linkedlist_node(LinkedList * list, int index) {
    if(list->size <= index) return NULL;
    Node * node = list->first;
    for(int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

void * linkedlist_get(LinkedList * list, int index) {
    Node * node = linkedlist_node(list, index);
    return node != NULL ? node->data : NULL;
}

void * linkedlist_remove(LinkedList * list, int index) {
    void * data;
    Node * node;
    if(index < 0 && list->size <= index) return NULL;
    if(index == 0) {
        node = list->first;
        if(list->size == 1) {
            list->first = NULL;
            list->last = NULL;
        } else {
            list->first = list->first->next;
            list->first->previous = NULL;
        }
    } else if(list->size - 1 == index) {
        node = list->last;
        list->last = list->last->previous;
        list->last->next = NULL;
    } else {
        node = linkedlist_node(list, index);
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }
    list->size--;
    data = node->data;
    free(node);
    return data;
}

void linkedlist_push(LinkedList * list, void * data) {
    linkedlist_add(list, data);
}

void * linkedlist_pop(LinkedList * list) {
    return linkedlist_remove(list, list->size - 1);
}

void * linkedlist_peek(LinkedList * list) {
    return linkedlist_get(list, list->size - 1);
}

void linkedlist_enqueue(LinkedList * list, void * data) {
    linkedlist_add(list, data);
}

void * linkedlist_dequeue(LinkedList * list) {
    return linkedlist_remove(list, 0);
}

void * linkedlist_head(LinkedList * list) {
    return linkedlist_get(list, 0);
}

void linkedlist_destroy(LinkedList * list) {
    Node * node = list->first, * previous = NULL;
    while(node != NULL) {
        previous = node;
        node = node->next;
        free(previous);
    }
    free(list);
}