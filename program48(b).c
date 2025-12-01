#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Display linked list
void displayList(struct Node *head) {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Sort linked list by changing addresses (links)
void sortByLinks(struct Node **headRef) {
    if(*headRef == NULL || (*headRef)->next == NULL) return;

    int swapped;
    struct Node **ptr;
    do {
        swapped = 0;
        ptr = headRef;

        while((*ptr)->next != NULL) {
            if((*ptr)->data > (*ptr)->next->data) {
                struct Node *tmp = *ptr;
                struct Node *nextNode = tmp->next;

                // Swap links
                tmp->next = nextNode->next;
                nextNode->next = tmp;
                *ptr = nextNode;

                swapped = 1;
            }
            ptr = &(*ptr)->next;
        }
    } while(swapped);
}

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = createNode(value);
        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\nOriginal List: ");
    displayList(head);

    // Sort by swapping addresses
    sortByLinks(&head);

    printf("Sorted List (by addresses): ");
    displayList(head);

    // Free memory
    temp = head;
    while(temp != NULL) {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}

