/* Program to add two polynomials
   @Daya Mathew
   01-08-2025 */

#include <stdio.h>

int main()
{
    int d1, d2, dmax, i;

    // First polynomial
    printf("Enter degree of first polynomial: ");
    scanf("%d", &d1);
    int p1[d1+1];
    for(i = d1; i >= 0; i--)
    {
        printf("Coeff of x^%d: ", i);
        scanf("%d", &p1[i]);
    }

    // Second polynomial
    printf("\nEnter degree of second polynomial: ");
    scanf("%d", &d2);
    int p2[d2+1];
    for(i = d2; i >= 0; i--)
    {
        printf("Coeff of x^%d: ", i);
        scanf("%d", &p2[i]);
    }

    // Max degree
    dmax = (d1 > d2) ? d1 : d2;
    int res[dmax+1];

    // Init result
    for(i = 0; i <= dmax; i++) res[i] = 0;

    // Add polynomials
    for(i = 0; i <= d1; i++) res[i] += p1[i];
    for(i = 0; i <= d2; i++) res[i] += p2[i];

    // Display result
    printf("\nResult: ");
    for(i = dmax; i >= 0; i--)
    {
        if(res[i] == 0) continue;

        if(i != dmax && res[i] > 0) printf("+");
        if(res[i] < 0) printf("-");

        if(i == 0 || res[i] < -1 || res[i] > 1)
            printf("%d", res[i] < 0 ? -res[i] : res[i]);

        if(i > 0)
        {
            printf("x");
            if(i > 1) printf("^%d", i);
        }
    }
    printf("\n");

    return 0;
}

