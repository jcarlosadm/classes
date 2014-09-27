#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * ADT da lista encadeada simples
 */

/**
 * Estrutura do nó da lista
 * Esse nó guarda um inteiro
 */
typedef struct node Node;
typedef struct nodeCharFreq NodeCharFreq;

/**
 * Inicializa o primeiro nó da lista com NULL
 * retorna NULL
 */
Node* createLinkedList();

/**
 * Libera toda a memória alocada na lista
 * retorna NULL
 *
 * Node* first : o primeiro nó da lista
 */
Node* freeLinkedList(Node *first);

/**
 * Insere um nó no começo da lista
 * retorna NULL se não conseguir alocar a memória para o novo nó
 *
 * Node* first : primeiro nó da lista
 * int item : valor a ser inserido no nó
 */
Node* insertNode(Node* first, int item);

/**
 * Imprime itens da lista
 *
 * Node* first : primeiro nó da lista
 */
void printLinkedList(Node* first);

/**
 * Verifica se o nó é nulo
 * return 0 (false) se não é nulo
 * caso contrário retorna valor diferente de 0 (true)
 *
 * Node* node : primeiro nó da lista
 */
int isEmpty(Node *node);

/**
 * procura por um nó com um valor específico
 * retorna o nó se o encontrar
 * retorna NULL caso contrário
 *
 * Node* first : primeiro nó da lista
 * int item : valor procurado
 */
Node* search(Node* first, int item);

/**
 * Remove um nó com o conteúdo especificado e retorna um ponteiro
 * para o primeiro nó da lista
 * 
 * Node* first : o primeiro nó da lista
 * int item : o conteúdo do nó a ser removido
 */
Node* removeNode(Node *first, int item);

/**
 * Verifica se uma lista B é um subconjunto de uma lista A
 * Retorna 1 em caso positivo, e 0 em caso negativo
 *
 * Node* firstB : primeiro nó da lista B
 * Node* firstA : primeiro nó da lista A
 */
int isSubset(Node* firstB, Node* firstA);

/**
 * Inverte uma lista numa só "passada"
 * Retorna o primeiro nó da lista invertida
 *
 * Node* first : primeiro nó da lista
 */
Node* reverseList(Node* first);

NodeCharFreq* createCharLinkedList();

NodeCharFreq* freeCharLinkedList(NodeCharFreq *first);

void printCharLinkedList(NodeCharFreq* first);

/**
 * Cria uma lista de caracteres e a frequencia de cada um
 * Retorna o primeiro nó desta lista
 * 
 * char* literal : uma string literal contendo os caracteres
 */
NodeCharFreq* listOfCharFreq(char* literal,int sizeLiteral, NodeCharFreq* first);

Node* bubblesort(Node* first);

#endif // LINKED_LIST_H
