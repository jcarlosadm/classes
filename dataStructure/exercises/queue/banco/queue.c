#include "queue.h"

typedef struct node Node;

struct node{
    int item;
    int priority;
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

void QUEUE_enqueue(Queue* queue, int item, int priority){
    
    Node* node = malloc(sizeof(Node));
    if(!node){
        printf("falha ao alocar memoria\n");
        return;
    }
    
    node->item = item;
    node->priority = priority;
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


/**
 * retira alguém da fila de acordo com o contador passado
 * (a cada três de prioridade baixa, um de prioridade alta é atendido)
 *
 * se retornar -1, então ninguém daquela prioridade foi encontrado
 */
int QUEUE_dequeue_priority(Queue* queue, int* count){
    if(QUEUE_isEmpty(queue)){
        printf("queue is empty\n");
        return -1;
    }
    else{
        int value = -1;
            
        Node* current = queue->first;
        Node* previous = NULL;
        
        if(*count < 3){
            
            while(current!=NULL && current->priority != BAIXA_PRIORIDADE){
                previous = current;
                current = current->nextNode;
            }
            
            if(!current){
                *count = 3;
                return -1;
            }
            
        }
        
        else{
            
            while(current!=NULL && current->priority != ALTA_PRIORIDADE){
                previous = current;
                current = current->nextNode;
            }
            
            if(!current){
                *count = 0;
                return -1;
            }
            
        }
        
        value = current->item;
            
        if(!previous)
            queue->first = current->nextNode;
        else
            previous->nextNode = current->nextNode;
        
        free(current);
        
        if(*count < 3)
            *count = *count + 1;
        else
            *count = 0;
        
        return value;
    }
}

