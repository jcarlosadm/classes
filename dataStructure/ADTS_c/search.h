/**
 * Funções de busca
 */

#ifndef SEARCH_H
#define SEARCH_H 

/*
 * Busca Linear
 * 
 * Retorna o índice do array em que se encontra o elemento
 * retorna -1 se não encontrar o elemento
 * 
 * int element : elemento procurado
 * int* array : ponteiro para o início de um array de inteiros
 * int size : tamanho do array
 */
int linearsearch(int element, int* array, int size);

/*
 * Busca binária
 * (o array deverá estar ordenado)
 *
 * Retorna o índice do array em que se encontra o elemento
 * retorna -1 se não encontrar o elemento
 *
 * int element : elemento procurado
 * int* array : ponteiro para o início de um array de inteiros
 * int size : tamanho do array
 */
int binarysearch(int element, int* array, int size);

#endif // SEARCH_H
