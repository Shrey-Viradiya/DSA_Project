#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "graph.c"
#include "GraphColorSolution.c"

int main(){
    int vertices, choice;
    bool **graph = NULL;
    struct Graph* GRP = NULL;
    printf("Graph Coloring Problem....");
    printf("Enter the number of vertices: \n");
    scanf("%d",&vertices);

    printf("Choose the approach\n1: add adjacency matrix of the graph\n2: add the edges of the graph\n");
    scanf("%d", &choice);

    switch (choice){
        case 1:
            graph = (bool **) calloc(vertices, sizeof(bool *));
            for (int k = 0; k < vertices; ++k) {
                graph[k] = (bool *) calloc(vertices, sizeof(bool));
            }

            printf("\n\nEnter the adjacency matrix of the graph\n");
            printf("________________________________________\n");

            for (int i = 0; i < vertices; ++i) {
                for (int j = 0; j < vertices; ++j) {
                    scanf("%d", &graph[i][j]);
                }
            }
            break;

        case 2:;
            GRP = createGraph(vertices, graph);

            printf("n Vertices are labeled as 0, 1, to n-1: ");
            printf("Instructions: ");
            printf("To add an edge, enter two vertices \"i j\" space separated");
            printf("If any of the i or j is greater of equal to no of vertices");
            printf("than input is rejected and asked for one more input");
            printf("Choose options\n1: add edge\n2:exit\n");

            int choice2;

            do{
                printf("\nChoice: \n");
                scanf("%d", &choice2);

                if (choice2 == 1){
                    int src,des;
                    printf("\n");
                    scanf("%d %d",&src, &des);

                    if (src >= vertices || des >= vertices){
                        printf("Invalid Input");
                        continue;
                    }
                    printf("Edge Added");
                    addEdge(GRP,src,des,graph);
                }
            }while(choice2 != 2);
            break;

    }


//    bool graph[V][V] = {{0, 1, 1, 1},
//                        {1, 0, 1, 0},
//                        {1, 1, 0, 1},
//                        {1, 0, 1, 0},
//    };

//    Solution : 1 2 3 2

    int m = 1;
    bool flag;
    do{
         flag = SolveGraph (graph, m, vertices);
         ++m;
    }while(!flag);

    return 0;
}