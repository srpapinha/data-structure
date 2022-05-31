#include <stdio.h>
#include "binarytree.h"
#include "linkedlist.h"

BinaryTreeNode * initBinaryTreeNode(BinaryTreeNode * left, BinaryTreeNode * right, int data) {
    BinaryTreeNode * node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
    if(node == NULL) exit(1);
    
    node->left = left;
    node->right = right;
    node->data = data;
    return node;
}

BinaryTreeNode * binarytree_min(BinaryTreeNode * node) {
    while(node->left != NULL) {
        node = node->left;
    }
    return node;
}

int binarytree_add(BinaryTreeNode ** node, int data) {
    if(*node == NULL) {
        *node = initBinaryTreeNode(NULL, NULL, data);
        return 1;
    }

    while(*node != NULL) {
        if(data < (*node)->data) {
            node = &(*node)->left;
        } else if(data > (*node)->data) {
            node = &(*node)->right;
        } else {
            return 0;
        }
    }
    *node = initBinaryTreeNode(NULL, NULL, data);
    return 1;
}

int binarytree_get(BinaryTreeNode * node, int data) {
    if(node == NULL) {
        return 0;
    }
    
    while(node != NULL && node->data != data) {
        if(data < node->data) {
            node = node->left;
        } else if(data > node->data) {
            node = node->right;
        }
    }
    return node != NULL;
}

BinaryTreeNode * binarytree_remove(BinaryTreeNode * node, int data) {
    if(node == NULL) return node;

    if(data < node->data) {
        node->left = binarytree_remove(node->left, data);
    } else if(data > node->data) {
        node->right = binarytree_remove(node->right, data);
    } else {
        if(node->left != NULL && node->right != NULL) {
            BinaryTreeNode * min = binarytree_min(node->right);
            node->data = min->data;
            node->right = binarytree_remove(node->right, min->data);
            return node;
        } else if(node->left != NULL || node->right != NULL) {
            BinaryTreeNode * temp = node->left != NULL ? node->left : node->right;
            free(node);
            return temp;
        } else {
            free(node);
            return NULL;
        }
    }
}

void binarytree_print(BinaryTreeNode * node) {
    if(node == NULL) return;

    printf("%d ", node->data);
    binarytree_print(node->left);
    binarytree_print(node->right);
}

void binarytree_destroy(BinaryTreeNode * node) {
    binarytree_destroy(node->left);
    binarytree_destroy(node->right);
    free(node);
}