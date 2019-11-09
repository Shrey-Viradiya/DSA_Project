//
// Created by shrey on 09-11-2019.
//

#include<stdio.h>
#include<stdbool.h>

void printSolution(int color[], int vertices)
{
    int i;
    printf("\nSolution Exists:"
           " Following are the assigned colors \n");
    for (i = 0; i < vertices; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

bool isSafe (int v, bool** graph, const int color[], int c, int vertices)
{
    for (int i = 0; i < vertices; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool GraphColoringREC(bool** graph, int m, int color[], int v, int vertices)
{
    if (v == vertices)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c, vertices))
        {
            color[v] = c;

            if (GraphColoringREC (graph, m, color, v+1, vertices) == true)
                return true;

            color[v] = 0;
        }
    }

    return false;
}

bool SolveGraph(bool** graph, int m, int vertices)
{
    int color[vertices];
    for (int i = 0; i < vertices; i++)
        color[i] = 0;

    if (GraphColoringREC(graph, m, color, 0, vertices) == false)
    {
        return false;
    }

    printf("Minimum Number of Different colors \nrequired to Color the graph: %d",m);
    printSolution(color, vertices);
    return true;
}