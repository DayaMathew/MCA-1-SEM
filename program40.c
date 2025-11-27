#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;
    float mean = 0;

    printf("Enter number of integers: ");
    scanf("%d", &n);

    // Allocate memory dynamically using malloc
    arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read n integers from user
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    // Calculate sum
    int sum = 0;
    for(i = 0; i < n; i++)
        sum =sum+ arr[i];

    // Calculate mean
    mean = (float)sum / n;

    printf("\nMean of the entered numbers: %.2f\n", mean);

    // Free allocated memory
    free(arr);

    return 0;
}

