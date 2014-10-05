#include<stdio.h>
#include "dStack.h"

int isBalanced(char *parentheses, int size){
    
    DStack* stack = dStackCreateStack();
    
    int count, par=0,col=0,cha=0;
    for(count=0;count<size-1;count++){
        dStackPush(stack,parentheses[count]);
    }
    
    while(!dStackIsEmpty(stack)){
        switch(dStackPop(stack)){
        case '(':
            par++;
            break;
        case ')':
            par--;
            break;
        case '[':
            col++;
            break;
        case ']':
            col--;
            break;
        case '{':
            cha++;
            break;
        case '}':
            cha--;
        }
    }
    
    int result = 1;
    if(par || col || cha)
        result = 0;
    
    stack = dStackFree(stack);
    
    return result;
    
}

int main(int argc, char* argv[])
{
    
    char sequence[] = "()[](){}";
    printf("%s\n",sequence);
    
    if(isBalanced(sequence,sizeof(sequence)))
        printf("is balanced\n");
    else
        printf("is not balanced\n");
    
    
    return 0;
}
