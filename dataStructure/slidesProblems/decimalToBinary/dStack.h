#ifndef D_STACK_H
#define D_STACK_H

#include<stdio.h>
#include<stdlib.h>

/**
     ADT da pilha dinâmica
                        */

/**
 * Estrutura da pilha
 */
typedef struct dStack DStack;

/**
 * Inicializa pilha
 * Aloca pilha e retorna ponteiro para a pilha alocada
 */
DStack *dStackCreateStack();

/**
 * Libera memória alocada na pilha
 * 
 * DStack* dStack: ponteiro para a pilha
 */
DStack *dStackFree(DStack* stack);

/**
 * Adiciona elemento no topo da pilha
 * 
 * DStack* stack: ponteiro para a pilha
 * int item: valor a ser adicionado no topo da pilha
 */
void dStackPush(DStack* stack, int item);

/**
 * Retira elemento do topo da pilha e o retorna o seu valor
 * 
 * DStack* stack: ponteiro para a pilha
 */
int dStackPop(DStack* stack);

/**
 * Retorna valor do topo da pilha (sem remover)
 *
 * DStack* stack: ponteiro para a pilha
 */
int dStackPeek(DStack* stack);

/**
 * Verifica se a pilha está vazia
 * retorna 1 se estiver, e 0 em caso contrário
 *
 * DStack* stack: ponteiro para a pilha
 */
int dStackIsEmpty(DStack* stack);

#endif // D_STACK_H
