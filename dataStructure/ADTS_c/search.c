#include "search.h"

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
int linearsearch(int element, int* array, int size){
    
    if(size>0){
        if(array[0]==element)
            return 0;
        else{
            int search = linearsearch(element, array+1, size-1);
            if(search != -1)
                return 1+search;
            else
                return -1;
        }
    }
    else
        return -1;
}

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
int binarysearch(int element, int* array, int size){
    
    int begin = 0;
    int end = size - 1;
    int middle = (begin + end)/2;
    
    int returned;
    
    if(begin > end)
        return -1;
    
    else if(array[middle] < element){
        returned = binarysearch(element,array+middle+1,size-middle-1);
        if(returned == -1)
            return -1;
        else
            return (middle + 1 + returned);
    }
    
    else if(array[middle] > element){
        returned = binarysearch(element,array,middle);
        if(returned == -1)
            return -1;
        else
            return returned;
    }
    
    else
        return middle;
    
}
