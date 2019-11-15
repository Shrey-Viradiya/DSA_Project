//
// Created by shrey on 15-11-2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "GraphColorSolution.h"

#define size 2
#define length size*size

void printSudoku(int* color, int vertices)
{
    printf("\nSolution:\n");

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%d\t",color[i+(4*j)]);
        }
        printf("\n");
    }
    printf("\n");
}

int sudokuProblem(){
    printf("\nThis is Sudoku Problem: %dx%d ",length,length);

    bool graph[16][16] =
            {{0,1,1,1,1,1,0,0,1,0, 1, 0, 0, 0, 0, 0}, // 0
             {1,0,1,1,1,1,0,0,0,1, 0, 0, 0, 1, 0, 0}, // 1
             {1,1,0,1,0,0,1,1,0,0, 1, 0, 0, 0, 1, 0}, // 2
             {1,1,1,0,0,0,1,1,0,0, 0, 1, 0, 0, 0, 1}, // 3
             {1,1,0,0,0,1,1,1,1,0, 0, 0, 1, 0, 0, 0}, // 4
             {1,1,0,0,1,0,1,1,0,1, 0, 0, 0, 1, 0, 0}, // 5
             {0,0,1,1,1,1,0,1,0,0, 1, 0, 0, 0, 1, 0}, // 6
             {0,0,1,1,1,1,1,0,0,0, 0, 1, 0, 0, 0, 1}, // 7
             {1,0,0,0,1,0,0,0,0,1, 1, 1, 1, 1, 0, 0}, // 8
             {0,1,0,0,0,1,0,0,1,0, 1, 1, 1, 1, 0, 0}, // 9
             {0,0,1,0,0,0,1,0,1,1, 0, 1, 0, 0, 1, 1}, // 10
             {0,0,0,1,0,0,0,1,1,1, 1, 0, 0, 0, 1, 1}, // 11
             {1,0,0,0,1,0,0,0,1,1, 0, 0, 0, 1, 1, 1}, // 12
             {0,1,0,0,0,1,0,0,1,1, 0, 0, 1, 0, 1, 1}, // 13
             {0,0,1,0,0,0,1,0,0,0, 1, 1, 1, 1, 0, 1}, // 14
             {0,0,0,1,0,0,0,1,0,0, 1, 1, 1, 1, 1, 0}}; // 15
//            0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

    int m = length;
    int *solution = NULL;

    solution = SolveGraphSudoku(graph, m, length * length);;
    if (solution != NULL) {
        printf("Error");
    }

    printSudoku(solution,length*length);

    return 0;
}