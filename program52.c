#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[50];
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Function to insert (enqueue) an element
void enqueue(char value[]) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->data, value);
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("'%s' inserted into queue.\n", value);
}

// Function to delete (dequeue) an element
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! (No elements to delete)\n");
        return;
    }

    struct node *temp = front;
    printf("'%s' deleted from queue.\n", front->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Function to display all elements in the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node *temp = front;
    printf("Queue elements (Front to Rear):\n");
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to peek (view the front element)
void peek() {
    if (front == NULL)
        printf("Queue is empty.\n");
    else
        printf("Front element: %s\n", front->data);
}

// Function to count elements
void count() {
    int c = 0;
    struct node *temp = front;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    printf("Total elements in queue: %d\n", c);
}

// Main function
int main() {
    int choice;
    char value[50];

    while (1) {
        printf("\n--- LINKED QUEUE MENU ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Peek (Front Element)\n");
        printf("5. Count\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                gets(value); // use fgets(value, 50, stdin) for safer input
                enqueue(value);
                break;
            case 2:
                dequeue();
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

