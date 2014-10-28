/**
Obs: as funções de arvore de busca binária foram levemente modificas,
para inserir um valor igual à esquerda do nó
*/

#include <stdio.h>
#include "binary_tree.h"

int
main (int argc, char *argv[])
{
    BinaryTree* binaryTree = BINARYTREE_createEmptyBinaryTree();
    
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 4);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 6);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 1);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 4);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 9);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 7);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 4);
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, 3);
    
    printf("occurrences of %d: %d\n",4,BINARYSEARCHTREE_returnOccurrences(binaryTree,4));
    
    binaryTree = BINARYTREE_free(binaryTree);
    
    return 0;
}
