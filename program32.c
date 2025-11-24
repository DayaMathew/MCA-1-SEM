#include <stdio.h>
#define SIZE 5

int data[SIZE], priority[SIZE];
int n = 0;

// Function to insert element with its priority
void insert(int value, int p) {
    if (n == SIZE) {
        printf("Queue is full\n");
        return;
    }

    int i = n - 1;

    // Shift elements to maintain descending order of priority
    while (i >= 0 && p > priority[i]) {
        data[i + 1] = data[i];
        priority[i + 1] = priority[i];
        i--;
    }

    // Insert new element
    data[i + 1] = value;
    priority[i + 1] = p;
    n++;

    printf("Inserted %d with priority %d\n", value, p);
}

// Function to delete element (highest priority first)
void delete() {
    if (n == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element: %d with priority %d\n", data[0], priority[0]);

    // Shift all elements left by one
    int i;
    for ( i = 0; i < n - 1; i++) {
        data[i] = data[i + 1];
        priority[i] = priority[i + 1];
    }
    n--;
}

// Function to display the queue
void display() {
    if (n == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("\nPriority Queue:\n");
    int i;
    for ( i = 0; i < n; i++) {
        printf("Value: %d, Priority: %d\n", data[i], priority[i]);
    }
}

int main() {
    int choice, value, p;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &value, &p);
                insert(value, p);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

