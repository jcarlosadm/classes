/**
 * Verifica se os parênteses, colchetes e chaves
 * estão balanceados
 */
int isBalanced(char *parentheses, int size){
    
    Stack* stack = createStack();
    
    int count, par=0,col=0,cha=0;
    for(count=0;count<size-1;count++){
        push(stack,parentheses[count]);
    }
    
    while(!stackIsEmpty(stack)){
        switch(pop(stack)){
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
    
    stack = stackFree(stack);
    
    return result;
    
}
