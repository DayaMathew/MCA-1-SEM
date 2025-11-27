/* Program to read and display a polynomial using structure array
   @Daya Mathew
   08-09-2025 */

#include <stdio.h>

// Structure for one term of a polynomial
struct term {
    int coeff;   // Coefficient
    int exp;     // Exponent
};

int main() {
    struct term poly[20];   // Array of polynomial terms
    int deg, i;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &deg);

    // Read coefficients (exponents auto-assigned)
    for (i = deg; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly[deg - i].coeff);
        poly[deg - i].exp = i;   // assign exponent automatically
    }

    printf("\nPolynomial: ");
    // Display the polynomial neatly
    for (i = 0; i <= deg; i++) {
        int c = poly[i].coeff;
        int e = poly[i].exp;

        if (c == 0)
            continue; // skip zero terms

        // print + sign for positive terms except first
        if (i > 0 && c > 0)
            printf("+");

        // print sign for negative terms
        if (c < 0)
            printf("-");

        // print coefficient (skip 1 and -1 for x terms)
        if (e == 0 || c > 1 || c < -1)
            printf("%d", c < 0 ? -c : c);

        // print variable and exponent
        if (e > 0) {
            printf("x");
            if (e > 1)
                printf("^%d", e);
        }
        printf(" ");
    }

    printf("\n");
    return 0;
}

