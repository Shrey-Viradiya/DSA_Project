//
// Created by shrey on 09-11-2019.
//

#ifndef DSA_PROJECT_GRAPHCOLORSOLUTION_H
#define DSA_PROJECT_GRAPHCOLORSOLUTION_H

#include<stdio.h>
#include<stdbool.h>

void printSolution(int color[], int vertices);
bool isSafe (int v, bool** graph, const int color[], int c, int vertices);
bool GraphColoringREC(bool** graph, int m, int color[], int v, int vertices);
int* SolveGraph(bool** graph, int m, int vertices);

#endif //DSA_PROJECT_GRAPHCOLORSOLUTION_H
