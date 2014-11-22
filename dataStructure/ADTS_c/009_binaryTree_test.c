#include<stdio.h>
#include "binary_tree.h"

int main()
{
    BinaryTree* binaryTree = BINARYTREE_createBinaryTree(6,NULL,NULL);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree,3);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree,9);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree,5);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree,2);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree,7);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree,10);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree,12);
    
    BINARYTREE_printInOrder(binaryTree);
    printf("\n");
    BINARYTREE_printPreOrder(binaryTree);
    printf("\n");
    BINARYTREE_printPostOrder(binaryTree);
    printf("\n");
    
    BinaryTree* binaryTree2 = BINARYSEARCHTREE_binarySearch(binaryTree, 3);
    BINARYTREE_printPreOrder(binaryTree2);
    printf("\n");
    
    binaryTree2 = BINARYSEARCHTREE_binarySearchNonRecursive(binaryTree, 10);
    BINARYTREE_printPreOrder(binaryTree2);
    printf("\n");
    
    binaryTree = BINARYSEARCHTREE_remove(binaryTree,9);
    BINARYTREE_printPreOrder(binaryTree);
    printf("\n");
    
    binaryTree = BINARYTREE_free(binaryTree);
    
    return 0;
}
