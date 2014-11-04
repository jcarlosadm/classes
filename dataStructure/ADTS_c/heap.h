#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Estrutura da Heap
 */
typedef struct heap Heap;

/**
 * Aloca memória para a heap
 * \return Retorna ponteiro para a memória alocada, ou
 * NULL se não conseguir alocar
 */
Heap* HEAP_create();

/**
 * Desaloca heap
 * \return Retorna NULL
 * \param heap Ponteiro para a heap
 */
Heap* HEAP_free(Heap* heap);

/**
 * Enfileira elemento na heap
 * \return Ponteiro para a heap
 * \param heap Ponteiro para a heap
 * \param value Valor do elemento a ser enfileirado
 * \param priority Prioridade do elemento a ser enfileirado
 */
Heap* HEAP_enqueue(Heap* heap, int value, int priority);

/**
 * Retira elemento com maior prioridade da heap
 * \return Ponteiro para a heap
 * \param heap Ponteiro para a heap
 */
Heap* HEAP_dequeue(Heap* heap);

#endif // HEAP_H
