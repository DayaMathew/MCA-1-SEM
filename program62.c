/*
Binary Search Tree (BST) Insertion and Preorder Traversal without Recursion
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

// Function to insert node into BST (recursive)
tree* insert(tree* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root; // duplicates ignored
}

// Function to perform preorder traversal without recursion
void preorderNonRecursive(tree* root) {
    if (root == NULL)
        return;

    tree* stack[100];  // Stack to store nodes
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        tree* current = stack[top--];
        printf("%d ", current->data);

        // Push right child first
        if (current->right)
            stack[++top] = current->right;

        // Push left child next
        if (current->left)
            stack[++top] = current->left;
    }
}

int main() {
    tree* root = NULL;
    int n, value;

    printf(" Binary Search Tree (Preorder without Recursion)\n");

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Insert nodes
    int i;
    for ( i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Display preorder traversal
    printf("\nPreorder Traversal (Without Recursion): ");
    preorderNonRecursive(root);
    printf("\n");

    return 0;
}

