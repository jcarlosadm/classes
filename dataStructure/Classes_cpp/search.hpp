#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <string>
using namespace std;

/**
 * grupo de funções de busca
 */

template<class Type>
class Search {

    public:
    /*
     * Busca Linear (para array de inteiros)
     * 
     * Retorna o índice do array em que se encontra o elemento
     * retorna -1 se não encontrar o elemento
     * 
     * int element : elemento procurado
     * int* array : ponteiro para o início de um array de inteiros
     * int size : tamanho do array
     */
    static int linearsearch(Type element, Type *array, int size);
    
    /*
     * Busca binária (para array de inteiros)
     * (o array deverá estar ordenado)
     *
     * Retorna o índice do array em que se encontra o elemento
     * retorna -1 se não encontrar o elemento
     *
     * int element : elemento procurado
     * int* array : ponteiro para o início de um array de inteiros
     * int size : tamanho do array
     */
    static int binarysearch(Type element, Type *array, int size);
};

#endif // SEARCH_HPP
