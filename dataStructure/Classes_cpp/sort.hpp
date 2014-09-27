#ifndef SORT_HPP
#define SORT_HPP

#include <limits.h> // INT_MAX no mergesort
#include <string>
using namespace std;

/**
 * Grupo de funções de ordenação
 */

template<class Type>
class Sort {
    public:
    /*
     * Ordena array de inteiros
     *
     * int *array : ponteiro para o início de um array de inteiros
     * int size : tamanho do array
     */
    static void selectionsort(Type *array, int size);

    /*
     * Ordena array de inteiros
     *
     * int *array : ponteiro para o início de um array de inteiros
     * int size : tamanho do array
     */
    static void insertionsort(Type *array, int size);

    /*
     * Ordena array de inteiros
     *
     * int *array : ponteiro para o início de um array de inteiros
     * int size : tamanho do array
     */
    static void bubblesort(Type *array, int size);

    /*
     * Ordena array de inteiros
     *
     * int *v : ponteiro para o início de um array de inteiros
     * int size : tamanho do array
     */
    static void quicksort(Type *array, int size);

    /*
     * Ordena array de inteiros
     *
     * int *array : ponteiro para o início de um array de inteiros
     * int begin : início do array (começa com 0)
     * int end : final do array (size-1)
     */
    static void mergesort(Type *array, int begin, int end);
};

#endif // SORT_HPP
