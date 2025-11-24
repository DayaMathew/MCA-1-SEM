
 /*program demonstrate circular queue.
@Daya Mathew
Roll no:20
28-07-2025 */

#include <stdio.h>
#define SIZE 5   // Maximum size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert an element into the circular queue
void enqueue(int value) {
    // Check if the queue is full
    if ((front == 0 && rear == SIZE - 1) || (rear + 1)%SIZE == front)) {
        printf("\nQueue is Full (Overflow)\n");
    } 
    else {
        // First insertion
        if (front == -1)
            front = 0;

        // Move rear circularly
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("\nInserted %d into the queue\n", value);
    }
}

// Function to delete an element from the circular queue
void dequeue() {
    if (front == -1) {
        printf("\nQueue is Empty (Underflow)\n");
    } 
    else {
        printf("\nDeleted %d from the queue\n", queue[front]);

        // If only one element was left
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

// Function to display the elements of the circular queue
void display() {
    if (front == -1) {
        printf("\nQueue is Empty\n");
    } 
    else  {
        printf("\nQueue elements are:\n");

        int i;
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]); // print the last element (rear)
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
}

