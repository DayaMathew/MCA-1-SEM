#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

node *head = NULL;

// Insert at beginning
void insertbeg(int a)
{
    node *t = (node*)malloc(sizeof(node));
    t->data = a;
    t->next = head;
    head = t;
    printf("%d inserted at the beginning\n", a);
}

// Insert at end
void insertend(int a)
{
    node *t = (node*)malloc(sizeof(node));
    t->data = a;
    t->next = NULL;

    if (head == NULL) {
        head = t;
    } else {
        node *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = t;
    }
    printf("%d inserted at the end\n", a);
}

// Insert after a specific element
void insert_aft(int a, int key)
{
    node *t = head;
    while (t != NULL && t->data != key) {
        t = t->next;
    }

    if (t == NULL) {
        printf("Element %d not found in the list\n", key);
    } else {
        node *new = (node*)malloc(sizeof(node));
        new->data = a;
        new->next = t->next;
        t->next = new;
        printf("%d inserted after %d\n", a, key);
    }
}

// Display linked list
void display()
{
    node *t = head;
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        printf("Elements are:\n");
        while (t != NULL) {
            printf("%d\t", t->data);
            t = t->next;
        }
        printf("\n");
    }
}

// Main function
int main()
{
    int ch, a, key;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Specific Element\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &a);
                insertbeg(a);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &a);
                insertend(a);
                break;

            case 3:
                printf("Enter element after which to insert: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &a);
                insert_aft(a, key);  // ? Corrected order
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

