/* Binary Search Tree (BST) Operations: Insertion, Search, Deletion, and Traversals
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

// Function to insert a node into BST
tree* insert(tree* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root; // duplicates ignored
}

// Function to search for a value in BST
tree* search(tree* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find minimum node (used in deletion)
tree* findMin(tree* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from BST
tree* deleteNode(tree* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (root->left == NULL) {
            tree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            tree* temp = root->left;
            free(root);
            return temp;
        }

        tree* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(tree* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(tree* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    tree* root = NULL;
    int choice, value;
    tree* found;

    while (1) {
        printf("\n Binary Search Tree Operations\n");
        printf("1. Insert Node\n");
        printf("2. Search Node\n");
        printf("3. Delete Node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted successfully!\n", value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                found = search(root, value);
                if (found != NULL)
                    printf("%d found in the tree.\n", value);
                else
                    printf("%d not found in the tree.\n", value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("%d deleted .\n", value);
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

