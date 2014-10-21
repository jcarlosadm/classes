#include <stdio.h>
#include "graph.h"

int main()
{
    Graph* graph = GRAPH_create();
    
    /*
    //do slide
    GRAPH_addEdge(graph,1,6,14);
    GRAPH_addEdge(graph,1,3,9);
    GRAPH_addEdge(graph,1,2,7);
    GRAPH_addEdge(graph,2,1,7);
    GRAPH_addEdge(graph,2,3,10);
    GRAPH_addEdge(graph,2,4,15);
    GRAPH_addEdge(graph,3,1,9);
    GRAPH_addEdge(graph,3,2,10);
    GRAPH_addEdge(graph,3,4,11);
    GRAPH_addEdge(graph,3,6,2);
    GRAPH_addEdge(graph,4,2,15);
    GRAPH_addEdge(graph,4,3,11);
    GRAPH_addEdge(graph,4,5,6);
    GRAPH_addEdge(graph,6,1,14);
    GRAPH_addEdge(graph,6,3,2);
    GRAPH_addEdge(graph,6,5,9);
    GRAPH_addEdge(graph,5,6,9);
    GRAPH_addEdge(graph,5,4,6);
    
    printf("%d\n",GRAPH_dijkstra(graph,5,2));*/
    
    GRAPH_addEdge(graph,1,2,1);
    GRAPH_addEdge(graph,1,3,2);
    GRAPH_addEdge(graph,2,1,1);
    GRAPH_addEdge(graph,2,4,2);
    GRAPH_addEdge(graph,2,5,5);
    GRAPH_addEdge(graph,2,6,4);
    GRAPH_addEdge(graph,3,1,2);
    GRAPH_addEdge(graph,4,2,2);
    GRAPH_addEdge(graph,4,8,3);
    GRAPH_addEdge(graph,5,2,5);
    GRAPH_addEdge(graph,6,2,4);
    GRAPH_addEdge(graph,6,7,3);
    GRAPH_addEdge(graph,6,8,2);
    GRAPH_addEdge(graph,7,6,3);
    GRAPH_addEdge(graph,8,4,3);
    GRAPH_addEdge(graph,8,6,2);
    
    printf("%d\n",GRAPH_dijkstra(graph,7,3));
    
    graph = GRAPH_free(graph);
    
    return 0;
}
