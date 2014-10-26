#include "binary_tree.h"

struct binaryTree{
    int value;
    BinaryTree* left;
    BinaryTree* right;
};

BinaryTree* BINARYTREE_createEmptyBinaryTree(){
    return NULL;
}

BinaryTree* BINARYTREE_createBinaryTree(
        int value, BinaryTree* left, BinaryTree* right){
    BinaryTree* binaryTree = malloc(sizeof(BinaryTree));
    if(!binaryTree) return NULL;
    
    binaryTree->value = value;
    binaryTree->left = left;
    binaryTree->right = right;
    return binaryTree;
}

BinaryTree* BINARYTREE_free(BinaryTree* binaryTree){
    if(BINARYTREE_isEmpty(binaryTree)) return NULL;
    
    binaryTree->left = BINARYTREE_free(binaryTree->left);
    binaryTree->right = BINARYTREE_free(binaryTree->right);
    free(binaryTree);
    return NULL;
}

int BINARYTREE_isEmpty(BinaryTree* binaryTree){
    return (binaryTree == NULL);
}

void BINARYTREE_printInOrder(BinaryTree* binaryTree){
    if(!BINARYTREE_isEmpty(binaryTree)){
        BINARYTREE_printInOrder(binaryTree->left);
        printf("%d ",binaryTree->value);
        BINARYTREE_printInOrder(binaryTree->right);
    }
}

void BINARYTREE_printPreOrder(BinaryTree* binaryTree){
    if(!BINARYTREE_isEmpty(binaryTree)){
        printf("%d ", binaryTree->value);
        BINARYTREE_printPreOrder(binaryTree->left);
        BINARYTREE_printPreOrder(binaryTree->right);
    }
}

void BINARYTREE_printPostOrder(BinaryTree* binaryTree){
    if(!BINARYTREE_isEmpty(binaryTree)){
        BINARYTREE_printPostOrder(binaryTree->left);
        BINARYTREE_printPostOrder(binaryTree->right);
        printf("%d ",binaryTree->value);
    }
}

BinaryTree* BINARYSEARCHTREE_insertNode(BinaryTree* binaryTree, int value){
    if(binaryTree==NULL){
        binaryTree = BINARYTREE_createBinaryTree(value,NULL,NULL);
    }
    else if(binaryTree->value > value){
        binaryTree->left = BINARYSEARCHTREE_insertNode(binaryTree->left, value);
    }
    else{
        binaryTree->right = BINARYSEARCHTREE_insertNode(binaryTree->right, value);
    }
    return binaryTree;
}

BinaryTree* BINARYSEARCHTREE_binarySearch(BinaryTree* binaryTree, int value){
    if((binaryTree==NULL) || (binaryTree->value == value))
        return binaryTree;
    else if(binaryTree->value > value)
        return BINARYSEARCHTREE_binarySearch(binaryTree->left,value);
    else
        return BINARYSEARCHTREE_binarySearch(binaryTree->right, value);
}
