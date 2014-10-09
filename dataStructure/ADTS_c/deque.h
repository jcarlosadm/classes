#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct deque Deque;

Deque* DEQUE_createQueue();

Deque* DEQUE_free(Deque* deque);

int DEQUE_pushFront(Deque* deque, int item);

int DEQUE_pushBack(Deque* deque, int item);

int DEQUE_popFront(Deque* deque);

int DEQUE_popBack(Deque* deque);

void DEQUE_printDeque(Deque* deque);

int DEQUE_isEmpty(Deque* deque);

#endif // DEQUE_H
