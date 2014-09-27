/**
 * Move o nó de maior valor para o final
 * Retorna o primeiro nó da lista
 * 
 * Node* first : primeiro nó da lista
 */
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

/**
 * Ordena uma lista
 * Depende da função bubble
 * Retorna o primeiro nó da lista
 *
 * Node* first : primeiro nó da lista
 */
Node* bubblesort(Node* first){
    if(first == NULL)
        return NULL;
    else{
        first->nextNode = bubblesort(first->nextNode);
        first = bubble(first);
        return first;
    }
}
