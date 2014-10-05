#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include<stdio.h>
#include<stdlib.h>

/**
 * ADT da lista duplamente encadeada
 */

/**
 * Estrutura do nó da lista
 * Esse nó guarda um inteiro
 */
typedef struct node Node;

/**
 * Inicializa o primeiro nó da lista
 * com NULL
 * Retorna NULL
 */
Node* createDoublyLinkedList();

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
 * Imprime itens da lista de first até o final
 *
 * Node* first : primeiro nó da lista
 */
void printDoublyLinkedListForward(Node* first);

/**
 * Imprime itens da lista de last até o começo
 *
 * Node* last : último nó da lista
 */
void printDoublyLinkedListBackward(Node* last);

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

Node* insertOrderedNode(Node* middle, int item);

#endif // DOUBLY_LINKED_LIST_H
