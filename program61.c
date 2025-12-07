/*
Binary Search Tree (BST) Insertion and Inorder Traversal without Recursion
Name: Daya Mathew
Roll No: 20
Date: 17-10-2025
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct node {
    int data;
    struct node *left, *right;
};
typedef struct node tree;

// Function to create a new node
tree* createNode(int value) {
    tree* newNode = (tree*)malloc(sizeof(tree));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert node into BST
tree* insert(tree* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Function to perform inorder traversal without recursion
void inorderNonRecursive(tree* root) {
    tree* stack[100];  // Stack to store nodes
    int top = -1;
    tree* current = root;

    while (current != NULL || top != -1) {
        // Traverse to leftmost node
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        // Visit node
        current = stack[top--];
        printf("%d ", current->data);

        // Move to right subtree
        current = current->right;
    }
}

int main() {
    tree* root = NULL;
    int n, value;
    int i;

    printf(" Binary Search Tree (Inorder without Recursion)\n");

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Insert nodes
    for ( i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Display inorder traversal
    printf("\nInorder Traversal (Without Recursion): ");
    inorderNonRecursive(root);
    printf("\n");

}
