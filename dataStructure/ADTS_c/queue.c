#include "queue.h"

// 1 para true e 0 para false
#define DINAMIC 0


#if DINAMIC == 0

#define MAX_QUEUE_SIZE 10

struct queue{
    int currentSize;
    int first;
    int last;
    int items[MAX_QUEUE_SIZE];
};

Queue* QUEUE_createQueue(){
    Queue* queue = malloc(sizeof(Queue));
    if(!queue) return NULL;
    
    queue->currentSize = 0;
    queue->first = 0;
    queue->last = MAX_QUEUE_SIZE-1;
    
    return queue;
}

Queue* QUEUE_free(Queue* queue){
    free(queue);
    return NULL;
}

void QUEUE_enqueue(Queue* queue, int item){
    if(queue->currentSize >= MAX_QUEUE_SIZE)
        printf("queue is full!\n");
    else{
        queue->last = (queue->last+1) % MAX_QUEUE_SIZE;
        queue->items[queue->last]=item;
        queue->currentSize++;
    }
}

int QUEUE_dequeue(Queue* queue){
    if(QUEUE_isEmpty(queue)){
        printf("queue is empty\n");
        return -1;
    }
    else{
        int value = queue->items[queue->first];
        queue->first = (queue->first+1)%MAX_QUEUE_SIZE;
        queue->currentSize--;
        return value;
    }
}

int QUEUE_isEmpty(Queue* queue){
    return (queue->currentSize == 0);
}

#else

typedef struct node Node;

struct node{
    int item;
    Node* nextNode;
};

struct queue{
    Node* first;
};

Queue* QUEUE_createQueue(){
    Queue* queue = malloc(sizeof(Queue));
    if(!queue) return NULL;
    
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

Queue* QUEUE_free(Queue* queue){
    queue->first = freeNodes(queue->first);
    free(queue);
    return NULL;
}

void QUEUE_enqueue(Queue* queue, int item){
    
    Node* node = malloc(sizeof(Node));
    if(!node){
        printf("falha ao alocar memoria\n");
        return;
    }
    
    node->item = item;
    node->nextNode = NULL;
    
    if(!(queue->first)){
        queue->first = node;
    }
    else{
        Node* current = queue->first;
        while(current->nextNode!=NULL){
            current = current->nextNode;
        }
        current->nextNode = node;
    }
}

int QUEUE_dequeue(Queue* queue){
    if(QUEUE_isEmpty(queue)){
        printf("queue is empty\n");
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

int QUEUE_isEmpty(Queue* queue){
    return (queue->first == NULL);
}

#endif
