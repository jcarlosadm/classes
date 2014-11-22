#include <stdio.h>
#include "heap.h"

int
main (int argc, char *argv[])
{
    
    Heap* heap = HEAP_create();
    
    heap = HEAP_enqueue(heap, 5, 10);
    heap = HEAP_enqueue(heap, 45,40);
    heap = HEAP_enqueue(heap, 23,70);
    heap = HEAP_enqueue(heap, 1, 70);
    heap = HEAP_enqueue(heap, 6, 20);
    heap = HEAP_enqueue(heap, 2, 40);
    heap = HEAP_enqueue(heap, 8, 90);
    
    heap = HEAP_dequeue(heap);
    heap = HEAP_dequeue(heap);
    heap = HEAP_dequeue(heap);
    heap = HEAP_dequeue(heap);
    heap = HEAP_dequeue(heap);
    heap = HEAP_dequeue(heap);
    heap = HEAP_dequeue(heap);
    
    heap = HEAP_free(heap);
    
    return 0;
}
