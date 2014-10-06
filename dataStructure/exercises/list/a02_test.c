#include "Linked_list.h"
#include <stdio.h>

int main()
{
    Node* list = createLinkedList();
    
    list = insertNode(list, 3);
    list = insertNode(list, 1);
    list = insertNode(list, 2);
    list = insertNode(list, 6);
    list = insertNode(list, 7);
    
    printLinkedList(list);
    
    list = reverseList(list);
    
    printLinkedList(list);
    
    list = freeLinkedList(list);
    
    return 0;
}
