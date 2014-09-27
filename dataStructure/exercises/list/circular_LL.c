#include "circular_LL.h"


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

Node* freeNodesCircularLinkedList(Node* first,int sizeList){
    if(sizeList>0)
    {
        if(sizeList==1){
            free(first);
            return NULL;
        }
        else{
            first = first->nextNode;
            free(first->previousNode);
            first->previousNode=NULL;
            return freeNodesCircularLinkedList(first,sizeList-1);
        }
        
    }
    else
        return NULL;
}

CircularLinkedList* freeCircularLinkedList(CircularLinkedList* list){
    
    if(list->head!=NULL){
        list->head = freeNodesCircularLinkedList(list->head,list->size);
        list->tail=NULL;
        list->size=0;
    }
    else
        return NULL;
    
}

void printNodesCircularLinkedList(Node* first,int sizeList){
    if(sizeList>0){
        printf(" %d",first->item);
        printNodesCircularLinkedList(first->nextNode,sizeList-1);
    }
    else{
        printf("\n");
    }
}

void printCircularLinkedList(CircularLinkedList* list){
    
    printNodesCircularLinkedList(list->head,list->size);
    
}
