#include<stdio.h>
#include"queue.h"

int main()
{
    
    Queue* queue = QUEUE_createQueue();
    
    if(!queue){
        printf("falha ao alocar queue\n");
        return 1;
    }
    
    QUEUE_enqueue(queue,4);
    QUEUE_enqueue(queue,1);
    QUEUE_enqueue(queue,5);
    QUEUE_enqueue(queue,7);
    QUEUE_enqueue(queue,2);
    
    printf(" %d",QUEUE_dequeue(queue));
    printf(" %d",QUEUE_dequeue(queue));
    printf(" %d",QUEUE_dequeue(queue));
    printf(" %d",QUEUE_dequeue(queue));
    printf(" %d",QUEUE_dequeue(queue));
    
    printf("\n");
    
    queue = QUEUE_free(queue);
    
    return 0;
}
