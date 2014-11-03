#include "binary_tree.h"

int
main (int argc, char *argv[])
{
    
    BinaryTree* binaryTree = BINARYTREE_createEmptyBinaryTree();
    
    int numbers[] = {2,5,3,43,34,4,6,1,7,44,8,9};
    
    int count;
    for(count=0; count<(sizeof(numbers)/sizeof(int)); count++){
        binaryTree = AVL_insertNode(binaryTree, numbers[count]);
    }
    
    BINARYTREE_printPreOrder(binaryTree);
    printf("\n");
    
    binaryTree = BINARYTREE_free(binaryTree);
    
    return 0;
}
