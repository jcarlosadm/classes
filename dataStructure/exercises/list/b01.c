typedef struct node Node;

typedef struct circularLinkedList CircularLinkedList;

struct node{
    int item;
    Node* nextNode;
    Node* previousNode;
};

struct circularLinkedList{
    
    Node* head;
    Node* tail;
    int size;
    
};

CircularLinkedList* createCircularLinkedList(){
    CircularLinkedList* newList = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    newList->head=NULL;
    newList->tail=NULL;
    newList->size=0;
}

CircularLinkedList* insertNode(CircularLinkedList* list, int item){
    
    Node* newNode = NULL;
    newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return list;
    
    newNode->item = item;
    
    if(list->head==NULL){
        newNode->nextNode = newNode;
        newNode->previousNode = newNode;
        list->head = newNode;
        list->tail = newNode;
    }
    else{
        newNode->nextNode = list->head;
        newNode->previousNode = list->tail;
        list->head->previousNode = newNode;
        list->tail->nextNode = newNode;
        list->head = newNode;
    }
    
    (list->size)++;
    
}
