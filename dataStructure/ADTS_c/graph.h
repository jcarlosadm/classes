#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct graph Graph;

Graph* GRAPH_create();

Graph* GRAPH_free(Graph* graph);

void GRAPH_addEdge(Graph *graph, int vertexX, int vertexY);

void GRAPH_printGraph(Graph* graph);

void GRAPH_depthFirstSearch(Graph* graph, int vertex);

#endif // GRAPH_H
