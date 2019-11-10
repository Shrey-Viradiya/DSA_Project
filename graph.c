//
// Created by shrey on 09-11-2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct AdjListNode{
    int dest;
    struct AdjListNode* next;
};


struct AdjList
{
    struct AdjListNode *head;
};


struct Graph
{
    int V;
    struct AdjList* array;
};


struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int V, bool** matrix)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // initialization of the graph
    matrix = (bool **) calloc(V, sizeof(bool *));
    for (int k = 0; k < V; ++k) {
        matrix[k] = (bool *) calloc(V, sizeof(bool));
    }

    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}


void addEdge(struct Graph* graph, int src, int dest, bool** matrix)
{
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;


    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;

//    matrix[src][dest] = 1;
//    *(*(matrix + src) + dest) = 1;
//    matrix[dest][src] = 1;
//    *(*(matrix + dest) + src) = 1;
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* node = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (node)
        {
            printf("-> %d", node->dest);
            node = node->next;
        }
        printf("\n");
    }
}