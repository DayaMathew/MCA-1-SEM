#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    int *arr;
    int mode = 0, maxCount = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Allocate memory using calloc (initialized to 0)
    arr = (int *)calloc(n, sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read n numbers from user
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    // Find the mode
    for(i = 0; i < n; i++) {
        int count = 0;
        for(j = 0; j < n; j++) {
            if(arr[j] == arr[i])
                count++;
        }
        if(count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }

    if(maxCount > 1)
        printf("\nMode of the array is: %d (occurs %d times)\n", mode, maxCount);
    else
        printf("\nNo mode found (all elements occur only once).\n");

    // Free allocated memory
    free(arr);

    return 0;
}

