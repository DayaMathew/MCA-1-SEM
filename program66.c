#include <stdio.h>
#include <stdlib.h>

// Node to represent each element in adjacency matrix row
typedef struct Node {
    int col;            // Column index
    int value;          // Edge weight
    struct Node* next;  // Pointer to next node in the row
} Node;

// Each row is a linked list
typedef struct Row {
    Node* head;         // Head of linked list for this row
} Row;

// Function to create a new node
Node* createNode(int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the linked list of a row
void insertNode(Row* row, int col, int value) {
    Node* newNode = createNode(col, value);
    if (row->head == NULL) {
        row->head = newNode;
    } else {
        Node* temp = row->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to display adjacency matrix using linked lists
void displayMatrix(Row rows[], int n, char vertices[]) {
    printf("\nAdjacency Matrix:\n\n    ");
    int i;
    for (i = 0; i < n; i++)
        printf("%c   ", vertices[i]);
    printf("\n");

    for ( i = 0; i < n; i++) {
        printf("%c   ", vertices[i]);
        Node* temp = rows[i].head;
        int colIndex = 0;
        while (colIndex < n) {
            if (temp != NULL && temp->col == colIndex) {
                printf("%d   ", temp->value);
                temp = temp->next;
            } else {
                printf("0   ");
            }
            colIndex++;
        }
        printf("\n");
    }
}

int main() {
    int n,j,i;
    printf("Graphs Using Linked Lists (Adjacency Matrix)\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    Row rows[n];
    char vertices[n];
    for ( i = 0; i < n; i++) {
        rows[i].head = NULL;
        vertices[i] = 'A' + i; // Assign names A, B, C, ...
    }

    printf("Enter adjacency matrix (weight of edge, 0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            int value;
            printf("Edge from %c to %c: ", vertices[i], vertices[j]);
            scanf("%d", &value);
            if (value != 0)
                insertNode(&rows[i], j, value);
        }
    }

    displayMatrix(rows, n, vertices);

    return 0;
}

