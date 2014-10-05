#include<stdio.h>
#include "dStack.h"

int main(int argc, char* argv[])
{
    
    int number = 5;
    int digit = 0;
    DStack* stack = dStackCreateStack();
    if(!stack) return 1;
    
    if(number==0)printf("0");
    
    while(number != 0){
        digit = number % 2;
        dStackPush(stack,digit);
        number = number/2;
    }
    
    while(!dStackIsEmpty(stack)){
        printf("%d",dStackPop(stack));
    }
    
    printf("\n");
    
    stack = dStackFree(stack);
    
    return 0;
}
