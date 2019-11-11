#include<stdio.h>
#include "GraphColorImplementation.h"
#include "TimeTableScheduling.h"
#include "FrequencyAllocation.h"

int main(){
    printf("\nDSA_Project");
    printf("\n______________________");
    printf("\nGraph Coloring and application");
    printf("\n______________________");
    printf("\nProject By Shrey Viradiya and Tirth Patel");
    printf("\n______________________");

    printf("\n\n");

    printf("\n______________________");
    printf("\nChoose From Options:");
    printf("\n______________________");
    printf("\n1: Simple Graph Coloring Implementation");
    printf("\n2: Exam Time-Table Scheduling");
    printf("\n3: Mobile Radio Frequency Allocation");
    printf("\n______________________");
    printf("\nEnter Your Choice:\n");

    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1:
            GraphColorImplementation();
            break;
        case 2:
            TimeTableScheduling();
            break;
        case 3:
            FrequencyAllocation();
            break;
        default:
            printf("Not Sure What to do! Please try again...");
            break;

    }

    return 0;
}