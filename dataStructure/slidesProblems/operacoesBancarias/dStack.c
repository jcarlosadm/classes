#include "dStack.h"

/**
 * Estrutura do nó da pilha
 */
typedef struct node Node;

struct node{
    int (*item)(DStack*,Cliente*);
    Node* nextNode;
};

/**
 * Estrutura da pilha
 */
struct dStack{
    Node* top;
};

struct cliente{
    char senha[10];
    
    float total;
    
    float tempSaque;
    float tempDeposito;
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

Cliente *createCliente(float value,char* senha){
    
    Cliente* cliente = malloc(sizeof(Cliente));
    
    strcpy(cliente->senha,senha);
    
    cliente->total = value;
    cliente->tempSaque = 0;
    cliente->tempDeposito = 0;
    return cliente;
}


float getTotal(Cliente * cliente){
    return cliente->total;
}
void setTotal(Cliente * cliente,float value){
    cliente->total = value;
}
float getTempSaque(Cliente * cliente){
    return cliente->tempSaque;
}
void setTempSaque(Cliente * cliente,float value){
    cliente->tempSaque = value;
}
float getTempDeposito(Cliente * cliente){
    return cliente->tempDeposito;
}
void setTempDeposito(Cliente * cliente,float value){
    cliente->tempDeposito = value;
}
int checkSenha(Cliente* cliente,char *senha){
    if(strcmp(cliente->senha,senha)==0)
        return 1;
    else
        return 0;
}

Cliente* freeCliente(Cliente* cliente){
    free(cliente);
    return NULL;
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
void dStackPush(DStack* stack, int (*item)(DStack*,Cliente*)){
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
void dStackPop(DStack* stack){
    if(!dStackIsEmpty(stack)){
        Node* oldTop = stack->top;
        stack->top = stack->top->nextNode;
        free(oldTop);
        //printf("elemento desempilhado!\n");
    }else{
        printf("stack is empty\n");
    }
}

/**
 * Retorna valor do topo da pilha (sem remover)
 *
 * DStack* stack: ponteiro para a pilha
 */
int dStackExecuteTopElement(DStack* stack,Cliente* cliente){
    if(!dStackIsEmpty(stack)){
        //printf("elemento irá ser executado!\n");
        return (*stack->top->item)(stack,cliente);
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
