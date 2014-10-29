#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

typedef struct queue Queue;

Queue* QUEUE_createQueue();

Queue* QUEUE_free(Queue* queue);

void QUEUE_enqueue(Queue* queue, BinaryTree* item);

BinaryTree* QUEUE_dequeue(Queue* queue);

int QUEUE_isEmpty(Queue* queue);

#endif // QUEUE_H
