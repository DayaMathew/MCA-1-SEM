#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;
node *front = NULL, *rear = NULL;

// Function to insert an element in the circular queue
void insert(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front; // circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // maintain circular link
    }
    printf("%d inserted into the queue\n", value);
}

// Function to delete an element from the circular queue
void delete() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node *temp = front;
    if (front == rear) { // only one element
        printf("Deleted element: %d\n", front->data);
        front = rear = NULL;
    } else {
        printf("Deleted element: %d\n", front->data);
        front = front->next;
        rear->next = front; // maintain circular link
    }
    free(temp);
}

// Function to display the elements in the circular queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node *temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

// Function to count number of elements in the circular queue
int count() {
    if (front == NULL)
        return 0;

    int cnt = 0;
    node *temp = front;
    do {
        cnt++;
        temp = temp->next;
    } while (temp != front);
    return cnt;
}

// Function to sort the circular queue
void sort() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node *i, *j;
    int temp;
    for (i = front; i->next != front; i = i->next) {
        for (j = i->next; j != front; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Queue sorted successfully.\n");
}

// Function to reverse the circular queue
void reverse() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node *prev = NULL, *current = front, *nextNode;
    node *start = front;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != start);

    front->next = prev;
    front = prev;
    rear = start;

    printf("Queue reversed successfully.\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Linked Queue Operations ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Sort\n5. Reverse\n6. Count\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            delete();
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
            printf("Total elements = %d\n", count());
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

