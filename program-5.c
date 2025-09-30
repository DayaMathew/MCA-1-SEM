/* Program to sort array elements in ascending order (minimum 3 functions)
   Daya Mathew
   27 July 2025 */

#include <stdio.h>

int a[100], i, n, temp, j;

void read() {
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void display() {
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);  // Added space for clarity
    }
    printf("\n");
}

void sort() {
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    read();

    printf("Original array:\n");
    display();

    sort();

    printf("Sorted array:\n");
    display();

    return 0;
}

