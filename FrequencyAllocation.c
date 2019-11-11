//
// Created by shrey on 11-11-2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "GraphColorSolution.h"

int FrequencyAllocation() {
    // declaration and null initialization of the graph structure and the adjacency matrix
    bool **graph = NULL;
//    struct Graph* GRP = NULL;

    printf("\nFrequency Allocation Problem");
    printf("\n_______________________________");

    printf("\nEnter The No. of different Tower: ");


    int towers;
    scanf("%d", &towers);
    getchar();

//    GRP = createGraph(courses, graph);

    graph = (bool **) calloc(towers, sizeof(bool *));
    for (int k = 0; k < towers; ++k) {
        graph[k] = (bool *) calloc(towers, sizeof(bool));
    }

    printf("\nInstructions: ");
    printf("\nTo share range b/w towers, \nenter two tower numbers \"i j\" space separated");
    printf("\nIf any of the i or j is greater or equal to no of towers");
    printf("\nthan input is rejected and asked for one more input");
    printf("\n\nChoose options\n1: Add Tower Connections\n0: exit\n");

    int choice2;

    do {
        printf("\nChoice: \n");
        scanf("%d", &choice2);

        if (choice2 == 1) {
            int tower1, tower2;
            printf("\n");
            scanf("%d %d", &tower1, &tower2);

            if (tower1 >= towers || tower2 >= towers) {
                printf("Invalid Input");
                continue;
            }

            // updating graph matrix
            graph[tower1][tower2] = 1;
            graph[tower2][tower1] = 1;
            printf("\nCommons Added\n");

        }
    } while (choice2 != 0);

    // generating solution

    int m = 1;
    int *solution = NULL;

    while (true) {
        solution = SolveGraph(graph, m, towers);
        if (solution != NULL) {
            break;
        }
        ++m;
    }

    printf("\nSolution:");
    printf("\n_____________________");

    for (int j = 0; j < m; ++j) {
        printf("\nFrequency %d:\t",(j+1));
        for (int i = 0; i < towers; ++i) {
            if (solution[i] == (j+1)){
                printf("Tower#%d\t",i);
            }
        }
    }


    return 0;
}