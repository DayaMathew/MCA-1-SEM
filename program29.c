/*program to demonstrate queue using array
@Daya Mathew
Roll no:20
28-07-2025 */

#include <stdio.h>
#define SIZE 5   // Maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert an element into the queue
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("\nQueue is Full (Overflow)\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("\nInserted %d into the queue\n", value);
    }
}

// Function to delete an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty (Underflow)\n");
    } 
	else
	 {
        printf("\nDeleted %d from the queue\n", queue[front]);
        front++;
        if (front > rear)
		{  // Reset when queue becomes empty
            front = rear = -1;
        }
    }
}

// Function to display the elements of the queue
void display() {
    if (front == -1) {
        printf("\nQueue is Empty\n");
    } else {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
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

    return 0;
}

