#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack/Stack.h"
#include "LinkedList/LinkedList.h"

void testStack() {
    Stack * stack = initStack(3);
    assert(stack_is_empty(stack));
    
    stack_push(stack, 10);

    stack_push(stack, 20);
    stack_push(stack, 30);
    assert(stack_is_full(stack));
    assert(stack_peek(stack) == 30);
    assert(stack_pop(stack) == 30);

    stack_destroy(stack);
}

void testLinkedList() {
    LinkedList * list = initLinkedList();

    linkedlist_add(list, 10);
    linkedlist_add(list, 20);
    linkedlist_add(list, 30);
    linkedlist_add(list, 40);
    linkedlist_add(list, 50);
    assert(linkedlist_get(list, 0) == 10);
    assert(linkedlist_get(list, 2) == 30);
    assert(linkedlist_get(list, 4) == 50);

    linkedlist_remove(list, 0);
    linkedlist_remove(list, 1);
    linkedlist_remove(list, 2);
    assert(linkedlist_get(list, 0) == 20);
    assert(linkedlist_get(list, 1) == 40);

    linkedlist_destroy(list);
}

int main(void) {
    testStack();
    testLinkedList();
    return 0;
}