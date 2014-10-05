/**
 * Insere nó à esquerda da última inserção, em uma posição adequada
 * Retorna ponteiro para o nó inserido
 *
 * Node* current: nó atual
 * Node* right: nó à direita do nó atual
 * int item: valor a ser inserido
 */
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

/**
 * Insere nó à direita da última inserção, em uma posição adequada
 * Retorna ponteiro para o nó inserido
 *
 * Node* current: nó atual
 * Node* left: nó à esquerda do nó atual
 * int item: valor a ser inserido
 */
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
/**
 * Insere nó de forma ordenada
 * retorna ponteiro para o nó inserido
 *
 * Node* middle: ponteiro para o nó da última inserção
 *      (não necessariamente presente no meio da lista)
 * int item: valor a ser inserido no novo nó
 */
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
