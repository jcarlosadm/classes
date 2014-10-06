#include "Linked_list.h"

/** ******************************************************
 * Estruturas
 *********************************************************/
 
/**
 * Estrutura do nó da lista
 * Esse nó guarda um inteiro
 */
struct node {
    int item;
    struct node *nextNode;
};

/** ******************************************************
 * Funções públicas
 *********************************************************/

/**
 * Inicializa o primeiro nó da lista com NULL
 * retorna NULL
 */
Node* createLinkedList(){
    return NULL;
}

/**
 * Libera toda a memória alocada na lista
 * retorna NULL
 *
 * Node* first : o primeiro nó da lista
 */
Node* freeLinkedList(Node *first){
    
    if(first!=NULL){
        Node* previous = first;
        first = first->nextNode;
        free(previous);
        return freeLinkedList(first);
    }
    else{
        return NULL;
    }
    
}

/**
 * Insere um nó no começo da lista
 * retorna NULL se não conseguir alocar a memória para o novo nó
 *
 * Node* first : primeiro nó da lista
 * int item : valor a ser inserido no nó
 */
Node* insertNode(Node* first, int item){
    
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->item = item;
    newNode->nextNode = first;
    return newNode;
    
}

/**
 * Imprime itens da lista
 *
 * Node* first : primeiro nó da lista
 */
void printLinkedList(Node* first){

    if(!isEmpty(first)){
        printf(" %d",first->item);
        printLinkedList(first->nextNode);
    }
    else{
        printf("\n");
    }
}

/**
 * Verifica se o nó é nulo
 * return 0 (false) se não é nulo
 * caso contrário retorna valor diferente de 0 (true)
 *
 * Node* node : primeiro nó da lista
 */
int isEmpty(Node *node){
    return (node==NULL);
}

/**
 * procura por um nó com um valor específico
 * retorna o nó se o encontrar
 * retorna NULL caso contrário
 *
 * Node* first : primeiro nó da lista
 * int item : valor procurado
 */
Node* search(Node* first, int item){
    
    if(first!=NULL){
        if(first->item == item){
            return first;
        }
        else{
            return search(first->nextNode,item);
        }
    }
    else{
        return NULL;
    }
    
}

/**
 * Remove um nó com o conteúdo especificado e retorna um ponteiro
 * para o primeiro nó da lista
 * 
 * Node* first : o primeiro nó da lista
 * int item : o conteúdo do nó a ser removido
 */
Node* removeNode(Node *first, int item){
    
    if(first!=NULL){
    
        if(first->item == item){
            Node* previous = first;
            first = first->nextNode;
            free(previous);
        }
        else{
            first->nextNode = removeNode(first->nextNode,item);
        }
        
        return first;
    }
    else{
        return NULL;
    }
    
}

/**
 * Verifica se uma lista B é um subconjunto de uma lista A
 * Retorna 1 em caso positivo, e 0 em caso negativo
 *
 * Node* firstB : primeiro nó da lista B
 * Node* firstA : primeiro nó da lista A
 */
int isSubset(Node* firstB, Node* firstA){
    
    if(firstB==NULL)
        return 1;
    else{
        if(search(firstA,firstB->item)==NULL)
            return 0;
        else
            return isSubset(firstB->nextNode, firstA);
    }
    
}

/**
 * Inverte uma lista numa só "passada"
 * Retorna o primeiro nó da lista invertida
 *
 * Node* first : primeiro nó da lista
 */
Node* reverseList(Node* first){
    
    if(first != NULL){
        if(first->nextNode != NULL){
            Node* last = reverseList(first->nextNode);
            (first->nextNode)->nextNode = first;
            first->nextNode = NULL;
            return last;
        }
        else{
            return first;
        }
    }
    else
        return NULL;
    
}

/**
 * Estrutura para a função listOfCharFreq
 */
struct nodeCharFreq{
    char item[1];
    int freq;
    NodeCharFreq *nextNode;
};

NodeCharFreq* createCharLinkedList(){
    return NULL;
}

NodeCharFreq* freeCharLinkedList(NodeCharFreq *first){
    
    if(first!=NULL){
        NodeCharFreq* previous = first;
        first = first->nextNode;
        free(previous);
        return freeCharLinkedList(first);
    }
    else{
        return NULL;
    }
    
}

NodeCharFreq* insertNodeCharFreq(NodeCharFreq* first, char* item, int freq){
    
    NodeCharFreq* newNode = (NodeCharFreq*) malloc(sizeof(NodeCharFreq));
    newNode->item[0] = *(item);
    newNode->item[1] = 0;
    newNode->freq = freq;
    newNode->nextNode = first;
    return newNode;
    
}

void printCharLinkedList(NodeCharFreq* first){

    if(first!=NULL){
        printf(" [%c - %d]",first->item[0],first->freq);
        printCharLinkedList(first->nextNode);
    }
    else{
        printf("\n");
    }
}

int countCharFreq(char* literal,char* item){
    if(literal[0] == 0)
        return 0;
    else{
        if(literal[0]==item[0])
            return 1 + countCharFreq(literal+1,item);
        else
            return countCharFreq(literal+1,item);
    }
}

void fillNewChar(char* literal, char* newCharLiteral, char* compare){
    
    if(literal[0]==0){
        newCharLiteral[0]=0;
        return;
    }
    else{
        if(literal[0]!=compare[0]){
            newCharLiteral[0]=literal[0];
            fillNewChar(literal+1,newCharLiteral+1,compare);
        }
        else{
            fillNewChar(literal+1,newCharLiteral,compare);
        }
    }
    
}

/**
 * Cria uma lista de caracteres e a frequencia de cada um
 * Retorna o primeiro nó desta lista
 * 
 * char* literal : uma string literal contendo os caracteres
 * NodeCharFreq* first : lista de caracteres
 */
NodeCharFreq* listOfCharFreq(char* literal,int sizeLiteral, NodeCharFreq* first){
    
    if(literal[0] != 0){
        int totalFreq = countCharFreq(literal,literal);
        first = insertNodeCharFreq(first,literal,totalFreq);
        if((sizeLiteral-totalFreq) > 0){
            
            char* newCharLiteral = malloc(sizeof(sizeLiteral-totalFreq));
            
            fillNewChar(literal+1,newCharLiteral, literal);
            
            NodeCharFreq* newList = listOfCharFreq(newCharLiteral,sizeLiteral-totalFreq,first);
            free(newCharLiteral);
            return newList;
        }
        else
            return first;
        
    }
    else
        return first;
    
}

Node* bubble(Node* first){
    if(first==NULL)
        return NULL;
    else if(first->nextNode != NULL){
        if(first->item > first->nextNode->item){
            Node* next = first->nextNode;
            first->nextNode = next->nextNode;
            next->nextNode = bubble(first);
            return next;
        }
        else{
            first->nextNode = bubble(first->nextNode);
            return first;
        }
    }
    else
        return first;
}

Node* listsort(Node* first){
    if(first == NULL)
        return NULL;
    else{
        first->nextNode = listsort(first->nextNode);
        first = bubble(first);
        return first;
    }
}
