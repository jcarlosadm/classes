/**
A função se encontra no final do arquivo binary_tree.c
*/

#include <stdio.h>
#include "binary_tree.h"

int
main (int argc, char *argv[])
{
    
    BinaryTree* binaryTree = BINARYTREE_createEmptyBinaryTree();
    
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 4);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 1);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 7);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 3);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 8);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 2);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 0);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 6);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 10);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 5);
    
    BINARYTREE_printLevelOrder(binaryTree);
    
    
    binaryTree = BINARYTREE_free(binaryTree);
    
    return 0;
}
