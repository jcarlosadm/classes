#include "hashtable.h"

// tamanho da table da hashTable
#define MAX_TABLE_SIZE 11;

/**
 * estrutura de cada elemento na hashTable
 */
typedef struct element Element;
struct element{
    int key;
    int value;
    Element* nextElement;
}

/**
 * Estrutura da hashtable
 */
struct hashTable{
    Element *table[MAX_TABLE_SIZE];
}

/**
 * Função que calcula uma posição na table
 * de acordo com a chave fornecida
 */
int hashFunction(int key){
    return (key % MAX_TABLE_SIZE);
}


