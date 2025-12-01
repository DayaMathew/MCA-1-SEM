#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    struct node *next;
};

struct node *head = NULL;

// Function to create and insert node at end
void insert(char n[]) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, n);
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Name inserted successfully.\n");
}

// Function to delete a name
void deleteName(char n[]) {
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If the name to delete is at the head
    if (strcmp(head->name, n) == 0) {
        head = head->next;
        free(temp);
        printf("Name deleted successfully.\n");
        return;
    }

    // Search for the name
    while (temp != NULL && strcmp(temp->name, n) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        printf("Name not found.\n");
    else {
        prev->next = temp->next;
        free(temp);
        printf("Name deleted successfully.\n");
    }
}

// Function to display all names
void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Names in the list:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to count total names
void count() {
    int c = 0;
    struct node *temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    printf("Total names: %d\n", c);
}

// Function to sort names alphabetically
void sort() {
    struct node *i, *j;
    char temp[50];

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {
                strcpy(temp, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp);
            }
        }
    }
    printf("Names sorted alphabetically.\n");
}

// Function to reverse the list
void reverse() {
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed successfully.\n");
}

// Main function
int main() {
    int choice;
    char name[50];

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert Name\n");
        printf("2. Delete Name\n");
        printf("3. Display Names\n");
        printf("4. Sort Names\n");
        printf("5. Reverse List\n");
        printf("6. Count Names\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter name to insert: ");
                gets(name);
                insert(name);
                break;
            case 2:
                printf("Enter name to delete: ");
                gets(name);
                deleteName(name);
                break;
            case 3:
                display();
                break;
            case 4:
                sort();
                break;
            case 5:
                reverse();
                break;
            case 6:
                count();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

