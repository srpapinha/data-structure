#include "linkedlist.h"

Node * initNode(Node * previous, Node * next, int data) {
    Node * node = (Node*) malloc(sizeof(Node));
    node->previous = previous;
    node->next = next;
    node->data = data;
    return node;
}

LinkedList * initLinkedList(void) {
    return (LinkedList*) calloc(1, sizeof(LinkedList));
}

void linkedlist_add(LinkedList * list, int data) {
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

int linkedlist_get(LinkedList * list, int index) {
    Node * node = linkedlist_node(list, index);
    return node != NULL ? node->data : INT_MIN;
}

void linkedlist_remove(LinkedList * list, int index) {
    Node * node;
    if(index < 0 && list->size <= index) return;
    if(index == 0) {
        node = list->first;
        list->first = list->first->next;
        list->first->previous = NULL;
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
    free(node);
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