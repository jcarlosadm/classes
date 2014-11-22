#include <stdio.h>
#include "stack.h"

int main()
{
    Stack* stack;
    
    stack = stackCreateStack();
    
    if(!stack){
        printf("pilha não inicializada\n");
        return 1;
    }
    
    stackIsFull(stack) ? :stackPush(stack,2);
    stackIsFull(stack) ? :stackPush(stack,5);
    stackIsFull(stack) ? :stackPush(stack,2);
    stackIsFull(stack) ? :stackPush(stack,3);
    stackIsFull(stack) ? :stackPush(stack,1);
    stackIsFull(stack) ? :stackPush(stack,8);
    stackIsFull(stack) ? :stackPush(stack,7);
    
    stackIsEmpty(stack) ? :printf("%d\n",stackPeek(stack));
    stackIsEmpty(stack) ? :printf("%d\n",stackPop(stack));
    stackIsEmpty(stack) ? :printf("%d\n",stackPop(stack));
    stackIsEmpty(stack) ? :printf("%d\n",stackPop(stack));
    stackIsEmpty(stack) ? :printf("%d\n",stackPop(stack));
    stackIsEmpty(stack) ? :printf("%d\n",stackPop(stack));
    stackIsEmpty(stack) ? :printf("%d\n",stackPop(stack));
    stackIsEmpty(stack) ? :printf("%d\n",stackPop(stack));
    
    stack = stackFree(stack);
    
    return 0;
}
