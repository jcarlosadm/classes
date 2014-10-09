#ifndef PQUEUE_H
#define PQUEUE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct priorityqueue PriorityQueue;

PriorityQueue* PQUEUE_createQueue();

PriorityQueue* PQUEUE_free(PriorityQueue* queue);

void PQUEUE_enqueue(PriorityQueue* queue, int item, int priority);

int PQUEUE_dequeue(PriorityQueue* queue);

int PQUEUE_maximum(PriorityQueue* queue);

void PQUEUE_printPriorityQueue(PriorityQueue* queue);

int PQUEUE_isEmpty(PriorityQueue* queue);

#endif // PQUEUE_H
