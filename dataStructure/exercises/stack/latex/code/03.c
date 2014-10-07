/**
 * Função auxiliar que verifica se parênteses, chaves e
 * colchetes fecham
 */
int checkParentheses(Stack* stack, char parentheses){
    
    if(stackIsEmpty(stack))
        return 0;
    
    char pop;
    
    int result = 0;
    
    while(!stackIsEmpty(stack)){
        
        pop = pop(stack);
        
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
/**
 * Verifica se os parênteses, colchetes e chaves
 * estão balanceados
 */
int isBalanced(char *sequence, int size){
    
    Stack* stack = createStack();
    
    int count;
    for(count=0;count<size-1;count++){
        push(stack,sequence[count]);
    }
    
    if(stackIsEmpty(stack)){
        stack = stackFree(stack);
        return 1;
    }
    
    int result = 1;
    
    while(!stackIsEmpty(stack) && result){
        result = checkParentheses(stack,pop(stack));
    }
    
    stack = stackFree(stack);
    
    return result;
    
}
