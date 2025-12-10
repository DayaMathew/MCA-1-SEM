/*
Graph Representation of Adjacency Matrix using array
Name: Daya Mathew
Roll No: 20
Date: 15-10-2025
*/

#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Graphs Using Arrays (Adjacency Matrix)\n");
    
    // Read number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    // Read adjacency matrix
    printf("Enter adjacency matrix (1 if edge exists, 0 otherwise):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Edge from %c to %c: ", 'A' + i, 'A' + j);
            scanf("%d", &adj[i][j]);
        }
    }

    // Display adjacency matrix with labels
    printf("\nAdjacency Matrix:\n\n    ");
    for (i = 0; i < n; i++)
        printf("%c   ", 'A' + i);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%c   ", 'A' + i);
        for (j = 0; j < n; j++)
            printf("%d   ", adj[i][j]);
        printf("\n");
    }

    return 0;
}
 

