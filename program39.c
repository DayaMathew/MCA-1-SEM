#include <stdio.h>
#include <stdlib.h> // Required for malloc, calloc, free

int main() {
    int n, i;
    int *arr1, *arr2;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // a) malloc — allocates memory without initializing
    arr1 = (int *)malloc(n * sizeof(int));
    if(arr1 == NULL) {
        printf("Memory allocation failed using malloc.\n");
        return 1;
    }

    printf("\nUsing malloc (uninitialized memory):\n");
    for(i = 0; i < n; i++)
        printf("arr1[%d] = %d\n", i, arr1[i]);  // may contain garbage values

    // Initialize malloc memory manually
    for(i = 0; i < n; i++)
        arr1[i] = i + 1;

    printf("\nAfter initializing malloc memory:\n");
    for(i = 0; i < n; i++)
        printf("arr1[%d] = %d\n", i, arr1[i]);

    // b) calloc — allocates memory and initializes to 0
    arr2 = (int *)calloc(n, sizeof(int));
    if(arr2 == NULL) {
        printf("Memory allocation failed using calloc.\n");
        free(arr1); // free previously allocated memory
        return 1;
    }

    printf("\nUsing calloc (initialized to 0):\n");
    for(i = 0; i < n; i++)
        printf("arr2[%d] = %d\n", i, arr2[i]);

    // Initialize calloc memory
    for(i = 0; i < n; i++)
        arr2[i] = (i + 1) * 2;

    printf("\nAfter initializing calloc memory:\n");
    for(i = 0; i < n; i++)
        printf("arr2[%d] = %d\n", i, arr2[i]);

    // c) free — deallocates memory
    free(arr1);
    free(arr2);

    printf("\nMemory freed successfully.\n");

    return 0;
}

