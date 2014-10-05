#include "Doubly_Linked_list.h"

/**
 * Estrutura do nó da lista
 * Esse nó guarda um inteiro
 */
struct node{
    int item;
    Node* nextNode;
    Node* previousNode;
};

/** *************************************************
 * Funções privadas
 ****************************************************/

Node* getFirstNode(Node* node){
    
    if(node==NULL)
        return NULL;
    else if(node->previousNode==NULL)
        return node;
    else
        return getFirstNode(node->previousNode);
}

Node* getLastNode(Node* node){
    if(node==NULL)
        return NULL;
    else if(node->nextNode==NULL)
        return node;
    else
        return getLastNode(node->nextNode);
}

void printForward(Node *node){
    if(node!=NULL){
        printf(" %d",node->item);
        if(node->nextNode!=NULL)
            printForward(node->nextNode);
        else
            printForward(NULL);
    }
    else
        printf("\n");
}

void printBackward(Node* node){
    if(node!=NULL){
        printf(" %d",node->item);
        if(node->previousNode!=NULL)
            printBackward(node->previousNode);
        else
            printBackward(NULL);
    }
    else
        printf("\n");
}


/** *************************************************
 * Funções públicas
 ****************************************************/
 
/**
 * Inicializa o primeiro nó da lista com NULL
 * Retorna NULL
 */
Node* createDoublyLinkedList(){
    return NULL;
}

/**
 * Libera toda a memória alocada na lista
 * retorna NULL
 *
 * Node* first : o primeiro nó da lista
 */
Node* freeLinkedList(Node *first){
    
    if(first != NULL && first->previousNode != NULL)
        first = getFirstNode(first);
    
    if(first!=NULL){
        
        if(first->nextNode!=NULL){
            first = first->nextNode;
            free(first->previousNode);
            first->previousNode = NULL;
            return freeLinkedList(first);
        }
        else{
            free(first);
            return NULL;
        }
        
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
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->nextNode = first;
    newNode->previousNode = NULL;
    newNode->item = item;
    
    if(first!=NULL)
        first->previousNode = newNode;
    
    return newNode;
}

/**
 * Imprime itens da lista de first até o final
 *
 * Node* first : primeiro nó da lista
 */
void printDoublyLinkedListForward(Node* first){
    printForward(getFirstNode(first));
}

/**
 * Imprime itens da lista de last até o começo
 *
 * Node* last : último nó da lista
 */
void printDoublyLinkedListBackward(Node* last){
    printBackward(getLastNode(last));
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
        if(first->item==item)
            return first;
        else
            return search(first->nextNode,item);
    }
    else
        return NULL;
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
            if(first->nextNode==NULL){
                free(first);
                first=NULL;
                return first;
            }
            
            else if(first->previousNode==NULL){
                first = first->nextNode;
                free(first->previousNode);
                first->previousNode=NULL;
                return first;
            }
            
            else{
                Node* current = first;
                first->previousNode->nextNode = first->nextNode;
                first->nextNode->previousNode = first->previousNode;
                first = current->nextNode;
                free(current);
                return first;
            }
        }
        else{
            first->nextNode = removeNode(first->nextNode,item);
            return first;
        }
        
    }
    else{
        return NULL;
    }
    
}


Node* insertLeft(Node* current, Node* right, int item){
    if(current==NULL){
        Node* newNode = (Node*)malloc(sizeof(Node));
        if(!newNode)return right;
        
        newNode->item = item;
        newNode->nextNode = right;
        newNode->previousNode = NULL;
        
        right->previousNode = newNode;
        return newNode;
        
    }
    else if(current->item < item){
        Node* newNode = (Node*)malloc(sizeof(Node));
        if(!newNode)return current;
        
        newNode->item = item;
        newNode->nextNode = current->nextNode;
        newNode->previousNode = current;
        
        current->nextNode->previousNode = newNode;
        current->nextNode = newNode;
        
        return newNode;
    }
    else{
        return insertLeft(current->previousNode,current,item);
    }
}
/////////////////////
Node* insertRight(Node* current, Node* left, int item){
    if(current==NULL){
        Node* newNode = (Node*)malloc(sizeof(Node));
        if(!newNode)return left;
        
        newNode->item = item;
        newNode->nextNode = NULL;
        newNode->previousNode = left;
        
        left->nextNode = newNode;
        return newNode;
        
    }
    else if(current->item > item){
        Node* newNode = (Node*)malloc(sizeof(Node));
        if(!newNode)return current;
        
        newNode->item = item;
        newNode->nextNode = current;
        newNode->previousNode = current->previousNode;
        
        current->previousNode->nextNode = newNode;
        current->previousNode = newNode;
        
        return newNode;
    }
    else{
        return insertRight(current->nextNode,current,item);
    }
}
///////////////////////
Node* insertOrderedNode(Node* middle, int item){
    
    if(middle==NULL){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->item = item;
        newNode->nextNode = NULL;
        newNode->previousNode = NULL;
        return newNode;
    }
    else{
        if(middle->item > item){
            return insertLeft(middle->previousNode,middle,item);
        }
        else{
            return insertRight(middle->nextNode,middle,item);
        }
    }
    
}

