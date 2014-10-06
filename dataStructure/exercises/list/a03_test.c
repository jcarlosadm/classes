#include "Linked_list.h"
#include <stdio.h>

int main()
{
    
    NodeCharFreq* list = createCharLinkedList();
    
    char mystring[] = "abacate";
    
    list = listOfCharFreq(mystring,sizeof(mystring)/sizeof(char),list);
    
    printCharLinkedList(list);
    
    list = freeCharLinkedList(list);
    
    return 0;
}
