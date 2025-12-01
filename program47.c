#include <stdio.h>
#include <stdlib.h>

// Define structure with typedef
typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;  // global head pointer

// Function to insert node at end
void insertEnd(int a) {
    node *t = (node *)malloc(sizeof(node));
    t->data = a;
    t->next = NULL;

    if (head == NULL) {
        head = t;
    } else {
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = t;
    }
    printf("Inserted %d successfully.\n", a);
}

// a) Delete node from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    node *t = head;
    head = head->next;
    printf("Deleted node: %d\n", t->data);
    free(t);
}

// b) Delete node from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    node *t = head, *prev = NULL;

    // If only one node exists
    if (head->next == NULL) {
        printf("Deleted node: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // Traverse to second last node
    while (t->next != NULL) {
        prev = t;
        t = t->next;
    }

    printf("Deleted node: %d\n", t->data);
    prev->next = NULL;
    free(t);
}

// c) Delete node with specific data
void deleteSpecific(int a) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    node *t = head, *prev = NULL;

    // If head node itself holds the key
    if (head->data == a) {
        head = head->next;
        printf("Deleted node: %d\n", t->data);
        free(t);
        return;
    }

    // Search for the key to be deleted
    while (t != NULL && t->data != a) {
        prev = t;
        t = t->next;
    }

    // Key not found
    if (t == NULL) {
        printf("Element %d not found.\n", a);
        return;
    }

    // Unlink the node and free memory
    prev->next = t->next;
    printf("Deleted node: %d\n", t->data);
    free(t);
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *t = head;
    printf("Linked List: ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

// Optional: Delete all nodes before exit
void deleteAll() {
    node *t;
    while (head != NULL) {
        t = head;
        head = head->next;
        free(t);
    }
    printf("All nodes deleted.\n");
}

// Main menu-driven function
int main() {
    int ch, a;

    while (1) {
        printf("\n--- Linked List Deletion Menu ---\n");
        printf("1. Insert node (for testing)\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete Specific Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &a);
                insertEnd(a);
                break;
            case 2:
                deleteBeginning();
                break;
            case 3:
                deleteEnd();
                break;
            case 4:
                printf("Enter number to delete: ");
                scanf("%d", &a);
                deleteSpecific(a);
                break;
            case 5:
                display();
                break;
            case 6:
                deleteAll();
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

