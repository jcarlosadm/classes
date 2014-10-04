/**
Este arquivo possui uma função main
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node{
    int item;
    Node* previousNode;
    Node* nextNode;
};

Node* createCircularList(){

    // aloca sentinela
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return NULL;
    
    newNode->nextNode = newNode;
    newNode->previousNode = newNode;
    
    return newNode;
}

int insertCircularNode(Node* sentinel, int item){
    
    if(sentinel==NULL) return 0;
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return 0;
    
    newNode->item = item;
    newNode->nextNode = sentinel->nextNode;
    newNode->previousNode = sentinel;
    
    sentinel->nextNode->previousNode = newNode;
    sentinel->nextNode = newNode;
    
    return 1;
    
}

Node* freeListRec(Node* current, Node* sentinel){
    if(current != sentinel){
        if(current->nextNode!= sentinel){
            current = current->nextNode;
            free(current->previousNode);
            return freeListRec(current,sentinel);
        }else{
            free(current);
            return NULL;
        }
    }else{
        return NULL;
    }
}

Node* freeCircularList(Node *sentinel){

    if(sentinel==NULL) return NULL;
    
    if(sentinel->nextNode != sentinel){
        freeListRec(sentinel->nextNode,sentinel);
    }
    
    free(sentinel);
    return NULL;
}

void printCircularList(Node* current, Node* sentinel){
    if(current == sentinel)
        printf("\n");
    else{
        printf(" %d", current->item);
        printCircularList(current->nextNode,sentinel);
    }
}

void printCircular(Node* sentinel){
    if(sentinel == NULL) return;
    
    if(sentinel->nextNode != sentinel)
        printCircularList(sentinel->nextNode,sentinel);
        
}


int main()
{
    
    Node* node = createCircularList();
    
    if(node){
        insertCircularNode(node,2);
        insertCircularNode(node,6);
        insertCircularNode(node,1);
        
        printCircular(node);
        
        node = freeCircularList(node);
    }
    
    return 0;
}


