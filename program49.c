#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertNode(struct Node** head, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to display polynomial (clean format)
void display(struct Node* poly) {
    struct Node* temp = poly;
    while (temp != NULL) {
        if (temp->pow == 0)
            printf("%d", temp->coeff); // constant term
        else if (temp->pow == 1)
            printf("%dx", temp->coeff); // no ^1
        else
            printf("%dx^%d", temp->coeff, temp->pow);

        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insertNode(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            insertNode(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            insertNode(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// Function to multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node *result = NULL, *ptr1, *ptr2;

    for (ptr1 = poly1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = poly2; ptr2 != NULL; ptr2 = ptr2->next) {
            int coeff = ptr1->coeff * ptr2->coeff;
            int pow = ptr1->pow + ptr2->pow;

            struct Node* temp = result;
            struct Node* prev = NULL;

            // Find correct position (sorted by descending power)
            while (temp != NULL && temp->pow > pow) {
                prev = temp;
                temp = temp->next;
            }

            if (temp != NULL && temp->pow == pow) {
                temp->coeff += coeff; // same power ? add coefficients
            } else {
                struct Node* newNode = createNode(coeff, pow);
                if (prev == NULL) { // insert at beginning
                    newNode->next = result;
                    result = newNode;
                } else {
                    newNode->next = prev->next;
                    prev->next = newNode;
                }
            }
        }
    }
    return result;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL, *product = NULL;
    int degree, coeff;

    printf("Enter first polynomial:\n");
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    int i;
    for (i = degree; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &coeff);
        insertNode(&poly1, coeff, i);
    }

    printf("\nEnter second polynomial:\n");
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    for (i = degree; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &coeff);
        insertNode(&poly2, coeff, i);
    }

    printf("\nFirst polynomial: ");
    display(poly1);
    printf("Second polynomial: ");
    display(poly2);

    sum = addPolynomials(poly1, poly2);
    product = multiplyPolynomials(poly1, poly2);

    printf("\nSum of polynomials: ");
    display(sum);

    printf("Product of polynomials: ");
    display(product);

    return 0;
}

