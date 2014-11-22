#include <stdio.h>
#include "graph.h"

int main()
{
    Graph* graph = GRAPH_create();
    
    GRAPH_addEdge(graph,0,1);
    GRAPH_addEdge(graph,2,3);
    GRAPH_addEdge(graph,2,1);
    GRAPH_addEdge(graph,2,0);
    GRAPH_addEdge(graph,3,2);
    GRAPH_addEdge(graph,1,2);
    
    GRAPH_printGraph(graph);
    
    printf("\n");
    GRAPH_depthFirstSearch(graph,0);
    
    printf("\n");
    GRAPH_depthFirstSearch(graph,2);
    
    graph = GRAPH_free(graph);
    
    return 0;
}
