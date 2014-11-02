#include "dStack_BinaryTree.h"

/**
 * Estrutura do nó da pilha
 */
typedef struct node Node;

struct node{
    BinaryTree* item;
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

Node* dStackFreeNodes_bt(Node* topNode){
    if(topNode){
        Node* prev = topNode;
        topNode = topNode->nextNode;
        free(prev);
        return dStackFreeNodes_bt(topNode);
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
DStack *dStackCreateStack_bt(){
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
DStack *dStackFree_bt(DStack* stack){
    if(stack){
        stack->top = dStackFreeNodes_bt(stack->top);
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
void dStackPush_bt(DStack* stack, BinaryTree* item){
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
BinaryTree* dStackPop_bt(DStack* stack){
    if(!dStackIsEmpty(stack)){
        BinaryTree* value = stack->top->item;
        Node* oldTop = stack->top;
        stack->top = stack->top->nextNode;
        free(oldTop);
        return value;
    }else{
        printf("stack is empty\n");
        return NULL;
    }
}

/**
 * Retorna valor do topo da pilha (sem remover)
 *
 * DStack* stack: ponteiro para a pilha
 */
BinaryTree* dStackPeek_bt(DStack* stack){
    if(!dStackIsEmpty(stack)){
        return stack->top->item;
    }else{
        printf("stack is empty!");
        return NULL;
    }
}

/**
 * Verifica se a pilha está vazia
 * retorna 1 se estiver, e 0 em caso contrário
 *
 * DStack* stack: ponteiro para a pilha
 */
int dStackIsEmpty_bt(DStack* stack){
    return (!stack->top);
}
