#include "pqueue.h"

typedef struct node Node;

struct node{
    int item;
    int priority;
    Node* nextNode;
};

struct priorityqueue{
    Node* first;
};

PriorityQueue* PQUEUE_createQueue(){
    PriorityQueue* queue = malloc(sizeof(PriorityQueue));
    if(!queue)return NULL;
    
    queue->first = NULL;
    
    return queue;
}

Node* freeNodes(Node* node){
    if(!node)
        return NULL;
    else{
        Node* next = node->nextNode;
        free(node);
        return freeNodes(next);
    }
}

PriorityQueue* PQUEUE_free(PriorityQueue* queue){
    queue->first = freeNodes(queue->first);
    free(queue);
    return NULL;
}

void PQUEUE_enqueue(PriorityQueue* queue, int item, int priority){
    Node* newNode = malloc(sizeof(Node));
    if(!newNode){
        printf("falha ao alocar novo no\n");
        return;
    }
    
    newNode->item = item;
    newNode->priority = priority;
    
    if(queue->first == NULL || priority > queue->first->priority){
        newNode->nextNode = queue->first;
        queue->first = newNode;
    }
    else{
        Node* current = queue->first;
        while(current->nextNode!=NULL && current->nextNode->priority >= priority)
            current = current->nextNode;
        
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }
    
}

int PQUEUE_dequeue(PriorityQueue* queue){
    if(PQUEUE_isEmpty(queue)){
        printf("queue is empty!\n");
        return -1;
    }
    else{
        int value = queue->first->item;
        Node* current = queue->first;
        queue->first = queue->first->nextNode;
        free(current);
        return value;
    }
}

int PQUEUE_maximum(PriorityQueue* queue){
    return queue->first->item;
}

void printNode(Node* node){
    if(node){
        printf(" %d",node->item);
        printNode(node->nextNode);
    }
}

void PQUEUE_printPriorityQueue(PriorityQueue* queue){
    if(!PQUEUE_isEmpty(queue)){
        printNode(queue->first);
        printf("\n");
    }
}

int PQUEUE_isEmpty(PriorityQueue* queue){
    return (queue->first == NULL);
}

