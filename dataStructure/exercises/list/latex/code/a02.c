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
