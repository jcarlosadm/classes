#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dStack.h"

typedef struct graph Graph;

Graph* GRAPH_create();

Graph* GRAPH_free(Graph* graph);

void GRAPH_addEdge(Graph *graph, int vertexX, int vertexY, int weight);

void GRAPH_printGraph(Graph* graph);

void GRAPH_depthFirstSearch(Graph* graph, int vertex);

int GRAPH_dijkstra(Graph* graph, int init, int end);

#endif // GRAPH_H
