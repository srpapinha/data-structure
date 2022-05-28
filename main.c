#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Stack.h>
#include <LinkedList.h>
#include <Queue.h>
#include <Sort.h>

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

void testQueue() {
    Queue * queue = initQueue(5);
    assert(queue_is_empty(queue));
    assert(queue_enqueue(queue, 10));
    assert(queue_enqueue(queue, 20));
    assert(queue_enqueue(queue, 30));
    assert(queue_enqueue(queue, 40));
    assert(queue_enqueue(queue, 50));
    assert(queue_enqueue(queue, 60) == 0);
    assert(queue_is_full(queue));
    assert(queue_dequeue(queue) == 10);
    assert(queue_dequeue(queue) == 20);
    assert(queue_dequeue(queue) == 30);
    assert(queue_dequeue(queue) == 40);
    assert(queue_dequeue(queue) == 50);
    assert(queue_dequeue(queue) == INT_MIN);

    queue_destroy(queue);
}

void testQuicksort() {
    int array[] = {7, 4, 2, 8, 1, 0, 3, 5, 9, 6};
    quicksort(array, 0, 9);
    assert(array[0] == 0);
    assert(array[1] == 1);
    assert(array[2] == 2);
    assert(array[3] == 3);
    assert(array[4] == 4);
    assert(array[5] == 5);
    assert(array[6] == 6);
    assert(array[7] == 7);
    assert(array[8] == 8);
    assert(array[9] == 9);
}

void testMergesort() {
    int array[] = {7, 4, 2, 8, 1, 0, 3, 5, 9, 6};
    mergesort(array, 0, 9);
    assert(array[0] == 0);
    assert(array[1] == 1);
    assert(array[2] == 2);
    assert(array[3] == 3);
    assert(array[4] == 4);
    assert(array[5] == 5);
    assert(array[6] == 6);
    assert(array[7] == 7);
    assert(array[8] == 8);
    assert(array[9] == 9);
}

int main(void) {
    testStack();
    testLinkedList();
    testQueue();
    testQuicksort();
    testMergesort();
    printf("END\n");
    system("pause");
    return 0;
}