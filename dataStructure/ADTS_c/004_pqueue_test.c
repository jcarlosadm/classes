#include <stdio.h>
#include "pqueue.h"

int main()
{
    
    PriorityQueue* queue = PQUEUE_createQueue();
    
    PQUEUE_enqueue(queue,3,10);
    //PQUEUE_enqueue(queue,1,20);
    PQUEUE_enqueue(queue,5,10);
    //PQUEUE_enqueue(queue,6,40);
    //PQUEUE_enqueue(queue,7,0);
    //PQUEUE_enqueue(queue,31,100);
    PQUEUE_enqueue(queue,12,10);
    
    PQUEUE_printPriorityQueue(queue);
    printf(" %d\n",PQUEUE_maximum(queue));
    
    printf(" %d",PQUEUE_dequeue(queue));
    printf(" %d",PQUEUE_dequeue(queue));
    printf(" %d",PQUEUE_dequeue(queue));
    //printf(" %d",PQUEUE_dequeue(queue));
    printf("\n");
    
    queue = PQUEUE_free(queue);
    
    return 0;
}
