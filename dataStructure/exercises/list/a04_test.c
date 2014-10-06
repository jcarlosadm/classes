#include "Linked_list.h"
#include <stdio.h>

int main()
{
    Node* list = createLinkedList();
    
    list = insertNode(list,4);
    list = insertNode(list,3);
    list = insertNode(list,1);
    list = insertNode(list,-9);
    list = insertNode(list,14);
    
    printLinkedList(list);
    
    list = listsort(list);
    
    printLinkedList(list);
    
    list = freeLinkedList(list);
    
    return 0;
}
