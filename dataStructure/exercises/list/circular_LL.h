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

typedef struct circularLinkedList CircularLinkedList;

/**
 * Inicializa o primeiro nó da lista
 * com NULL
 * Retorna NULL
 */
CircularLinkedList* createCircularLinkedList();

/**
 * Libera toda a memória alocada na lista
 * retorna NULL
 *
 * Node* first : o primeiro nó da lista
 */
CircularLinkedList* freeCircularLinkedList(CircularLinkedList* list);

/**
 * Insere um nó no começo da lista
 * retorna NULL se não conseguir alocar a memória para o novo nó
 *
 * Node* first : primeiro nó da lista
 * int item : valor a ser inserido no nó
 */
CircularLinkedList* insertNode(CircularLinkedList* list, int item);

/**
 * Imprime itens da lista de first até o final
 *
 * Node* first : primeiro nó da lista
 */
void printCircularLinkedList(CircularLinkedList* list);
