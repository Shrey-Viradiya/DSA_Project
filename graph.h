//
// Created by shrey on 09-11-2019.
//

#ifndef DSA_PROJECT_GRAPH_H
#define DSA_PROJECT_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct AdjListNode;
struct AdjList;
struct Graph;

struct AdjListNode* newAdjListNode(int dest);
struct Graph* createGraph(int V, bool** matrix);
void addEdge(struct Graph* graph, int src, int dest, bool** matrix);
void printGraph(struct Graph* graph);


#endif //DSA_PROJECT_GRAPH_H
