#ifndef QUEUE_H
#define QUEUE_H

#include<stdio.h>
#include<stdlib.h>

#define BAIXA_PRIORIDADE 1
#define ALTA_PRIORIDADE 10

typedef struct queue Queue;

Queue* QUEUE_createQueue();

Queue* QUEUE_free(Queue* queue);

void QUEUE_enqueue(Queue* queue, int item, int priority);

int QUEUE_dequeue(Queue* queue);

int QUEUE_isEmpty(Queue* queue);

int QUEUE_dequeue_priority(Queue* queue, int* count);

#endif // QUEUE_H
