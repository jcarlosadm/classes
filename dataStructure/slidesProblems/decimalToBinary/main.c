#include<stdio.h>
#include "dStack.h"

void printBinary(int number){
    
    int digit = 0;
    DStack* stack = dStackCreateStack();
    if(!stack) return;
    
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
}

int main(int argc, char* argv[])
{
    
    printBinary(2);
    
    return 0;
}
