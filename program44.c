#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display linked list
void displayList(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = createNode(value);

        if(head == NULL) {
            head = newNode; // first node
            temp = head;
        } else {
            temp->next = newNode; // link new node
            temp = newNode;
        }
    }

    // Display the linked list
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

