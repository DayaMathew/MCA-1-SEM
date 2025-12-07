#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
typedef struct Node node;

node *head = NULL;

// Function to create a new node
node* createNode(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(int value) {
    node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted successfully.\n", value);
}

// Delete a node by value
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    if (temp == head)  // deleting first node
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    printf("%d deleted successfully.\n", value);
    free(temp);
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Count the number of nodes
int count() {
    int c = 0;
    node *temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

// Sort the list in ascending order
void sort() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted successfully.\n");
}

// Reverse the list
void reverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *temp = NULL, *current = head;

    // Swap prev and next for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Before changing head, check for the case when list is not empty
    if (temp != NULL)
        head = temp->prev;

    printf("List reversed successfully.\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Sort\n5. Reverse\n6. Count\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertEnd(value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
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

