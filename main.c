#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

/* A utility function to print solution */
void printSolution(int color[], int vertices)
{
    int i;
    printf("Solution Exists:"
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

/* A recursive utility function to solve m coloring problem */
bool graphColoringUtil(bool** graph, int m, int color[], int v, int vertices)
{
    /* base case: If all vertices are assigned a color then
       return true */
    if (v == vertices)
        return true;

    /* Consider this vertex v and try different colors */
    for (int c = 1; c <= m; c++)
    {
        /* Check if assignment of color c to v is fine*/
        if (isSafe(v, graph, color, c, vertices))
        {
            color[v] = c;

            /* recur to assign colors to rest of the vertices */
            if (graphColoringUtil (graph, m, color, v+1, vertices) == true)
                return true;

            /* If assigning color c doesn't lead to a solution
               then remove it */
            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(bool** graph, int m, int vertices)
{

    int color[vertices];
    for (int i = 0; i < vertices; i++)
        color[i] = 0;

    // Call graphColoringUtil() for vertex 0
    if (graphColoringUtil(graph, m, color, 0, vertices) == false)
    {
        return false;
    }

    // Print the solution
    printSolution(color, vertices);
    return true;
}

int main(){
    int vertices;
    printf("Graph Coloring Problem....");
    printf("Enter the number of vertices: \n");
    scanf("%d",&vertices);

    bool **graph = (bool **) calloc(vertices, sizeof(bool *));
    for (int k = 0; k < vertices; ++k) {
        graph[k] = (bool *) calloc(vertices, sizeof(bool));
    }

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }
//    bool graph[V][V] = {{0, 1, 1, 1},
//                        {1, 0, 1, 0},
//                        {1, 1, 0, 1},
//                        {1, 0, 1, 0},
//    };

//    Solution :

    int m = 1;
    bool flag;
    do{
         flag = graphColoring (graph, m, vertices);
         ++m;
    }while(!flag);

    return 0;
}