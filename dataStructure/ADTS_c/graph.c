#include "graph.h"

#define MAX_SIZE 10

typedef struct adjList AdjList;
struct adjList {
    int item;
    int visited;
    AdjList *nextAdjVertex;
};

struct graph{
    AdjList* vertices[MAX_SIZE];
};

Graph* GRAPH_create(){
    Graph* graph = malloc(sizeof(Graph));
    if(!graph)return NULL;
    
    int count;
    for(count=0;count<MAX_SIZE; count++)
        graph->vertices[count] = NULL;
    
    return graph;
}

void freeAdjLists(AdjList** vertices,int count){
    if(count<MAX_SIZE){
        if(vertices[count]!=NULL){
            AdjList* adjList = vertices[count];
            AdjList* current = NULL;
            while(adjList){
                current = adjList;
                adjList = adjList->nextAdjVertex;
                free(current);
                current = NULL;
            }
            vertices[count] = NULL;
        }
        freeAdjLists(vertices,count+1);
    }
}

Graph* GRAPH_free(Graph* graph){
    freeAdjLists(graph->vertices,0);
    free(graph);
}

void GRAPH_addEdge(Graph *graph, int vertexX, int vertexY){
    
    int found = 0;
    AdjList* current = graph->vertices[vertexX];
    
    while(current){
        if(current->item==vertexY){
            found = 1;
            break;
        }
        
        current = current->nextAdjVertex;
    }
    
    if(!found){
        AdjList* vertex = malloc(sizeof(AdjList));
    
        vertex->item = vertexY;
        vertex->visited = 0;
        vertex->nextAdjVertex = graph->vertices[vertexX];
        
        graph->vertices[vertexX] = vertex;
    }
    
}

void printAdjLists(AdjList** vertices,int count){
    if(count < MAX_SIZE){
        if(vertices[count]){
            AdjList* adjList = vertices[count];
            while(adjList){
                printf("%d - %d\n",count,adjList->item);
                adjList = adjList->nextAdjVertex;
            }
        }
        printAdjLists(vertices,count+1);
    }
}

void GRAPH_printGraph(Graph* graph){
    printAdjLists(graph->vertices,0);
}

void depthFirstSearch(Graph* graph, int vertex){
    if(graph->vertices[vertex])
        (graph->vertices[vertex])->visited = 1;
    printf("%d\n",vertex);
    AdjList* adjList = graph->vertices[vertex];
    while(adjList){
        if(!(graph->vertices[adjList->item])->visited)
            depthFirstSearch(graph, adjList->item);
        adjList = adjList->nextAdjVertex;
    }
    
}

void GRAPH_depthFirstSearch(Graph* graph, int vertex){
    
    depthFirstSearch(graph,vertex);
    
    int count;
    for(count=0;count<MAX_SIZE;count++){
        if(graph->vertices[count]){
            AdjList* adjList = graph->vertices[count];
            while(adjList){
                if(adjList->visited)
                    adjList->visited = 0;
                adjList = adjList->nextAdjVertex;
            }
        }
    }
    
}



