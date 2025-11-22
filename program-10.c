/* Program to find the transpose of a matrix
   @Daya Mathew
   29-07-2025
*/

#include <stdio.h>

int main() 
{
    int a[10][10], transpose[10][10];
    int r, c, i, j;

    // Input number of rows and columns
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++) 
    {
        for (j = 0; j < c; j++) 
        {

            scanf("%d", &a[i][j]);
        }
    }

    // Finding transpose
    for (i = 0; i < r; i++) 
    {
        for (j = 0; j < c; j++) 
        {
            transpose[j][i] = a[i][j];
        }
    }

    // Display original matrix
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < r; i++) 
    {
        for (j = 0; j < c; j++) 
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Display transpose matrix
    printf("\nTransposed Matrix:\n");
    for (i = 0; i < c; i++) 
    {
        for (j = 0; j < r; j++) 
        {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}

