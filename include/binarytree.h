#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <stdlib.h>
#include <limits.h>

typedef struct BinaryTreeNode {
    struct BinaryTreeNode * left;
    struct BinaryTreeNode * right;
    int data;
} BinaryTreeNode;

BinaryTreeNode * initBinaryTreeNode(BinaryTreeNode * left, BinaryTreeNode * right, int data);
int binarytree_add(BinaryTreeNode ** node, int data);
int binarytree_get(BinaryTreeNode * node, int data);
BinaryTreeNode * binarytree_remove(BinaryTreeNode * node, int data);
void binarytree_destroy(BinaryTreeNode * node);
void binarytree_print(BinaryTreeNode * node);
#endif