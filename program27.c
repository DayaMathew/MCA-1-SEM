/* Program to subtract two polynomials
   @Daya Mathew
   Date: 10-11-2025
*/

#include <stdio.h>

int main() 
{
    int a[20], b[20], diff[20];
    int d1, d2, max, i;

    // Input degree of first polynomial
    printf("Enter the degree of first polynomial: ");
    scanf("%d", &d1);
    printf("Enter coefficients:\n");
    for (i = d1; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &a[i]);
    }

    // Input degree of second polynomial
    printf("Enter the degree of second polynomial: ");
    scanf("%d", &d2);
    printf("Enter coefficients:\n");
    for (i = d2; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &b[i]);
    }

    // Determine the highest degree
    max = (d1 > d2) ? d1 : d2;

    // Fill missing coefficients with 0
    for (i = d1 + 1; i <= max; i++)
        a[i] = 0;
    for (i = d2 + 1; i <= max; i++)
        b[i] = 0;

    // Perform subtraction: (a - b)
    for (i = 0; i <= max; i++) {
        diff[i] = a[i] - b[i];
    }

    // Display the result
    printf("\nResultant polynomial after subtraction:\n");
    for (i = max; i >= 0; i--) {
        if (i != 0)
            printf("%dx^%d + ", diff[i], i);
        else
            printf("%d", diff[i]);
    }

    return 0;
}

