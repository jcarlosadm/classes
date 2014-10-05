/**
 * Verifica se a string é um palíndromo
 */
int isPalindrome(char* name, int sizeName){
    
    int result = 0;
    
    Stack* stack = createStack();
    if(!stack)return 0;
    
    int count;
    for(count=0;count<sizeName-1;count++){
        push(stack,name[count]);
    }
    
    char name2[sizeName];
    name2[sizeName-1] = 0;
    
    for(count=0;count < sizeName-1;count++){
        name2[count] = pop(stack);
    }
    
    if(strcmp(name,name2)==0) result = 1;
    else result = 0;
    
    stack = stackFree(stack);
    
    return result;
}
