#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[50];
    struct node *next;
};

struct node *top = NULL;

// Function to push an element onto the stack
void push(char value[]) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->data, value);
    newNode->next = top;
    top = newNode;
    printf("'%s' pushed to stack.\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL)
        printf("Stack Underflow! (No elements to pop)\n");
    else {
        struct node *temp = top;
        printf("'%s' popped from stack.\n", top->data);
        top = top->next;
        free(temp);
    }
}

// Function to display all elements in the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct node *temp = top;
    printf("Stack elements (Top to Bottom):\n");
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to peek (show top element)
void peek() {
    if (top == NULL)
        printf("Stack is empty.\n");
    else
        printf("Top element: %s\n", top->data);
}

// Function to count elements
void count() {
    int c = 0;
    struct node *temp = top;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    printf("Total elements in stack: %d\n", c);
}

// Main function
int main() {
    int choice;
    char value[50];

    while (1) {
        printf("\n--- LINKED STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Count\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                gets(value);  // you can use fgets(value, 50, stdin);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                count();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

