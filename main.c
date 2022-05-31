#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sort.h>
#include <linkedlist.h>
#include <binarytree.h>


void testLinkedList() {
    int array[] = {10, 20, 30, 40, 50};
    LinkedList * list = initLinkedList(sizeof(int));

    linkedlist_add(list, &array[0]);
    linkedlist_add(list, &array[1]);
    linkedlist_add(list, &array[2]);
    linkedlist_add(list, &array[3]);
    linkedlist_add(list, &array[4]);

    int * test = linkedlist_array(list);
    for(int i = 0; i < 5; i++) {
        printf("%d ", test[i]);
    }
    /*
    assert(*(int*) linkedlist_get(list, 0) == array[0]);
    assert(*(int*) linkedlist_get(list, 2) == array[2]);
    assert(*(int*) linkedlist_get(list, 4) == array[4]);

    linkedlist_remove(list, 0);
    linkedlist_remove(list, 1);
    linkedlist_remove(list, 2);
    assert(*(int*) linkedlist_get(list, 0) == array[1]);
    assert(*(int*) linkedlist_get(list, 1) == array[3]);

    assert(*(int*) linkedlist_dequeue(list) == array[1]);
    assert(*(int*) linkedlist_dequeue(list) == array[3]);
    */
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

void testBinaryTree() {
    int array[] = {7, 4, 2, 8, 1, 3, 5, 9, 6};
    BinaryTreeNode * root = initBinaryTreeNode(NULL, NULL, 7);
    for(int i = 1; i < 10; i++) {
        binarytree_add(&root, array[i]);
    }

    assert(binarytree_get(root, 1));
    assert(binarytree_get(root, 2));
    assert(binarytree_get(root, 3));
    assert(binarytree_get(root, 4));
    assert(binarytree_get(root, 5));
    assert(binarytree_get(root, 6));
    assert(binarytree_get(root, 7));
    assert(binarytree_get(root, 8));
    assert(binarytree_get(root, 9));

    binarytree_remove(root, 4);
    binarytree_remove(root, 5);
    binarytree_remove(root, 6);
    binarytree_remove(root, 7);
}

int main(void) {
    testLinkedList();
    testQuicksort();
    testMergesort();
    testBinaryTree();
    printf("END\n");
    return 0;
}