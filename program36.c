#include <stdio.h>

struct polynomial {
    int coeff[20];
    int degree;
};

int main() {
    struct polynomial p1, p2, sum;
    int i;

    // --- Input for first polynomial ---
    printf("Enter first polynomial:\n");
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &p1.degree);
    for (i = p1.degree; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &p1.coeff[i]);
    }

    // --- Input for second polynomial ---
    printf("\nEnter second polynomial:\n");
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &p2.degree);
    for (i = p2.degree; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &p2.coeff[i]);
    }

    // --- Find highest degree ---
    if (p1.degree > p2.degree)
        sum.degree = p1.degree;
    else
        sum.degree = p2.degree;

    // --- Add polynomials ---
    for (i = 0; i <= sum.degree; i++) {
        sum.coeff[i] = 0; // initialize
        if (i <= p1.degree)
            sum.coeff[i] += p1.coeff[i];
        if (i <= p2.degree)
            sum.coeff[i] += p2.coeff[i];
    }

    // --- Display first polynomial ---
    printf("\nFirst polynomial: ");
    for (i = p1.degree; i >= 0; i--) {
        printf("%dx^%d", p1.coeff[i], i);
        if (i != 0)
            printf(" + ");
    }

    // --- Display second polynomial ---
    printf("\nSecond polynomial: ");
    for (i = p2.degree; i >= 0; i--) {
        printf("%dx^%d", p2.coeff[i], i);
        if (i != 0)
            printf(" + ");
    }

    // --- Display sum polynomial ---
    printf("\n\nSum of polynomials: ");
    for (i = sum.degree; i >= 0; i--) {
        printf("%dx^%d", sum.coeff[i], i);
        if (i != 0)
            printf(" + ");
    }

    printf("\n");
    return 0;
}

