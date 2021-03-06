#ifndef BINARYTREE
#define BINARYTREE

#include <stdio.h>
#include <stdlib.h>

typedef struct binaryTree BinaryTree;

BinaryTree* BINARYTREE_createEmptyBinaryTree();

BinaryTree* BINARYTREE_createBinaryTree(
        int value, BinaryTree* left, BinaryTree* right);

BinaryTree* BINARYTREE_free(BinaryTree* binaryTree);

int BINARYTREE_isEmpty(BinaryTree* binaryTree);

int BINARYTREE_computeHeight(BinaryTree* binaryTree);

void BINARYTREE_printInOrder(BinaryTree* binaryTree);

void BINARYTREE_printPreOrder(BinaryTree* binaryTree);

void BINARYTREE_printPostOrder(BinaryTree* binaryTree);

BinaryTree* BINARYSEARCHTREE_insertNode(BinaryTree* binaryTree, int value);

BinaryTree* BINARYSEARCHTREE_binarySearch(BinaryTree* binaryTree, int value);

int BINARYSEARCHTREE_search(BinaryTree* binaryTree, int value);

BinaryTree* BINARYSEARCHTREE_remove(BinaryTree* binaryTree, int value);

BinaryTree* BINARYSEARCHTREE_binarySearchNonRecursive(BinaryTree* binaryTree, int value);

BinaryTree* AVL_insertNode(BinaryTree* binaryTree, int value);

BinaryTree* AVL_deleteNode(BinaryTree* binaryTree, int value);

BinaryTree* BINARYEXPRESSIONTREE_create(char value);

BinaryTree* BINARYEXPRESSIONTREE_insertOperator(BinaryTree* firstTree,
                                    BinaryTree* secondTree, char operatorEx);

double BINARYEXPRESSIONTREE_evalExpression(BinaryTree* binaryTree);
#endif // BINARYTREE
