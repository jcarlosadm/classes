#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include<stdlib.h>

/**
 * Estrutura da pilha
 */
typedef struct stack Stack;

/**
 * Inicializa pilha
 * Aloca pilha e retorna ponteiro para a pilha alocada
 */
Stack *stackCreateStack();

/**
 * Libera memória alocada na pilha
 * 
 * Stack* stack: ponteiro para a pilha
 */
Stack *stackFree(Stack* stack);

/**
 * Adiciona elemento no topo da pilha
 * 
 * Stack* stack: ponteiro para a pilha
 * int item: valor a ser adicionado no topo da pilha
 */
void stackPush(Stack* stack, int item);

/**
 * Retira elemento do topo da pilha e o retorna o seu valor
 * 
 * Stack* stack: ponteiro para a pilha
 */
int stackPop(Stack* stack);

/**
 * Retorna valor do topo da pilha (sem remover)
 *
 * Stack* stack: ponteiro para a pilha
 */
int stackPeek(Stack* stack);

/**
 * Verifica se a pilha está vazia
 * retorna 1 se estiver, e 0 em caso contrário
 */
int stackIsEmpty(Stack* stack);

/**
 * Verifica se a pilha está cheia
 * retorna 1 se estiver, e 0 em caso contrário
 */
int stackIsFull(Stack* stack);

#endif // STACK_H
