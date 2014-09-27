/**
 * Funções de ordenação
 */

#ifndef SORT_H
#define SORT_H

#include <limits.h> // INT_MAX no mergesort

/*
 * Ordena array de inteiros
 *
 * int *array : ponteiro para o início de um array de inteiros
 * int size : tamanho do array
 */
void selectionsort(int *array, int size);

/*
 * Ordena array de inteiros
 *
 * int *array : ponteiro para o início de um array de inteiros
 * int size : tamanho do array
 */
void insertionsort(int *array, int size);

/*
 * Ordena array de inteiros
 *
 * int *array : ponteiro para o início de um array de inteiros
 * int size : tamanho do array
 */
void bubblesort(int *array, int size);

/*
 * Ordena array de inteiros
 *
 * int *v : ponteiro para o início de um array de inteiros
 * int size : tamanho do array
 */
void quicksort(int *array, int size);

/*
 * Ordena array de inteiros
 *
 * int *array : ponteiro para o início de um array de inteiros
 * int begin : início do array (começa com 0)
 * int end : final do array (size-1)
 */
void mergesort(int *array, int begin, int end);

#endif // SORT_H
