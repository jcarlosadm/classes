#include "binary_tree.h"

struct binaryTree{
    int value;
    int height;
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
    BINARYTREE_computeHeight(binaryTree);
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

int computeHeight(BinaryTree* binaryTree, int height){
    
    int left=height, right=height;
    
    if(binaryTree->left){
        left = computeHeight(binaryTree->left, left+1);
    }
    if(binaryTree->right){
        right = computeHeight(binaryTree->right, right+1);
    }
    
    if(left>=right)
        binaryTree->height = left-height;
    else
        binaryTree->height = right-height;
    
    return binaryTree->height + height;
    
}

int BINARYTREE_computeHeight(BinaryTree* binaryTree){
    if(!binaryTree) return 0;
    
    computeHeight(binaryTree, 0);
    return 1;
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

BinaryTree* BINARYSEARCHTREE_searchPrevious(BinaryTree* binaryTree, int value){
    
    if(!binaryTree)
        return NULL;
    if(!(binaryTree->left) && !(binaryTree->right))
        return NULL;
    if((binaryTree->left && binaryTree->left->value == value) || 
            (binaryTree->right && binaryTree->right->value == value))
        return binaryTree;
    
    BinaryTree* previousNode = BINARYSEARCHTREE_searchPrevious(binaryTree->left,value);
    
    if(!previousNode)
        previousNode = BINARYSEARCHTREE_searchPrevious(binaryTree->right, value);
    
    return previousNode;
    
}

BinaryTree* BINARYSEARCHTREE_remove(BinaryTree* binaryTree, int value){
    if(!binaryTree) return binaryTree;
    
    BinaryTree* search = NULL;
    BinaryTree* searchPrevious = NULL;
    
    search = BINARYSEARCHTREE_binarySearch(binaryTree, value);
    
    if(!search) return binaryTree;
    
    if(search != binaryTree){
        searchPrevious = BINARYSEARCHTREE_searchPrevious(binaryTree,value);
    }
    
    if(!(search->left) && !(search->right)){
        if(!searchPrevious){
            free(search);
            binaryTree = NULL;
            return binaryTree;
        }
        else{
            if(searchPrevious->left == search)
                searchPrevious->left = NULL;
            else
                searchPrevious->right = NULL;
            free(search);
            return binaryTree;
        }
    }
    
    else if(!(search->left) || !(search->right)){
        if(!searchPrevious){
            if(search->left)
                binaryTree = search->left;
            else
                binaryTree = search->right;
            free(search);
            return binaryTree;
        }
        
        else{
            if(searchPrevious->left == search){
                if(search->left)
                    searchPrevious->left = search->left;
                else
                    searchPrevious->left = search->right;
            }
            else{
                if(search->left)
                    searchPrevious->right = search->left;
                else
                    searchPrevious->right = search->right;
            }
            free(search);
            return binaryTree;
        }
    }
    
    else{
        if(!searchPrevious){
            binaryTree->left = BINARYSEARCHTREE_insertNode(binaryTree->left, search->right->value);
            searchPrevious = BINARYSEARCHTREE_searchPrevious(binaryTree->left, search->right->value);
            
            if(searchPrevious->left && searchPrevious->left->value == search->right->value){
                free(searchPrevious->left);
                searchPrevious->left = search->right;
            }
            else{
                free(searchPrevious->right);
                searchPrevious->right = search->right;
            }
            
            binaryTree = search->left;
            free(search);
            return binaryTree;
        }
        else{
            BinaryTree* aux = NULL;
            if(!(search->right->left) && !(search->left->right)){
                aux = search;
                search->right->left = search->left;
                if(searchPrevious->left == search)
                    searchPrevious->left = search->right;
                else
                    searchPrevious->right = search->right;
                free(search);
                
                return binaryTree;
            }
            else{
                if(search->right->left){
                    search->value = search->right->left->value;
                    aux = search->right->left;
                    
                    if(search->right->left->left)
                        search->right->left = search->right->left->left;
                    else if(search->right->left->right)
                        search->right->left = search->right->left->right;
                    else
                        search->right->left = NULL;
                        
                    free(aux);
                    return binaryTree;
                }
                else{
                    search->value = search->left->right->value;
                    aux = search->left->right;
                    
                    if(search->left->right->left)
                        search->left->right = search->left->right->left;
                    else if(search->left->right->right)
                        search->left->right = search->left->right->right;
                    else
                        search->left->right = NULL;
                    free(aux);
                    return binaryTree;
                }
            }
        }
    }
    
    return binaryTree;
}

BinaryTree* BINARYSEARCHTREE_binarySearchNonRecursive(BinaryTree* binaryTree, int value){
    if(!binaryTree || binaryTree->value == value) return binaryTree;
    
    BinaryTree* search = binaryTree;
    while(search){
        if(search->value == value) return search;
        else if(search->value > value){
            if(!search->left) return NULL;
            else
                search = search->left;
        }
        
        else{
            if(!search->right) return NULL;
            else
                search = search->right;
        }
    }
    
    if(search) return search;
    else return NULL;
}

int AVL_getBalanceFactor(BinaryTree* binaryTree){
    int left = binaryTree->left ? binaryTree->left->height+1 : 0;
    int right = binaryTree->right ? binaryTree->right->height+1 : 0;
    return (left - right);
}

int AVL_isBalanced(BinaryTree* binaryTree){
    int balanceFactor = AVL_getBalanceFactor(binaryTree);
    return ((-1 <= balanceFactor) && (balanceFactor <= 1));
}

BinaryTree* AVL_rotate_left(BinaryTree* binaryTree){
    BinaryTree* subTreeRoot = NULL;
    
    if(binaryTree != NULL && binaryTree->right != NULL){
        subTreeRoot = binaryTree->right;
        binaryTree->right = subTreeRoot->left;
        subTreeRoot->left = binaryTree;
    }
    
    return subTreeRoot;
}

BinaryTree* AVL_rotate_right(BinaryTree* binaryTree){
    BinaryTree* subTreeRoot = NULL;
    
    if(binaryTree != NULL && binaryTree->left != NULL){
        subTreeRoot = binaryTree->left;
        binaryTree->left = subTreeRoot->right;
        subTreeRoot->right = binaryTree;
    }
    
    return subTreeRoot;
}

BinaryTree* AVL_rotate(BinaryTree* binaryTree){

    BinaryTree* child = NULL;
    
    if(AVL_getBalanceFactor(binaryTree)==2){
        child = binaryTree->left;
        if(AVL_getBalanceFactor(child)== -1){
            binaryTree->left = AVL_rotate_left(child);
        }
        binaryTree = AVL_rotate_right(binaryTree);
    }
    else{
        child = binaryTree->right;
        if(AVL_getBalanceFactor(child)== 1){
            binaryTree->right = AVL_rotate_right(child);
        }
        binaryTree = AVL_rotate_left(binaryTree);
    }
    
    return binaryTree;
}

BinaryTree* AVL_checkBalanceFactor(BinaryTree* binaryTree, int value){
    
    if(binaryTree->value != value){
        if(value < binaryTree->value)
            binaryTree->left = AVL_checkBalanceFactor(binaryTree->left, value);
        else
            binaryTree->right = AVL_checkBalanceFactor(binaryTree->right, value);
    }
    
    if(!AVL_isBalanced(binaryTree)){
        binaryTree = AVL_rotate(binaryTree);
    }
    
    return binaryTree;
}

BinaryTree* AVL_insertNode(BinaryTree* binaryTree, int value){
    binaryTree = BINARYSEARCHTREE_insertNode(binaryTree, value);
    
    BINARYTREE_computeHeight(binaryTree);
    
    if(binaryTree->value != value){
        if(value < binaryTree->value)
            binaryTree->left = AVL_checkBalanceFactor(binaryTree->left, value);
        else
            binaryTree->right = AVL_checkBalanceFactor(binaryTree->right, value);
    }
    
    if(!AVL_isBalanced(binaryTree)){
        binaryTree = AVL_rotate(binaryTree);
    }
    
    BINARYTREE_computeHeight(binaryTree);
    
    return binaryTree;
    
}

