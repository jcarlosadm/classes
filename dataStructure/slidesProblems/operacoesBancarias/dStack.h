#ifndef D_STACK_H
#define D_STACK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
     ADT da pilha dinâmica
                        */

/**
 * Estrutura da pilha
 */
typedef struct dStack DStack;

typedef struct cliente Cliente;

/**
 * Inicializa pilha
 * Aloca pilha e retorna ponteiro para a pilha alocada
 */
DStack *dStackCreateStack();

Cliente *createCliente(float value,char* senha);

float getTotal(Cliente * cliente);
void setTotal(Cliente * cliente,float value);
float getTempSaque(Cliente * cliente);
void setTempSaque(Cliente * cliente,float value);
float getTempDeposito(Cliente * cliente);
void setTempDeposito(Cliente * cliente,float value);
int checkSenha(Cliente* cliente,char *senha);

Cliente* freeCliente(Cliente* cliente);


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
void dStackPush(DStack* stack, int (*item)(DStack*,Cliente*));

/**
 * Retira elemento do topo da pilha e o retorna o seu valor
 * 
 * DStack* stack: ponteiro para a pilha
 */
void dStackPop(DStack* stack);

/**
 * Retorna valor do topo da pilha (sem remover)
 *
 * DStack* stack: ponteiro para a pilha
 */
int dStackExecuteTopElement(DStack* stack,Cliente* cliente);

/**
 * Verifica se a pilha está vazia
 * retorna 1 se estiver, e 0 em caso contrário
 *
 * DStack* stack: ponteiro para a pilha
 */
int dStackIsEmpty(DStack* stack);

#endif // D_STACK_H
