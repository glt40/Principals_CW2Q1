#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cocktailsort.h"

// Initialise variables
int SIZE = 100;
int MAX = 999;

/*
 * Generates an array of @param GENSIZE pseudo-random integers into memory
 * @returns the pointer to the start of the array
 */
int * arr_gen(int GENSIZE, int GENMAX) {
    if (GENSIZE < 1 || GENMAX < 1) {
        printf("ERROR: Please give positive arguments.\n");
        return 0;
    }
    printf("Generating %d random integers...\n" , GENSIZE);
    int *ARR_POINT = malloc(GENSIZE * sizeof(int));
    // rand() is used for pseudo random numbers, since they don't have to be cryptographically secure
    srand(time(NULL));
    for (int i=0; i < GENSIZE; i++) {
        int current = (rand() % GENMAX) + 1;
        ARR_POINT[i] = current;
    }
    return ARR_POINT;
}

/*
 * Main function, calls function from main.c and cocktailsort.c
 */
int main() {
    // Generates array of int
    // SIZE 100 specified in question, MAX 999 chosen arbitrarily
    int *ARR_POINT = arr_gen(SIZE, MAX);
    cs_print(ARR_POINT, SIZE);
    cs_sort(ARR_POINT, SIZE);
    cs_print(ARR_POINT, SIZE);
    return 0;
}
