#include "Linked_list.h"
#include <stdio.h>

int main()
{
    Node* listA = createLinkedList();
    Node* listB = createLinkedList();
    
    listA = insertNode(listA,3);
    listA = insertNode(listA,4);
    listA = insertNode(listA,1);
    
    listB = insertNode(listB,5);
    listB = insertNode(listB,3);
    
    if(isSubset(listB,listA))
        printf("list B is a subset of list A\n");
    else
        printf("list B is not a subset of list A\n");
    
    listA = freeLinkedList(listA);
    listB = freeLinkedList(listB);
    
    return 0;
}
