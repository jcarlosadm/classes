#include <stdio.h>
#include "deque.h"

int main()
{
    Deque* deque = DEQUE_createQueue();
    
    DEQUE_pushFront(deque,5);
    DEQUE_pushFront(deque,2);
    DEQUE_pushBack(deque,0);
    DEQUE_pushFront(deque,1);
    DEQUE_pushBack(deque,11);
    DEQUE_pushBack(deque,20);
    DEQUE_pushFront(deque,3);
    DEQUE_pushFront(deque,6);
    DEQUE_pushBack(deque,45);
    DEQUE_pushFront(deque,7);
    
    DEQUE_printDeque(deque);
    DEQUE_popBack(deque);
    DEQUE_printDeque(deque);
    DEQUE_popFront(deque);
    DEQUE_printDeque(deque);
    
    deque = DEQUE_free(deque);
    
    return 0;
}
