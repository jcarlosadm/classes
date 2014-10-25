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
    return NULL;
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

/**
int GRAPH_dijkstra(Graph* graph, int init, int end){
    int costs[MAX_SIZE];
    int visited[MAX_SIZE];
    int path[MAX_SIZE];
    int exclude[MAX_SIZE];
    int min; // vetor com a menor distância
    int currentV = init;
    int totalV = 0;
    
    AdjList* adjList = NULL;
    
    int count;
    for(count=0; count<MAX_SIZE; count++){
        if(graph->vertices[count])
            totalV+=1;
        
        costs[count] = INT_MAX;
        visited[count] = 0;
        path[count] = -1;
        exclude[count] = 0;
    }
    
    costs[init] = 0;
    min = init;
    
    while(totalV > 0){
        currentV = min;
        totalV -= 1;
        visited[currentV] = 1;
        printf("%d\n",currentV);
        adjList = graph->vertices[currentV];
        while(adjList){
            
            if(exclude[adjList->item]){
                adjList = adjList->nextAdjVertex;
                continue;
            }
            
            if(costs[adjList->item] >= (costs[currentV] + adjList->weight)){
                costs[adjList->item] = costs[currentV] + adjList->weight;
                path[adjList->item] = currentV;
                visited[adjList->item] = 0;
            }
            
            if(!visited[adjList->item]){
            
                printf("  %d\n",adjList->item);
                
                if(min == currentV)
                    min = adjList->item;
                else{
                    if(costs[adjList->item] <= costs[min] )
                        min = adjList->item;
                }
            }
            
            adjList = adjList->nextAdjVertex;
        }
        
        if(min == currentV && min != end){
            printf("endline: %d\n",min);
            min = path[currentV];
            exclude[currentV] = 1;
        }
        
    }
    
    count = end;
    printf("end to begin: ");
    while(path[count]!=-1){
        printf("%d ", count);
        count = path[count];
    }
    printf("%d\n",count);
    printf("cost: %d\n",costs[end]);
    
    return costs[end];
    
}*/

/**
 * Extrai o vetor não visitado com o menor custo
 * retorna o valor do vetor com o menor custo
 * o vetor com o menor custo é configurado como visitado
 */
int extractMin(int *costs, int *visited){
    int count;
    int min=0;
    while(visited[min] && min<MAX_SIZE){
        min++;
    }
    for(count=min; count<MAX_SIZE; count++){
        if(!visited[count] && costs[count] <= costs[min]){
            min = count;
        }
    }
    visited[min] = 1;
    return min;
}

/**
 * Retorna o custo do menor caminho do vetor init
 * até o vetor end
 */
int GRAPH_dijkstra(Graph* graph, int init, int end){
    int costs[MAX_SIZE];
    int visited[MAX_SIZE];
    int path[MAX_SIZE];
    int min = init;
    
    AdjList* adjList = NULL;
    
    int count;
    
    /* initialize */
    for(count=0; count<MAX_SIZE; count++){
        costs[count] = INT_MAX;
        visited[count] = 0;
        path[count] = -1;
    }
    
    costs[init] = 0;
    
    while(min < MAX_SIZE){
        min = extractMin(costs,visited);
        adjList = graph->vertices[min];
        while(adjList){
            
            /* relax */
            if(costs[adjList->item] > costs[min] + adjList->weight){
                costs[adjList->item] = costs[min] + adjList->weight;
                path[adjList->item] = min;
            }
            
            adjList = adjList->nextAdjVertex;
        }
    }
    
    /* print path */
    
    DStack* stack = dStackCreateStack();
    dStackPush(stack,end);
    count = end;
    while(path[count]!=init){
        dStackPush(stack,path[count]);
        count = path[count];
    }
    dStackPush(stack,init);
    printf("path: ");
    while(!dStackIsEmpty(stack)){
        printf("%d ",dStackPop(stack));
    }
    printf("\n");
    
    stack = dStackFree(stack);
    
    /*printf("path: %d ",end);
    count = end;
    while(path[count]!=init){
        printf("%d ",path[count]);
        count = path[count];
    }
    printf("%d\n", init);*/
    
    /* print cost */
    printf("cost: %d\n", costs[end]);
    
    /* return cost */
    return costs[end];
    
}

