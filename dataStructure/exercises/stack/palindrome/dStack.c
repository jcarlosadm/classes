#include "dStack.h"

/**
 * Estrutura do nó da pilha
 */
typedef struct node Node;

struct node{
    char item;
    Node* nextNode;
};

/**
 * Estrutura da pilha
 */
struct dStack{
    Node* top;
};

/** ******************************************************************
 * Funções privadas
 *********************************************************************/

Node* dStackFreeNodes(Node* topNode){
    if(topNode){
        Node* prev = topNode;
        topNode = topNode->nextNode;
        free(prev);
        return dStackFreeNodes(topNode);
    }
    else{
        return NULL;
    }
}

/** ******************************************************************
 * Funções públicas
 *********************************************************************/

/**
 * Inicializa pilha
 * Aloca pilha e retorna ponteiro para a pilha alocada
 */
DStack *dStackCreateStack(){
    DStack* stack = (DStack*)malloc(sizeof(DStack));
    if(!stack) return NULL;
    stack->top = NULL;
    return stack;
}

/**
 * Libera memória alocada na pilha
 * 
 * DStack* dStack: ponteiro para a pilha
 */
DStack *dStackFree(DStack* stack){
    if(stack){
        stack->top = dStackFreeNodes(stack->top);
        free(stack);
        return NULL;
    }
}

/**
 * Adiciona elemento no topo da pilha
 *
 * DStack* stack: ponteiro para a pilha
 * int item: valor a ser adicionado no topo da pilha
 */
void dStackPush(DStack* stack, char item){
    Node* topNode = (Node*)malloc(sizeof(Node));
    if(!topNode)return;
    
    topNode->item = item;
    topNode->nextNode = stack->top;
    stack->top = topNode;
}

/**
 * Retira elemento do topo da pilha e o retorna o seu valor
 * 
 * DStack* stack: ponteiro para a pilha
 */
char dStackPop(DStack* stack){
    if(!dStackIsEmpty(stack)){
        char value = stack->top->item;
        Node* oldTop = stack->top;
        stack->top = stack->top->nextNode;
        free(oldTop);
        return value;
    }else{
        printf("stack is empty\n");
    }
}

/**
 * Retorna valor do topo da pilha (sem remover)
 *
 * DStack* stack: ponteiro para a pilha
 */
char dStackPeek(DStack* stack){
    if(!dStackIsEmpty(stack)){
        return stack->top->item;
    }else{
        printf("stack is empty!");
    }
}

/**
 * Verifica se a pilha está vazia
 * retorna 1 se estiver, e 0 em caso contrário
 *
 * DStack* stack: ponteiro para a pilha
 */
int dStackIsEmpty(DStack* stack){
    return (!stack->top);
}
