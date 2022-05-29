#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <linkedlist.h>
#include <sort.h>

void testLinkedList() {
    int array[] = {10, 20, 30, 40, 50};
    LinkedList * list = initLinkedList();

    linkedlist_add(list, &array[0]);
    linkedlist_add(list, &array[1]);
    linkedlist_add(list, &array[2]);
    linkedlist_add(list, &array[3]);
    linkedlist_add(list, &array[4]);
    assert(*(int*) linkedlist_get(list, 0) == array[0]);
    assert(*(int*) linkedlist_get(list, 2) == array[2]);
    assert(*(int*) linkedlist_get(list, 4) == array[4]);

    linkedlist_remove(list, 0);
    linkedlist_remove(list, 1);
    linkedlist_remove(list, 2);
    assert(*(int*) linkedlist_get(list, 0) == array[1]);
    assert(*(int*) linkedlist_get(list, 1) == array[3]);

    linkedlist_push(list, &array[1]);
    linkedlist_push(list, &array[2]);
    linkedlist_push(list, &array[4]);
    assert(*(int*) linkedlist_pop(list) == array[4]);
    assert(*(int*) linkedlist_pop(list) == array[2]);
    assert(*(int*) linkedlist_pop(list) == array[1]);

    assert(*(int*) linkedlist_dequeue(list) == array[1]);
    assert(*(int*) linkedlist_dequeue(list) == array[3]);

    linkedlist_destroy(list);
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
    testLinkedList();
    /*
    testQuicksort();
    testMergesort();
    */
    printf("END\n");
    return 0;
}