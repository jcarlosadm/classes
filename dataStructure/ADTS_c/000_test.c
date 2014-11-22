#include <stdio.h>
#include "search.h"
#include "sort.h"
#include "Linked_list.h"
//#include "Doubly_Linked_list.h"

int main(int argc, char* argv[])
{
    Node* node;
    
    node = createLinkedList();
    
    node = insertNode(node,1);
    node = insertNode(node,2);
    node = insertNode(node,3);
    node = insertNode(node,4);
    node = insertNode(node,5);
    node = insertNode(node,6);
    
    printLinkedList(node);
    
    node = reverseList(node);
    
    printLinkedList(node);
    
    node = freeLinkedList(node);
    
    
    /*Node* node;
    
    node = createDoublyLinkedList();
    
    node = insertNode(node,1);
    node = insertNode(node,2);
    node = insertNode(node,3);
    node = insertNode(node,4);
    node = insertNode(node,5);
    
    
    
    printDoublyLinkedListForward(node);
    

    node = removeNode(node,4);
    node = removeNode(node,6);
    
    printDoublyLinkedListBackward(node);
    printDoublyLinkedListForward(node);
    
    node = freeLinkedList(node);
    
    printDoublyLinkedListForward(node);*/
    
    return 0;
}
