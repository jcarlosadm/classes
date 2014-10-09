#include "deque.h"

typedef struct node Node;

struct node{
    int item;
    Node* nextNode;
    Node* previousNode;
};

struct deque{
    Node* first;
    Node* end;
};

Deque* DEQUE_createQueue(){
    Deque* deque = malloc(sizeof(Deque));
    if(!deque) return NULL;
    
    deque->first = NULL;
    deque->end = NULL;
    
    return deque;
}

Node* freeNodes(Node* node){
    if(!node)
        return NULL;
    else{
        Node* current = node;
        node = node->nextNode;
        free(current);
        return freeNodes(node);
    }
}

Deque* DEQUE_free(Deque* deque){
    deque->first = freeNodes(deque->first);
    deque->end = NULL;
    free(deque);
    return NULL;
}

int DEQUE_pushFront(Deque* deque, int item){
    
    Node* newNode = malloc(sizeof(Node));
    if(!newNode)return 0;

    newNode->item=item;
    newNode->previousNode = NULL;
    newNode->nextNode = deque->first;
    
    if(deque->first==NULL){
        deque->first = newNode;
        deque->end = newNode;
    }
    else{
        deque->first->previousNode = newNode;
        deque->first = newNode;
    }
    
    return 1;
}

int DEQUE_pushBack(Deque* deque, int item){
    Node* newNode = malloc(sizeof(Node));
    if(!newNode)return 0;

    newNode->item=item;
    newNode->nextNode = NULL;
    newNode->previousNode = deque->end;
    
    if(deque->end==NULL){
        deque->first = newNode;
        deque->end = newNode;
    }
    else{
        deque->end->nextNode = newNode;
        deque->end = newNode;
    }
    
    return 1;
}

int DEQUE_popFront(Deque* deque){
    
    if(!deque->first){
        printf("queue is empty\n");
        return -1;
    }
    else{
        int value = deque->first->item;
        if(deque->first->nextNode!=NULL){
            deque->first = deque->first->nextNode;
            free(deque->first->previousNode);
            deque->first->previousNode = NULL;
        }
        else{
            free(deque->first);
            deque->first = NULL;
            deque->end = NULL;
        }
        return value;
    }
}

int DEQUE_popBack(Deque* deque){
    
    if(!deque->end){
        printf("queue is empty\n");
        return -1;
    }
    else{
        int value = deque->end->item;
        if(deque->end->previousNode!=NULL){
            deque->end = deque->end->previousNode;
            free(deque->end->nextNode);
            deque->end->nextNode = NULL;
        }
        else{
            free(deque->end);
            deque->first = NULL;
            deque->end = NULL;
        }
        return value;
    }
    
}

void printNode(Node* node){
    if(node){
        printf(" %d",node->item);
        printNode(node->nextNode);
    }
}

void DEQUE_printDeque(Deque* deque){
    printNode(deque->first);
    printf("\n");
}

int DEQUE_isEmpty(Deque* deque){
    return (deque->first == NULL);
}


