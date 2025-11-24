/* Program to read and display a polynomial
   @Daya Mathew
   08-09-2025 */

#include <stdio.h>

int main()
{
    int d, i;
    printf("Enter degree of polynomial: ");
    scanf("%d", &d);

    int coef[d+1];

    // Read coefficients
    for(i = d; i >= 0; i--)
    {
        printf("Coeff of x^%d: ", i);
        scanf("%d", &coef[i]);
    }

    printf("Polynomial: ");
    // Display polynomial
    for(i = d; i >= 0; i--)
    {
        int c = coef[i];
        if(c == 0) continue;   // skip zero terms

        if(i != d && c > 0) printf("+");
        if(c < 0) printf("-");

        if(i == 0 || c < -1 || c > 1)
            printf("%d", c < 0 ? -c : c);

        if(i > 0)
        {
            printf("x");
            if(i > 1) printf("^%d", i);
        }
    }
    return 0;
}

