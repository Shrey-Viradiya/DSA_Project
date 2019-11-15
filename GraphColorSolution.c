//
// Created by shrey on 09-11-2019.
//

#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int solutionSudoku = 0;

void printSudoku(int *color) {
    printf("\nSolution: %d\n", ++solutionSudoku);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d ", color[i + (4 * j)]);
        }
        printf("| ");
        for (int j = 2; j < 4; ++j) {
            printf("%d ", color[i + (4 * j)]);
        }
        printf("\n");
    }
    printf("----------\n");
    for (int i = 2; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d ", color[i + (4 * j)]);
        }
        printf(" | ");
        for (int j = 2; j < 4; ++j) {
            printf("%d ", color[i + (4 * j)]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

void printSolution(int* color, int vertices)
{
    int i;
    printf("\nSolution Exists:"
           " Following are the assigned colors \n");
    for (i = 0; i < vertices; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

bool isSafe (int v, bool** graph, const int* color, int c, int vertices)
{
    for (int i = 0; i < vertices; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool isSafeSudoku (int v, bool graph[16][16], const int* color, int c, int vertices)
{
    for (int i = 0; i < vertices; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool GraphColoringREC(bool** graph, int m, int* color, int v, int vertices)
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

bool GraphColoringSudoku(bool graph[16][16], int m, int* color, int v, int vertices)
{
    if (v == vertices) {
        printSudoku(color);
        return true;
    }


    for (int c = 1; c <= m; c++)
    {
        if (isSafeSudoku(v, graph, color, c, vertices))
        {
            color[v] = c;
            GraphColoringSudoku(graph, m, color, v + 1, vertices);
            color[v] = 0;
        }
    }

    return false;
}

int* SolveGraph(bool** graph, int m, int vertices)
{
    int* color = calloc(vertices, sizeof(int));

    if (GraphColoringREC(graph, m, color, 0, vertices) == false)
    {
        return NULL;
    }

    return color;
}

int* SolveGraphSudoku(bool graph[16][16], int m, int vertices){
    int* color = calloc(vertices, sizeof(int));
//    for (int i = 0; i < vertices; i++)
//        color[i] = 0;

    if (GraphColoringSudoku(graph, m, color, 0, vertices) == false)
    {
        return NULL;
    }

    return color;
}