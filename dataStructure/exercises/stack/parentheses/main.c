#include<stdio.h>
#include "dStack.h"

int checkParentheses(DStack* stack, char parentheses){
    
    if(dStackIsEmpty(stack))
        return 0;
    
    char pop;
    
    int result = 0;
    
    while(!dStackIsEmpty(stack)){
        
        pop = dStackPop(stack);
        
        if(pop==')' || pop==']' || pop=='}'){
            result = checkParentheses(stack,pop);
            if(!result) return result;
        }
        else{
            switch(parentheses){
            case ')':
                if(pop=='(')
                    return 1;
                else return 0;
            case ']':
                if(pop=='[')
                    return 1;
                else return 0;
            case '}':
                if(pop=='{')
                    return 1;
                else return 0;
            }
        }
    }
    
    return 0;
}

int isBalanced(char *sequence, int size){
    
    DStack* stack = dStackCreateStack();
    
    int count;
    for(count=0;count<size-1;count++){
        dStackPush(stack,sequence[count]);
    }
    
    if(dStackIsEmpty(stack)){
        stack = dStackFree(stack);
        return 1;
    }
    
    int result = 1;
    
    while(!dStackIsEmpty(stack) && result){
        result = checkParentheses(stack,dStackPop(stack));
    }
    
    stack = dStackFree(stack);
    
    return result;
    
}

int main()
{
    
    char sequence[] = "{({)}";
    printf("%s\n",sequence);
    
    if(isBalanced(sequence,sizeof(sequence)))
        printf("is balanced\n");
    else
        printf("is not balanced\n");
    
    return 0;
}
