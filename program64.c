/*
Binary Search Tree (BST) Insertion Using Names and Inorder Traversal
Name: Daya Mathew
Roll No: 20
Date: 17-10-2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    struct node *left, *right;
};
typedef struct node tree;

// Function to create a new node
tree* createNode(char name[]) {
    tree* newNode = (tree*)malloc(sizeof(tree));
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a name into the BST
tree* insert(tree* root, char name[]) {
    if (root == NULL)
        return createNode(name);

    if (strcmp(name, root->name) < 0)
        root->left = insert(root->left, name);
    else if (strcmp(name, root->name) > 0)
        root->right = insert(root->right, name);

    return root; // duplicates ignored
}

// Inorder traversal to display names in ascending order
void inorder(tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s\n", root->name);
        inorder(root->right);
    }
}

int main() {
    tree* root = NULL;
    int n, i;
    char name[50];

    printf("Binary Search Tree Using Names\n");

    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar(); // Clear input buffer

    for (i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline
        root = insert(root, name);
    }

    printf("\nNames in Ascending Order (Inorder Traversal):\n");
    inorder(root);

    return 0;
}

