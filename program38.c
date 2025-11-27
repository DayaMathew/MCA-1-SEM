#include <stdio.h>

struct poly {
    int c[40];  // coefficients
    int d;      // degree
};

int main() {
    struct poly p1, p2, pr;
    int i, j;

    // Input first polynomial
    printf("Enter degree of first polynomial: ");
    scanf("%d", &p1.d);
    for (i = 0; i <= p1.d; i++) {
        printf("Coeff of x^%d: ", i);
        scanf("%d", &p1.c[i]);
    }

    // Input second polynomial
    printf("\nEnter degree of second polynomial: ");
    scanf("%d", &p2.d);
    for (i = 0; i <= p2.d; i++) {
        printf("Coeff of x^%d: ", i);
        scanf("%d", &p2.c[i]);
    }

    // Initialize product
    pr.d = p1.d + p2.d;
    for (i = 0; i <= pr.d; i++)
        pr.c[i] = 0;

    // Multiply
    for (i = 0; i <= p1.d; i++)
        for (j = 0; j <= p2.d; j++)
            pr.c[i + j] += p1.c[i] * p2.c[j];

    // Display product
    printf("\nProduct: ");
    for (i = pr.d; i >= 0; i--) {
        printf("%dx^%d", pr.c[i], i);
        if (i != 0) printf(" + ");
    }
    printf("\n");

    return 0;
}

