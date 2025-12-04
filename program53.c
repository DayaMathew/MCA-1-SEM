#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[50];
    struct node *next;
};

struct node *tail = NULL; // tail pointer points to the last node

// Function to create a new node
struct node* createNode(char value[]) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->data, value);
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(char value[]) {
    struct node *newNode = createNode(value);
    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    printf("Node inserted at beginning.\n");
}

// Insert at end
void insertAtEnd(char value[]) {
    struct node *newNode = createNode(value);
    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    printf("Node inserted at end.\n");
}

// Insert after a specific element
void insertAfterElement(char value[], char after[]) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = tail->next;
    int found = 0;

    do {
        if (strcmp(temp->data, after) == 0) {
            struct node *newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == tail) tail = newNode;
            printf("Node inserted after %s.\n", after);
            found = 1;
            break;
        }
        temp = temp->next;
    } while (temp != tail->next);

    if (!found)
        printf("Element %s not found.\n", after);
}

// Delete a node
void deleteNode(char value[]) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *curr = tail->next, *prev = tail;
    int found = 0;

    do {
        if (strcmp(curr->data, value) == 0) {
            if (curr == tail && curr == tail->next) { // only one node
                free(curr);
                tail = NULL;
            } else {
                prev->next = curr->next;
                if (curr == tail) tail = prev;
                free(curr);
            }
            printf("Node %s deleted.\n", value);
            found = 1;
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    if (!found)
        printf("Node %s not found.\n", value);
}

// Display all nodes
void display() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = tail->next;
    printf("Circular Linked List: ");
    do {
        printf("%s -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(back to head)\n");
}

// Count nodes
void count() {
    if (tail == NULL) {
        printf("Total nodes: 0\n");
        return;
    }

    int c = 0;
    struct node *temp = tail->next;
    do {
        c++;
        temp = temp->next;
    } while (temp != tail->next);

    printf("Total nodes: %d\n", c);
}

// Main function
int main() {
    int choice;
    char value[50], after[50];

    while (1) {
        printf("\n--- CIRCULAR LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Element\n");
        printf("4. Delete Node\n");
        printf("5. Display\n");
        printf("6. Count Nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                gets(value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                gets(value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter element after which to insert: ");
                gets(after);
                printf("Enter value to insert: ");
                gets(value);
                insertAfterElement(value, after);
                break;
            case 4:
                printf("Enter value to delete: ");
                gets(value);
                deleteNode(value);
                break;
            case 5:
                display();
                break;
            case 6:
                count();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

