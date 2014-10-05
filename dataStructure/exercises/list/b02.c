#include "Doubly_Linked_list.h"
#include <stdio.h>

int main()
{
    Node* node = createDoublyLinkedList();
    
    node = insertOrderedNode(node, 5);
    node = insertOrderedNode(node, 4);
    node = insertOrderedNode(node, 1);
    node = insertOrderedNode(node, 3);
    node = insertOrderedNode(node, -1);
    node = insertOrderedNode(node, 9);
    node = insertOrderedNode(node, -2);
    
    printDoublyLinkedListForward(node);
    
    node = freeLinkedList(node);
    
    return 0;
}
