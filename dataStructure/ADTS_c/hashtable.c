#include "hashtable.h"

// hash table com listas? 1 true, 0 false
#define HASHTABLE_WITH_LIST 0

// tamanho da table da hashTable
#define MAX_TABLE_SIZE 11

/**
 * Função que calcula uma posição na table
 * de acordo com a chave fornecida
 */
int hashFunction(int key){
    return (key % MAX_TABLE_SIZE);
}

/** **************************************************************
 * Hash Table com listas
 *****************************************************************/
#if HASHTABLE_WITH_LIST == 1

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





/** *************************************************************
 * Hash Table sem listas
 ****************************************************************/
#else

/**
 * estrutura de cada elemento na hashTable
 */
typedef struct element Element;
struct element{
    int key;
    int value;
};

/**
 * Estrutura da hashtable
 */
struct hashTable{
    int size;
    Element* table[MAX_TABLE_SIZE];
};

/**
 * Inicializa a table de uma hashTable
 */
void initializeTable(Element** table, int count){
    if(count<MAX_TABLE_SIZE){
        table[count] = NULL;
        initializeTable(table,count+1);
    }
}

/**
 * Aloca memória para a hashTable
 * retorna ponteiro para a memória alocada
 * Retornará NULL se não conseguir alocar a memória
 */
HashTable* HASHTABLE_createHashTable(){
    HashTable* hashTable = malloc(sizeof(HashTable));
    if(!hashTable) return NULL;
    
    initializeTable(hashTable->table,0);
    hashTable->size = 0;
    
    return hashTable;
}

void freeTable(Element** table, int count){
    if(count<MAX_TABLE_SIZE){
        if(table[count]!=NULL){
            free(table[count]);
            table[count]=NULL;
        }
        freeTable(table, count+1);
    }
}

/**
 * Libera memória alocada na hashTable
 * retorna NULL
 *
 * HashTable* hashTable: ponteiro para a estrutura HashTable
 */
HashTable* HASHTABLE_free(HashTable* hashTable){
    freeTable(hashTable->table,0);
    free(hashTable);
    return NULL;
}

/**
 * Adiciona elemento na hashTable
 * retorna 0 se não conseguir inserir o elemento por falha de alocação
 * ou se a table estiver cheia, ou 1 em caso de sucesso.
 *
 * HashTable* hashTable: ponteiro para a estrutura HashTable
 * int key: chave do novo elemento
 * int value: valor do novo elemento
 */
int HASHTABLE_put(HashTable* hashTable, int key, int value){

    if(hashTable->size >= MAX_TABLE_SIZE){
        printf("table is full!\n");
        return 0;
    }
    
    int index = hashFunction(key);
    
    int lockPosition = 0;
    int lockedPosition = -1;
    
    while(hashTable->table[index] != NULL){
        if(!lockPosition){
            if(hashTable->table[index]->key == -1){
                lockedPosition = index;
                lockPosition = 1;
            }
        }
        else{
            if(index==lockedPosition)
                break;
        }
        
        if(hashTable->table[index]->key == key){
            hashTable->table[index]->value = value;
            return 1;
        }
        
        index = (index + 1) % MAX_TABLE_SIZE;
    }
    
    if(lockPosition){
        hashTable->table[lockedPosition]->key = key;
        hashTable->table[lockedPosition]->value = value;
        hashTable->size++;
        return 1;
    }
    
    Element* newElement = malloc(sizeof(Element));
    if(!newElement) return 0;
    newElement->key = key;
    newElement->value = value;
    hashTable->table[index] = newElement;
    hashTable->size++;
    return 1;
    
}

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
int HASHTABLE_get(HashTable* hashTable, int key, int* result){
    if(hashTable->size <= 0){
        printf("table is empty!\n");
        return 0;
    }
    
    int count = 0;
    int index = hashFunction(key);
    
    while(hashTable->table[index] != NULL){
        if(count>=MAX_TABLE_SIZE)
            return 0;
        
        if(hashTable->table[index]->key == key){
            *result = hashTable->table[index]->value;
            return 1;
        }
        
        index = (index+1)%MAX_TABLE_SIZE;
        count++;
    }
    
    return 0;
}

/**
 * Verifica se uma determinada chave já existe na hashTable
 * Retorna 1 se existir, e 0 em caso contrário
 *
 * HashTable* hashTable: ponteiro para a estrutura hashTable
 * int key: chave do elemento a ser excluído
 */
int HASHTABLE_containsKey(HashTable* hashTable, int key){
    if(hashTable->size <= 0){
        printf("table is empty!\n");
        return 0;
    }
    
    int count = 0;
    int index = hashFunction(key);
    
    while(hashTable->table[index] != NULL){
        if(count>=MAX_TABLE_SIZE)
            return 0;
        
        if(hashTable->table[index]->key == key)
            return 1;
        
        index = (index+1)%MAX_TABLE_SIZE;
        count++;
    }
    
    return 0;
}

/**
 * Remove um elemento da hashTable.
 * retorna 0 se o elemento não for encontrado, e 1 em caso contrário.
 *
 * HashTable* hashTable: ponteiro para a estrutura hashTable
 * int key: chave do elemento a ser excluído
 */
int HASHTABLE_remove(HashTable* hashTable, int key){
    
    if(hashTable->size <= 0){
        printf("table is empty!\n");
        return 0;
    }
    
    int count = 0;
    int index = hashFunction(key);
    
    while(hashTable->table[index] != NULL){
        if(count >= MAX_TABLE_SIZE)
            return 0;
        
        if(hashTable->table[index]->key == key){
            hashTable->table[index]->key = -1;
            hashTable->size--;
            return 1;
        }
        
        index = (index+1) % MAX_TABLE_SIZE;
        count++;
    }
    
    return 0;
}

void printHashTableElement(Element** table, int count){
    if(count<MAX_TABLE_SIZE){
        if(table[count] != NULL && table[count]->key != -1)
            printf("  %d  -  %d  -  %d\n",count, table[count]->key, table[count]->value);
        printHashTableElement(table,count+1);
    }
}

/**
 * imprime o conteúdo de todos os elementos da hashTable
 *
 * HashTable* hashTable: ponteiro para a estrutura hashTable
 */
void HASHTABLE_printHashTable(HashTable* hashTable){
    printf("index - key - value\n");
    printHashTableElement(hashTable->table,0);
}

#endif







