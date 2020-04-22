#include "cocktailsort.h"

/*
 * Sorts an array starting at @param arr of size @param SIZE using "cocktail shaker sort"
 * This is a bi-directional bubble sort, with a sweep to the right and then to the left
 * @returns 0 for error, 1 for success
 */
int cs_sort(int *arr, int SIZE) {
    if (SIZE < 1) {
        printf("ERROR: Please give a positive argument.\n");
        return 0;
    }
    for (int i = 0; i < SIZE / 2; i++) {
        // Boolean remains true if no swaps are made, indicating the list is sorted
        int isSorted = 1;
        // Sweep going right
        for (int j = i; j < SIZE - i - 1; j++) {
            // If the pair are in the wrong order, swap
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                // The list isn't sorted yet
                isSorted = 0;
            }
        }
        // Sweep going left
        for (int j = SIZE - 2 - i; j > i; j--) {
            // If the pair are in the wrong order, swap
            if (arr[j] < arr[j-1]) {
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
                // The list isn't sorted yet
                isSorted = 0;
            }
        }
        // Breaks if the list is sorted
        if (isSorted == 1) {
            break;
        }
    }
    return 1;
}

/*
 * Prints an array starting at @param arr of size @param SIZE in rows of ten, and line numbers
 * NOTE that formatting is much less attractive, but still entirely readable, if using numbers greater than three
 * digits due to the nature of tabs
 * @returns 0 for error, 1 for success
 */
int cs_print (int *arr, int SIZE) {
    if (SIZE < 1) {
        printf("ERROR: Please give a positive argument.\n");
        return 0;
    }
    for (int i = 0; i < SIZE; i++) {
        // This if statement prints a line number before each line of 10 ints
        if (i % 10 == 0) {
            printf("[%d]  \t", (i / 10) + 1);
        }
        // This if statement prints every 10 integers separated by a tab
        // Each 11th int gets printed on a new line
        if ((i + 1) % 10 != 0) {
            printf("%d\t", arr[i]);
        } else {
            printf("%d\n", arr[i]);
        }
    }
    printf("\n");
    return 1;
}

