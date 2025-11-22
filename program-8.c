/* program to perform the addition of two matrices and subtraction of one matrix from another
   @Daya Mathew
   28-07-2025 */

#include <stdio.h>

int main() 
{
    int a[10][10], b[10][10], sum[10][10], diff[10][10];
    int i, j;
    int r1, c1, r2, c2;   // using r1, c1, r2, c2 as requested

    // Input dimensions of both matrices
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if addition and subtraction are possible
    if (r1 != r2 || c1 != c2) 
    {
        printf("Addition or subtraction not possible. Matrices must be of same size.\n");
        return 0;
    }

    // Input elements of first matrix
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++) 
    {
        for (j = 0; j < c1; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Input elements of second matrix
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++) 
    {
        for (j = 0; j < c2; j++) 
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Perform addition and subtraction
    for (i = 0; i < r1; i++) 
    {
        for (j = 0; j < c1; j++) 
        {
            sum[i][j] = a[i][j] + b[i][j];
            diff[i][j] = a[i][j] - b[i][j];
        }
    }

    // Display sum of matrices
    printf("Addition of two matrices:\n");
    for (i = 0; i < r1; i++) 
    {
        for (j = 0; j < c1; j++) 
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    // Display difference of matrices
    printf("Subtraction of second matrix from first:\n");
    for (i = 0; i < r1; i++) 
    {
        for (j = 0; j < c1; j++) 
        {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    return 0;
}

