#include <stdio.h>
#include "Doubly_Linked_list.h"



int
main (int argc, char *argv[])
{
    
    int var, answer=1;
    
    Node* node;
    node = createDoublyLinkedList();
    
    while(answer){
        printf("-2 para voltar, -1 para avançar, 0 para sair e 1 para continuar\n");
        scanf("%d",&answer);
        switch(answer){
        case -2:
            if(back(&node))
                printf("%d\n",getValue(&node));
            break;
        case -1:
            if(forward(&node))
                printf("%d\n",getValue(&node));
            break;
        case 0:
            break;
        case 1:
            scanf("%d",&var);
            insertHere(&node,var);
            printf("%d\n",getValue(&node));
        }
            
    }
    
    node = freeLinkedList(node);
    
    return 0;
}
