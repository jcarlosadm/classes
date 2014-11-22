#include <stdio.h>
#include "Linked_list.h"

int main()
{
    Node* node;
    
    node = createLinkedList();
    
    node = insertSortedNode(node,4);
    node = insertSortedNode(node,-2);
    node = insertSortedNode(node,5);
    node = insertSortedNode(node,1);
    node = insertSortedNode(node,7);
    node = insertSortedNode(node,1);
    node = insertSortedNode(node,2);
    node = insertSortedNode(node,2);
    
    printLinkedList(node);
    
    node  = freeLinkedList(node);
    
    return 0;
}
