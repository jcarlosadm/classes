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
    
    /* print cost */
    printf("cost: %d\n", costs[end]);
    
    /* return cost */
    return costs[end];
    
}
