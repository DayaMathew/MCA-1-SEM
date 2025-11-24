/* Program to multiply two polynomials
   @Daya Mathew
   Date: 10-11-2025
*/

#include <stdio.h>

int main() 
{
    int a[10], b[10], mul[20];  // arrays for coefficients
    int d1, d2, i, j;

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

    // Initialize result array to 0
    for (i = 0; i <= d1 + d2; i++)
        mul[i] = 0;

    // Multiply the two polynomials
    for (i = 0; i <= d1; i++) {
        for (j = 0; j <= d2; j++) {
            mul[i + j] += a[i] * b[j];
        }
    }

    // Display the result
    printf("\nResultant polynomial after multiplication:\n");
    for (i = d1 + d2; i >= 0; i--) {
        if (i != 0)
            printf("%dx^%d + ", mul[i], i);
        else
            printf("%d", mul[i]);
    }

    return 0;
}

