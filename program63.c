/*
Binary Search Tree (BST) Insertion and Postorder Traversal without Recursion
@Daya Mathew
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

// Function to perform postorder traversal without recursion
void postorderNonRecursive(tree* root) {
    if (root == NULL)
        return;

    tree* stack1[100];
    tree* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        tree* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left)
            stack1[++top1] = current->left;
        if (current->right)
            stack1[++top1] = current->right;
    }

    // Display elements from second stack
    while (top2 != -1)
        printf("%d ", stack2[top2--]->data);
}

int main() {
    tree* root = NULL;
    int n, value;
    int i;

    printf("Binary Search Tree (Postorder without Recursion)\n");

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Insert nodes
    for ( i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Display postorder traversal
    printf("\nPostorder Traversal (Without Recursion): ");
    postorderNonRecursive(root);
    printf("\n");

}
