/**
 * Aloca sentinela da lista circular e o retorna
 */
Node* createCircularList(){

    // aloca sentinela (retorna NULL se não conseguir)
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return NULL;
    
    // o próximo nó da sentinela é a própria sentinela
    newNode->nextNode = newNode;
    // o mesmo acontece com o nó anterior
    newNode->previousNode = newNode;
    
    // retorna a sentinela
    return newNode;
}

/**
 * Insere um nó na lista circular
 * Retorna 1 se bem sucedido. Retorna 0 caso contrário
 *
 * Node* sentinel: ponteiro para a sentinela da lista
 * int item: valor a ser inserido no nó
 */
int insertCircularNode(Node* sentinel, int item){
    
    // se a sentinela for nula, a lista não foi inicializada!
    if(sentinel==NULL) return 0;
    
    // tenta alocar o novo nó (retorna 0 se não conseguir)
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return 0;
    
    // preenche o novo nó
    newNode->item = item;
    // o próximo nó do novo nó é o próximo nó da sentinela
    newNode->nextNode = sentinel->nextNode;
    // o nó anterior do novo nó é a sentinela
    newNode->previousNode = sentinel;
    
    // o nó anterior do próximo nó da sentinela é o novo nó
    sentinel->nextNode->previousNode = newNode;
    // o próximo nó da sentinela é o novo nó
    sentinel->nextNode = newNode;
    
    // retorna sucesso
    return 1;
    
}
