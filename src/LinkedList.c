#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

Node * initNode(Node * previous, Node * next, void * data) {
    Node * node = (Node*) malloc(sizeof(Node));
    node->previous = previous;
    node->next = next;
    node->data = data;
    return node;
}

LinkedList * initLinkedList(size_t data_size) {
    LinkedList * list = (LinkedList*) malloc(sizeof(LinkedList));
    if(list == NULL) exit(1);

    list->data_size = data_size;
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
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

void linkedlist_copy(LinkedList * list, void * data) {
    void * copy = malloc(list->size);
    memcpy(copy, data, list->data_size);
    linkedlist_add(list, copy);
}

Node * linkedlist_node(LinkedList * list, int index) {
    if(index < 0 || list->size <= index) {
        fprintf(stderr, "LinkedList out bounds error");
        return NULL;
    }
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
    Node * node = linkedlist_node(list, index);
    if(index == 0) {
        if(list->size == 1) {
            list->first = NULL;
            list->last = NULL;
        } else {
            list->first = list->first->next;
            list->first->previous = NULL;
        }
    } else if(list->size - 1 == index) {
        list->last = list->last->previous;
        list->last->next = NULL;
    } else {
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }
    list->size--;
    data = node->data;
    free(node);
    return data;
}

int linkedlist_empty(LinkedList * list) {
    return list->size == 0;
}

void * linkedlist_pop(LinkedList * list) {
    return linkedlist_remove(list, list->size - 1);
}

void * linkedlist_peek(LinkedList * list) {
    return linkedlist_get(list, list->size - 1);
}

void * linkedlist_dequeue(LinkedList * list) {
    return linkedlist_remove(list, 0);
}

void * linkedlist_head(LinkedList * list) {
    return linkedlist_get(list, 0);
}

void * linkedlist_array(LinkedList * list) {
    Node * node = list->first;
    void * array = malloc(list->data_size * list->size);
    for(int i = 0; i < list->size; i++) {
        memcpy(array + (list->data_size * i), node->data, list->data_size);
        node = node->next;
    }
    return array;
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