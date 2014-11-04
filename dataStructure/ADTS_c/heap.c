#include "heap.h"

// Quantidade máxima de elementos da heap
#define MAX_HEAP_SIZE 30

/**
 * Estrutura de um elemento da heap
 */
typedef struct element Element;
struct element{
    int value; ///< valor do elemento
    int priority; ///< prioridade do elemento
    int order; ///< ordem em que foi colocado na heap
};

/**
 * Estrutura da Heap
 */
struct heap{
    int size; ///< quantidade de elementos na heap
    int lastOrder; ///< ordem do último elemento enfileirado
    Element* elements[MAX_HEAP_SIZE]; ///< array de ponteiros para Element
};

/** **********************************************************************
 * Funções privadas
 *************************************************************************/

/**
 * Desaloca recursivamente cada elemento da heap
 */
void freeElements(Element** elements, int count){
    // condição de parada
    if(count<MAX_HEAP_SIZE){
        // se a posição atual tiver elemento alocado, desaloca
        if(elements[count]){
            free(elements[count]);
            elements[count] = NULL;
        }
        // chamada recursiva
        freeElements(elements, count+1);
    }
}

/**
 * Retorna índice do pai
 */
int returnParent(int index){
    return index/2;
}

/**
 * Retorna índice do filho da esquerda
 */
int returnLeftChild(int index){
    return index*2;
}

/**
 * Retorna índice do filho da direita
 */
int returnRightChild(int index){
    return index*2 +1;
}

void max_heapify(Heap* heap, int currentPosition){
    // pega os índices dos filhos à esquerda e direita
    int leftIndex = returnLeftChild(currentPosition);
    int rightIndex = returnRightChild(currentPosition);
    int largestIndex;
    
    if(leftIndex <= heap->size && 
    heap->elements[leftIndex-1]->priority >= heap->elements[currentPosition-1]->priority){
        // mesma prioridade
        if(heap->elements[leftIndex-1]->priority == heap->elements[currentPosition-1]->priority){
            // a esquerda enfileirado primeiro
            if(heap->elements[leftIndex-1]->order < heap->elements[currentPosition-1]->order)
                largestIndex = leftIndex;
            else
                largestIndex = currentPosition;
        }
        else
            largestIndex = leftIndex;
    }
    else
        largestIndex = currentPosition;
    
    if(rightIndex <= heap->size &&
    heap->elements[rightIndex-1]->priority >= heap->elements[largestIndex-1]->priority){
        // mesma prioridade
        if(heap->elements[rightIndex-1]->priority == heap->elements[largestIndex-1]->priority){
            // a direita enfileirado primeiro
            if(heap->elements[rightIndex-1]->order < heap->elements[largestIndex-1]->order)
                largestIndex = rightIndex;
        }
        else
            largestIndex = rightIndex;
    }
    
    if(largestIndex != currentPosition){
        Element* tempElement = heap->elements[currentPosition-1];
        heap->elements[currentPosition-1] = heap->elements[largestIndex-1];
        heap->elements[largestIndex-1] = tempElement;
        max_heapify(heap, largestIndex);
    }
}

/** **********************************************************************
 * Funções públicas
 *************************************************************************/

/**
 * Aloca memória para a heap
 * \return Retorna ponteiro para a memória alocada, ou
 * NULL se não conseguir alocar
 */
Heap* HEAP_create(){
    // aloca memória para a heap
    Heap* heap = malloc(sizeof(Heap));
    if(!heap){
        printf("Memory Allocation Failure\n");
        return NULL;
    }
    
    int count;
    // inicializa todos os elementos da heap com NULL
    for(count=0; count<MAX_HEAP_SIZE; count++){
        heap->elements[count] = NULL;
    }
    
    // heap tem 0 elementos
    heap->size = 0;
    heap->lastOrder = 0;
    
    return heap;
}

/**
 * Desaloca heap
 * \return Retorna NULL
 * \param heap Ponteiro para a heap
 */
Heap* HEAP_free(Heap* heap){
    // desaloca recursivamente a partir do 1º elemento (elemento 0)
    freeElements(heap->elements, 0);
}

/**
 * Enfileira elemento na heap
 * \return Ponteiro para a heap
 * \param heap Ponteiro para a heap
 * \param value Valor do elemento a ser enfileirado
 * \param priority Prioridade do elemento a ser enfileirado
 */
Heap* HEAP_enqueue(Heap* heap, int value, int priority){

    if(heap->size>=MAX_HEAP_SIZE){
        printf("heap is full\n");
        return heap;
    }
    
    // tenta alocar elemento
    Element* element = malloc(sizeof(Element));
    if(!element){
        printf("Memory Allocation Failure\n");
        return heap;
    }
    
    // preenche elemento
    element->value = value;
    element->priority = priority;
    element->order = ++heap->lastOrder;
    
    // coloca elemento na última posição disponível da heap
    // considerando o conceito de heap
    // e incrementa quantidade de elementos na heap
    heap->elements[heap->size++] = element;
    
    // chama heapfy para todos os nós parents do elemento até o topo
    int currentPosition = heap->size;
    while(currentPosition){
        max_heapify(heap, currentPosition);
        currentPosition = returnParent(currentPosition);
    }
    
    return heap;
}

/**
 * Retira elemento com maior prioridade da heap
 * \return Ponteiro para a heap
 * \param heap Ponteiro para a heap
 */
Heap* HEAP_dequeue(Heap* heap){
    
    // verifica se a heap está vazia
    if(heap->size == 0){
        printf("heap is empty\n");
        return heap;
    }
    
    // faz algo com o elemento do topo
    printf("value:%d; priority:%d\n", heap->elements[0]->value,
        heap->elements[0]->priority);
    
    // desaloca elemento do topo
    free(heap->elements[0]);
    heap->elements[0]=NULL;
    
    // se a heap tiver apenas um elemento, sai
    if(--heap->size == 0) return heap;
    
    // pega último elemento e coloca no topo
    heap->elements[0] = heap->elements[heap->size];
    
    // coloca última posição em NULL
    heap->elements[heap->size] = NULL;
    
    // faz max_heapify com o primeiro elemento
    max_heapify(heap, 1);
    
    return heap;
}

