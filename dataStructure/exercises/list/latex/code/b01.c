Node* insertCircularNode(Node* first, int item){
    
    Node* newNode = NULL;
    newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return first;
    
    newNode->item = item;
    
    if(first==NULL){
        newNode->nextNode = newNode;
        newNode->previousNode = newNode;
        return newNode;
    }
    
    newNode->nextNode = first;
    newNode->previousNode = first->previousNode;
    first->previousNode = newNode;
    newNode->previousNode->nextNode = newNode;
    return newNode;
    
}
