#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to create and insert node at end
void insert(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display the list
void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// a) Sort by swapping values
void sortByValue() {
    struct node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted by swapping values.\n");
}

// b) Sort by swapping addresses (links)
void sortByAddress() {
    struct node *prev, *curr, *next;
    int swapped;

    if (head == NULL || head->next == NULL)
        return;

    do {
        swapped = 0;
        prev = NULL;
        curr = head;

        while (curr->next != NULL) {
            if (curr->data > curr->next->data) {
                // Swap nodes
                next = curr->next;
                curr->next = next->next;
                next->next = curr;

                if (prev == NULL)
                    head = next;
                else
                    prev->next = next;

                prev = next;
                swapped = 1;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    } while (swapped);

    printf("List sorted by swapping addresses.\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Sort by Value\n4. Sort by Address\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                display();
                break;
            case 3:
                sortByValue();
                break;
            case 4:
                sortByAddress();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

