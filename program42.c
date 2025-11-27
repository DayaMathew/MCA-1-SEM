#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Book
struct Book {
    char author_name[50];
    char book_name[50];
};

// Function to read n books using pointer
void readBooks(struct Book *books, int n)
 {	
 	int i;
    for( i = 0; i < n; i++) {
        printf("\nEnter details for Book %d:\n", i + 1);

        printf("Author Name: ");
        getchar(); // clear newline from previous input
        fgets(books[i].author_name, 50, stdin);
        books[i].author_name[strcspn(books[i].author_name, "\n")] = '\0'; // remove newline

        printf("Book Name: ");
        fgets(books[i].book_name, 50, stdin);
        books[i].book_name[strcspn(books[i].book_name, "\n")] = '\0';
    }
}

// Function to display n books using pointer
void displayBooks(struct Book *books, int n) {
    printf("\nList of Books:\n");
    int i;
    for(i = 0; i < n; i++) 
	{
        printf("Book %d:\n", i + 1);
        printf("Author: %s\n", books[i].author_name);
        printf("Book Name: %s\n\n", books[i].book_name);
    }
}

int main() {
    int n;
    struct Book *books;

    printf("Enter number of books: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n books
    books = (struct Book *)malloc(n * sizeof(struct Book));
    if(books == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read books
    readBooks(books, n);

    // Display books
    displayBooks(books, n);

    // Free allocated memory
    free(books);

    return 0;
}

