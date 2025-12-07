#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for node
struct Node {
    char data[50];
    struct Node *prev;
    struct Node *next;
};
typedef struct Node node;

node *head = NULL;

// Function to create a new node
node* createNode(char value[]) {
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->data, value);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert a node at the end
void insertEnd(char value[]) {
    node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        node *last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
    printf("\"%s\" inserted successfully.\n", value);
}

// Delete a node by value
void deleteNode(char value[]) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *temp = head;
    node *toDelete = NULL;

    // Search for the node
    do {
        if (strcmp(temp->data, value) == 0) {
            toDelete = temp;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (toDelete == NULL) {
        printf("\"%s\" not found in the list.\n", value);
        return;
    }

    // If only one node
    if (toDelete->next == toDelete && toDelete->prev == toDelete) {
        head = NULL;
    } 
    else {
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        if (toDelete == head)
            head = toDelete->next;
    }

    printf("\"%s\" deleted successfully.\n", value);
    free(toDelete);
}

// Display all nodes
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("[%s] ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Count nodes
int count() {
    if (head == NULL)
        return 0;

    int c = 0;
    node *temp = head;
    do {
        c++;
        temp = temp->next;
    } while (temp != head);
    return c;
}

// Sort the list alphabetically
void sort() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *i, *j;
    char temp[50];

    for (i = head; i->next != head; i = i->next) {
        for (j = i->next; j != head; j = j->next) {
            if (strcmp(i->data, j->data) > 0) {
                strcpy(temp, i->data);
                strcpy(i->data, j->data);
                strcpy(j->data, temp);
            }
        }
    }
    printf("List sorted alphabetically.\n");
}

// Reverse the circular doubly linked list
void reverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *current = head, *temp = NULL;

    do {
        // Swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != head);

    if (temp != NULL)
        head = temp->prev; // adjust head

    printf("List reversed successfully.\n");
}

// Main function
int main() {
    int choice;
    char value[50];

    while (1) {
        printf("\n--- Circular Doubly Linked List Operations ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Sort\n5. Reverse\n6. Count\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from input buffer

        switch (choice) {
        case 1:
            printf("Enter string to insert: ");
            scanf("%[^\n]", value);
            insertEnd(value);
            break;

        case 2:
            printf("Enter string to delete: ");
            scanf("%[^\n]", value);
            deleteNode(value);
            break;

        case 3:
            display();
            break;

        case 4:
            sort();
            break;

        case 5:
            reverse();
            break;

        case 6:
            printf("Total nodes = %d\n", count());
            break;

        case 7:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

