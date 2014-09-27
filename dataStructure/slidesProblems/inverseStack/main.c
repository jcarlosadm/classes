#include <stdio.h>

typedef struct stack{
    int array[5];
    int index;
}Stack;

void newStack(Stack* stack){
    stack->index = 0;
}

void push(Stack* stack, int numb){
    if(stack->index<5){
        stack->array[stack->index]=numb;
        stack->index += 1;
    }else{
        printf("pilha cheia\n");
    }
}

int pop(Stack* stack, int print){
    if(stack->index>0){
        stack->index -= 1;
        if(print)printf("%d\n",stack->array[stack->index]);
        return stack->array[stack->index];
    }else{
        if(print)printf("pilha vazia\n");
        return 0;
    }
}

int returnBottom(Stack* stack){
    int element = pop(stack,0);
    if(stack->index == 0)
        return element;
    else{
        int bottom_element = returnBottom(stack);
        push(stack,element);
        return bottom_element;
    }
}

void invertStack(Stack* stack){
    if(stack->index > 0){
        int element = returnBottom(stack);
        invertStack(stack);
        push(stack,element);
    }
}

int main()
{
    Stack stack;
    newStack(&stack);
    push(&stack,10);
    push(&stack,20);
    push(&stack,30);
    push(&stack,40);
    push(&stack,50);
    push(&stack,60);
    
    invertStack(&stack);
    
    pop(&stack,1);
    pop(&stack,1);
    pop(&stack,1);
    pop(&stack,1);
    pop(&stack,1);
    pop(&stack,1);
    pop(&stack,1);
    pop(&stack,1);
    
    return 0;
}
