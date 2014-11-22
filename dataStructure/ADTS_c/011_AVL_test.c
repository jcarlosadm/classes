#include <stdio.h>
#include "binary_tree.h"

int
main (int argc, char *argv[])
{
    
    BinaryTree* binaryTree = BINARYTREE_createEmptyBinaryTree();
    
    binaryTree = AVL_insertNode(binaryTree, 1);
    binaryTree = AVL_insertNode(binaryTree, 2);
    binaryTree = AVL_insertNode(binaryTree, 3);
    binaryTree = AVL_insertNode(binaryTree, 4);
    binaryTree = AVL_insertNode(binaryTree, 5);
    binaryTree = AVL_insertNode(binaryTree, 6);
    binaryTree = AVL_insertNode(binaryTree, 7);
    binaryTree = AVL_insertNode(binaryTree, 8);
    binaryTree = AVL_insertNode(binaryTree, 0);
    
    binaryTree = AVL_deleteNode(binaryTree, 6);
    binaryTree = AVL_deleteNode(binaryTree, 7);
    binaryTree = AVL_deleteNode(binaryTree, 5);
    
    int n=4;
    printf("found %d? %d\n",n,BINARYSEARCHTREE_search(binaryTree, n));
    
    BINARYTREE_printInOrder(binaryTree);
    printf("\n");
    
    binaryTree = BINARYTREE_free(binaryTree);
    
    return 0;
}
