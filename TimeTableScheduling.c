//
// Created by shrey on 10-11-2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "GraphColorSolution.h"

int TimeTableScheduling(){
    // declaration and null initialization of the graph structure and the adjacency matrix
    bool** graph = NULL;
//    struct Graph* GRP = NULL;

    printf("\nTimeTable Scheduling Problem");
    printf("\n_______________________________");

    printf("\nEnter The No. of different Courses: ");



    int courses;
    scanf("%d", &courses);
    getchar();

    // getting course names

    printf("\n\nEnter the course names: \n");
    char** course_names = (char **)malloc(courses * sizeof(char *));
    for (int i = 0; i < courses; ++i) {
        course_names[i] = (char *) malloc(60 * sizeof(char));
        printf("\nCourse %d: ", i);
        gets(course_names[i]);
    }

//    GRP = createGraph(courses, graph);

    graph = (bool **) calloc(courses, sizeof(bool *));
    for (int k = 0; k < courses; ++k) {
        graph[k] = (bool *) calloc(courses, sizeof(bool));
    }

    printf("\nInstructions: ");
    printf("\nTo show common student b/w course, \nenter two course numbers \"i j\" space separated");
    printf("\nIf any of the i or j is greater or equal to no of course");
    printf("\nthan input is rejected and asked for one more input");
    printf("\n\nChoose options\n1: Add Commons\n0: exit\n");

    int choice2;

    do{
        printf("\nChoice: \n");
        scanf("%d", &choice2);

        if (choice2 == 1){
            int course1,course2;
            printf("\n");
            scanf("%d %d",&course1, &course2);

            if (course1 >= courses || course2 >= courses){
                printf("Invalid Input");
                continue;
            }

            // updating graph matrix
            graph[course1][course2] = 1;
            graph[course2][course1] = 1;
            printf("\nCommons Added\n");

        }
    }while(choice2 != 0);

    // generating solution

    int m = 1;
    int* solution = NULL;

    while(true){
        solution = SolveGraph(graph, m, courses);
        if(solution != NULL){
            break;
        }
        ++m;
    }

    printf("\nTime Table:");
    printf("\n_____________________");

    for (int j = 0; j < m; ++j) {
        printf("\nSlot %d:\t",(j+1));
        for (int i = 0; i < courses; ++i) {
            if (solution[i] == (j+1)){
                printf("%s\t",course_names[i]);
            }
        }
    }


    return 0;
}