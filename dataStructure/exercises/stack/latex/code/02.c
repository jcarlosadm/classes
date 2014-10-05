/**
 * Imprime a representação binária de
 * um valor decimal
 */
void printBinary(int number){
    
    int digit = 0;
    Stack* stack = createStack();
    if(!stack) return;
    
    if(number==0)printf("0");
    
    while(number != 0){
        digit = number % 2;
        push(stack,digit);
        number = number/2;
    }
    
    while(!stackIsEmpty(stack)){
        printf("%d",pop(stack));
    }
    
    printf("\n");
    
    stack = stackFree(stack);
}
