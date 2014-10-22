#include "graph.h"

#define MAX_SIZE 10

typedef struct adjList AdjList;
struct adjList {
    int item;
    int weight;
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

void GRAPH_addEdge(Graph *graph, int vertexX, int vertexY, int weight){
    
    int found = 0;
    AdjList* current = graph->vertices[vertexX];
    
    while(current){
        if(current->item==vertexY){
            found = 1;
            break;
        }
        
        current = current->nextAdjVertex;
    }
    if(found)
        current->weight = weight;
    else{
        AdjList* vertex = malloc(sizeof(AdjList));
    
        vertex->item = vertexY;
        vertex->weight = weight;
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

void depthFirstSearch(Graph* graph, int *visited, int vertex){
    if(graph->vertices[vertex])
        visited[vertex] = 1;
    printf("%d\n",vertex);
    AdjList* adjList = graph->vertices[vertex];
    while(adjList){
        if(!visited[adjList->item])
            depthFirstSearch(graph, visited,adjList->item);
        adjList = adjList->nextAdjVertex;
    }
    
}

void GRAPH_depthFirstSearch(Graph* graph, int vertex){
    
    int visited[MAX_SIZE];
    int count;
    for(count=0;count<MAX_SIZE;count++){
        visited[count] = 0;
    }
    
    depthFirstSearch(graph,visited,vertex);
    
}

// deverá guardar o menor caminho dos adjacentes de um n
// deverá guardar os predecessores de cada posição (ver por último)
// deve retornar 0 se entrou num beco sem saída (ver por último)
void setCosts(AdjList** vertices, int* costs, int* visited, int n, int end){
    if(vertices[n]){
        visited[n] = 1;
        AdjList* adjList = vertices[n];
        while(adjList){
            if(costs[adjList->item] > (costs[n] + adjList->weight) ){
                
                printf("%d %d %d\n",n,adjList->item,costs[n] + adjList->weight);
                costs[adjList->item] = (costs[n] + adjList->weight);
                visited[adjList->item] = 0;
            }
            
            if(!visited[adjList->item] && adjList->item != end)
                setCosts(vertices,costs,visited,adjList->item,end);
                
            adjList = adjList->nextAdjVertex;
        }
        
    }
}

int GRAPH_dijkstra(Graph* graph, int init, int end){
    int costs[MAX_SIZE];
    int visited[MAX_SIZE];
    int i;
    
    for(i=0;i<MAX_SIZE;i++){
        costs[i] = INT_MAX;
        visited[i] = 0;
    }
    
    costs[init] = 0;
    
    setCosts(graph->vertices,costs,visited,init,end);
    return costs[end];
}





