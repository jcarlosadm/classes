#include "stack.h"

#define MAX_STACK_SIZE 5

/**
 * Estrutura da pilha
 */
struct stack{
    int currentSize;
    int items[MAX_STACK_SIZE];
};

/**
 * Inicializa pilha
 * Aloca pilha e retorna ponteiro para a pilha alocada
 */
Stack *stackCreateStack(){
    // aloca a pilha
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    // se não conseguir alocar, retorna NULL
    if(!stack) return NULL;
    // define o tamanho inicial da pilha
    stack->currentSize = 0;
    // retorna o ponteiro para a pilha alocada
    return stack;
}

/**
 * Libera memória alocada na pilha
 * 
 * Stack* stack: ponteiro para a pilha
 */
Stack *stackFree(Stack* stack){
    if(stack)
        free(stack);
    return NULL;
}

/**
 * Adiciona elemento no topo da pilha
 * 
 * Stack* stack: ponteiro para a pilha
 * int item: valor a ser adicionado no topo da pilha
 */
void stackPush(Stack* stack, int item){
    // somente adiciona se a pilha não estiver cheia
    if(!stackIsFull(stack)){
        stack->items[stack->currentSize] = item;
        stack->currentSize++;
    }
    else
        printf("stack is full!\n");
}

/**
 * Retira elemento do topo da pilha e o retorna o seu valor
 * 
 * Stack* stack: ponteiro para a pilha
 */
int stackPop(Stack* stack){
    // somente retira elemento se a pilha não estiver vazia
    if(!stackIsEmpty(stack)){
        stack->currentSize--;
        return stack->items[stack->currentSize];
    }
    else
        printf("stack is empty\n");
}

/**
 * Retorna valor do topo da pilha (sem remover)
 *
 * Stack* stack: ponteiro para a pilha
 */
int stackPeek(Stack* stack){
    // somente retorna elemento se a pilha não estiver vazia
    if(!stackIsEmpty(stack))
        return stack->items[stack->currentSize - 1];
    else
        printf("stack is empty\n");
}

/**
 * Verifica se a pilha está vazia
 * retorna 1 se estiver, e 0 em caso contrário
 */
int stackIsEmpty(Stack* stack){
    return (stack->currentSize == 0);
}

/**
 * Verifica se a pilha está cheia
 * retorna 1 se estiver, e 0 em caso contrário
 */
int stackIsFull(Stack* stack){
    return (stack->currentSize == MAX_STACK_SIZE);
}
