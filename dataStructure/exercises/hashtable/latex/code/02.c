/**

Implementação da Estrutura Hashtable com close addressing.
Basta modificar a constante HASHTABLE_WITH_LIST para 1 se
desejar usar o método close addressing para resolver colisões,
ou 0 se desejar usar o método open addressing.

as diretivas #if, #else e #endif controlam aquilo que é compilado
de acordo com a constante HASHTABLE_WITH_LIST
                */

#include "hashtable.h"

// hash table com close addressing? 1 true, 0 false
#define HASHTABLE_WITH_LIST 1

// tamanho da table da hashtable
#define MAX_TABLE_SIZE 11

/**
 * Função que calcula uma posição na table
 * de acordo com a chave fornecida
 */
int hashFunction(int key){
    return (key % MAX_TABLE_SIZE);
}

#if HASHTABLE_WITH_LIST == 1

/** **************************************************************
 * Hash Table com closed addressing
 *****************************************************************/

/**
 * estrutura de cada elemento na hashtable
 */
typedef struct element Element;
struct element{
    int key;
    int value;
    Element* nextElement;
};

/**
 * Estrutura da hashtable
 */
struct hashtable{
    Element *table[MAX_TABLE_SIZE];
};

/**
 * (usada pela função HASHTABLE_createHashtable())
 * Inicializa a table de uma hashtable
 */
void initializeTable(Element** table, int count){
    if(count<MAX_TABLE_SIZE){
        table[count] = NULL;
        initializeTable(table,count+1);
    }
}

/**
 * Aloca memória para a hashtable
 * retorna ponteiro para a memória alocada
 * Retornará NULL se não conseguir alocar a memória
 */
Hashtable* createHashtable(){
    Hashtable* hashtable = malloc(sizeof(Hashtable));
    if(!hashtable) return NULL;
    
    initializeTable(hashtable->table,0);
    return hashtable;
}

/**
 * Função auxiliar de HASHTABLE_free()
 * Percorre todas as entradas da table e
 * libera qualquer memória que tenha sido alocada
 */
void freeTable(Element** table, int count){
    if(count<MAX_TABLE_SIZE){
        if(table[count]!=NULL){
            Element* element = table[count];
            Element* current = NULL;
            while(element != NULL){
                current = element;
                element = element->nextElement;
                free(current);
                current=NULL;
            }
            table[count] = NULL;
        }
        freeTable(table,count+1);
    }
}

/**
 * Libera memória alocada na hashtable
 * retorna NULL
 *
 * Hashtable* hashtable: ponteiro para a estrutura Hashtable
 */
Hashtable* HASHTABLE_free(Hashtable* hashtable){
    freeTable(hashtable->table, 0);
}

/**
 * Adiciona elemento na hashtable
 *
 * Hashtable* hashtable: ponteiro para a estrutura Hashtable
 * int key: chave do novo elemento
 * int value: valor do novo elemento
 */
void put(Hashtable* hashtable, int key, int value){
    int index = hashFunction(key);
    
    if(hashtable->table[index]!=NULL){
        Element* element = hashtable->table[index];
        while(element->nextElement != NULL && element->key != key){
            element = element->nextElement;
        }
        if(element->key == key){
            element->value = value;
        }
        else{
            Element* newElement = malloc(sizeof(Element));
            if(!newElement) return;
            newElement->key = key;
            newElement->value = value;
            newElement->nextElement = NULL;
            element->nextElement = newElement;
        }
    }
    else{
        Element* newElement = malloc(sizeof(Element));
        if(!newElement) return;
        newElement->key = key;
        newElement->value = value;
        newElement->nextElement = NULL;
        hashtable->table[index] = newElement;
    }
}

/**
 * Se o elemento da chave informada existir, retorna o valor
 * desse elemento.
 * retorna -100 em caso de falha.
 *
 * Hashtable* hashtable: ponteiro para a estrutura Hashtable
 * int key: chave do elemento a ser procurado
 */
int get(Hashtable* hashtable, int key){
    int index = hashFunction(key);
    
    if(hashtable->table[index] != NULL){
        Element* element = hashtable->table[index];
        while(element!=NULL && element->key != key)
            element = element->nextElement;
        
        if(!element) return -100;
        else
            return element->value;
    }
    else
        return -100;
}

/**
 * Remove um elemento da hashtable.
 *
 * Hashtable* hashtable: ponteiro para a estrutura hashtable
 * int key: chave do elemento a ser excluído
 */
void remove(Hashtable* hashtable, int key){
    int index = hashFunction(key);
    
    if(hashtable->table[index] != NULL){
        
        if(hashtable->table[index]->key == key){
            if(hashtable->table[index]->nextElement != NULL){
                Element* current = hashtable->table[index];
                hashtable->table[index] = 
                            hashtable->table[index]->nextElement;
                free(current);
                return;
            }
            else{
                free(hashtable->table[index]);
                hashtable->table[index] = NULL;
                return;
            }
        }
        
        Element* element = hashtable->table[index];
        
        while(element->nextElement!=NULL && 
                    element->nextElement->key != key)
            element = element->nextElement;
            
        if(!element->nextElement) return;
        else
        {
            if(element->nextElement->nextElement==NULL){
                free(element->nextElement);
                element->nextElement = NULL;
                return;
            }
            
            Element* current = element->nextElement;
            element->nextElement = element->nextElement->nextElement;
            free(current);
        }
    }
}

/**
 * Verifica se uma determinada chave já existe na hashtable
 * Retorna 1 se existir, e 0 em caso contrário
 *
 * Hashtable* hashtable: ponteiro para a estrutura hashtable
 * int key: chave do elemento a ser excluído
 */
int containsKey(Hashtable* hashtable, int key){
    int index = hashFunction(key);
    
    if(hashtable->table[index] != NULL){
        
        Element* element = hashtable->table[index];
        while(element!=NULL && element->key!=key)
            element = element->nextElement;
            
        if(!element) return 0;
        else
            return 1;
    }
    else
        return 0;
}

/**
 * função auxiliar de printHashtable()
 * percorre a table e imprime qualquer elemento alocado
 */
void printHashtableElement(Element** table, int count){
    if(count < MAX_TABLE_SIZE){
        if(table[count]!=NULL){
            Element* element = table[count];
            while(element!=NULL){
                printf("  %d  -   %d   -   %d\n",
                        count,element->key, element->value);
                element = element->nextElement;
            }
        }
        printHashtableElement(table,count+1);
    }
}

/**
 * imprime o conteúdo de todos os elementos da hashtable
 *
 * Hashtable* hashtable: ponteiro para a estrutura hashtable
 */
void printHashtable(Hashtable* hashtable){
    printf("index - key - value\n");
    printHashtableElement(hashtable->table,0);
}


#else

/** *************************************************************
 * Hash Table sem listas
 ****************************************************************/

// ... implementação com open addressing ...

#endif

