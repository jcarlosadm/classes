#include<stdio.h>
#include"queue.h"


int main(){
    
    
    Queue* queue = QUEUE_createQueue();
    
    QUEUE_enqueue(queue,5,BAIXA_PRIORIDADE);
    QUEUE_enqueue(queue,33,ALTA_PRIORIDADE);
    QUEUE_enqueue(queue,2,BAIXA_PRIORIDADE);
    QUEUE_enqueue(queue,6,BAIXA_PRIORIDADE);
    QUEUE_enqueue(queue,11,BAIXA_PRIORIDADE);
    QUEUE_enqueue(queue,1,ALTA_PRIORIDADE);
    QUEUE_enqueue(queue,15,BAIXA_PRIORIDADE);
    QUEUE_enqueue(queue,23,ALTA_PRIORIDADE);
    QUEUE_enqueue(queue,10,BAIXA_PRIORIDADE);
    QUEUE_enqueue(queue,41,ALTA_PRIORIDADE);
    
    int getValue;
    int count=0;
    
    while(!QUEUE_isEmpty(queue)){
        getValue = QUEUE_dequeue_priority(queue,&count);
        if(getValue!=-1){
            printf("%d foi atendido\n",getValue);
        }
    }
    
    queue = QUEUE_free(queue);
    
    return 0;
}
