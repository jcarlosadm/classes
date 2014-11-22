#include <stdio.h>
#include "dStack.h"

int main()
{
    DStack* stack;
    
    stack = dStackCreateStack();
    
    if(!stack){
        printf("pilha não inicializada\n");
        return 1;
    }
    
    dStackPush(stack,2);
    dStackPush(stack,3);
    dStackPush(stack,1);
    dStackPush(stack,2);
    dStackPush(stack,3);
    dStackPush(stack,4);
    dStackPush(stack,7);
    dStackPush(stack,4);
    
    
    dStackIsEmpty(stack) ? :printf("%d\n",dStackPeek(stack));
    dStackIsEmpty(stack) ? :printf("%d\n",dStackPop(stack));
    dStackIsEmpty(stack) ? :printf("%d\n",dStackPop(stack));
    dStackIsEmpty(stack) ? :printf("%d\n",dStackPop(stack));
    dStackIsEmpty(stack) ? :printf("%d\n",dStackPop(stack));
    dStackIsEmpty(stack) ? :printf("%d\n",dStackPop(stack));
    dStackIsEmpty(stack) ? :printf("%d\n",dStackPop(stack));
    dStackPush(stack,113);
    dStackIsEmpty(stack) ? :printf("%d\n",dStackPop(stack));
    dStackIsEmpty(stack) ? :printf("%d\n",dStackPop(stack));
    dStackIsEmpty(stack) ? :printf("%d\n",dStackPop(stack));
    
    stack = dStackFree(stack);
    
    return 0;
}
