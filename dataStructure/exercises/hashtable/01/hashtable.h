#ifndef HASHTABLE_H
#define HASHTABLE_H

/**
 * HASHTABLE
 */

#include <stdio.h>
#include <stdlib.h>

// hash table com listas? 1 true, 0 false
#define HASHTABLE_WITH_LIST 0

/**
 * Estrutura da hashtable
 */
typedef struct hashTable HashTable;

/**
 * Aloca memória para a hashTable
 * retorna ponteiro para a memória alocada
 * Retornará NULL se não conseguir alocar a memória
 */
HashTable* HASHTABLE_createHashTable();

/**
 * Libera memória alocada na hashTable
 * retorna NULL
 *
 * HashTable* hashTable: ponteiro para a estrutura HashTable
 */
HashTable* HASHTABLE_free(HashTable* hashTable);

/**
 * Adiciona elemento na hashTable
 * retorna 0 se não conseguir inserir o elemento por falha de alocação
 * ou se a table estiver cheia, ou 1 em caso de sucesso.
 *
 * HashTable* hashTable: ponteiro para a estrutura HashTable
 * int key: chave do novo elemento
 * int value: valor do novo elemento
 */
int HASHTABLE_put(HashTable* hashTable, int key, int value);

/**
 * Se o elemento da chave informa existir, preenche a variável
 * result com o valor deste elemento.
 * retorna 1 em caso de sucesso, ou 0 em caso de falha
 *
 * HashTable* hashTable: ponteiro para a estrutura HashTable
 * int key: chave do elemento a ser procurado
 * int* result: variável a ser preenchida se a busca for bem
 *          sucedida.
 */
int HASHTABLE_get(HashTable* hashTable, int key, int* result);

/**
 * Remove um elemento da hashTable.
 * retorna 0 se o elemento não for encontrado, e 1 em caso contrário.
 *
 * HashTable* hashTable: ponteiro para a estrutura hashTable
 * int key: chave do elemento a ser excluído
 */
int HASHTABLE_remove(HashTable* hashTable, int key);

/**
 * Verifica se uma determinada chave já existe na hashTable
 * Retorna 1 se existir, e 0 em caso contrário
 *
 * HashTable* hashTable: ponteiro para a estrutura hashTable
 * int key: chave do elemento a ser excluído
 */
int HASHTABLE_containsKey(HashTable* hashTable, int key);

/**
 * imprime o conteúdo de todos os elementos da hashTable
 *
 * HashTable* hashTable: ponteiro para a estrutura hashTable
 */
void HASHTABLE_printHashTable(HashTable* hashTable);

#endif // HASHTABLE_H
