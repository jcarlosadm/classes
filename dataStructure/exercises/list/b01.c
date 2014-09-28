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
    int sentinel;
};

Node* createCircularList(){
    return NULL;
}

Node* insertCircularNode(Node* first, int item){
    
    Node* newNode = NULL;
    newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return first;
    
    newNode->item = item;
    newNode->sentinel = 1;
    
    if(first==NULL){
        newNode->nextNode = newNode;
        newNode->previousNode = newNode;
        return newNode;
    }
    
    newNode->nextNode = first;
    newNode->previousNode = first->previousNode;
    first->previousNode = newNode;
    newNode->previousNode->nextNode = newNode;
    return newNode;
    
}

Node* freeCircularList(Node* current, Node *first){
    if(current==NULL)
        return NULL;
    if(current==first){
        if(current->sentinel==1){
            current->sentinel=0;
            current->nextNode = freeCircularList(current->nextNode,first);
            free(current);
            return NULL;
        }
        else{
            current->sentinel = 1;
            return current;
        }
    }
    else{
        current->nextNode = freeCircularList(current->nextNode,first);
        free(current);
        current = NULL;
        return current;
    }
}

void printCircular(Node* current, Node* first){
    if(current==NULL)
        return;
    if(current==first){
        if(current->sentinel == 1){
            current->sentinel = 0;
            printf(" %d",current->item);
            printCircular(current->nextNode,first);
        }
        else{
            printf("\n");
            current->sentinel=1;
        }
    }
    else{
        printf(" %d",current->item);
        printCircular(current->nextNode,first);
    }
}


int main()
{
    
    Node* node = createCircularList();
    
    node = insertCircularNode(node,2);
    node = insertCircularNode(node,6);
    node = insertCircularNode(node,1);
    
    printCircular(node,node);
    
    node = freeCircularList(node,node);
    
    return 0;
}


