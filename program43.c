#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = NULL;  // Pointer to hold the string
    int size = 0;      // Current allocated size
    int ch, length = 0;

    printf("Enter a string (press Enter to finish): ");

    while(1) {
        ch = getchar();      // Read one character

        if(ch == '\n')       // Stop at newline
            break;

        // Reallocate memory to hold one more character
        char *temp = realloc(str, (length + 1) * sizeof(char));
        if(temp == NULL) {
            printf("Memory allocation failed.\n");
            free(str);
            return 1;
        }
        str = temp;

        str[length] = (char)ch; // Store character
        length++;
    }

    // Add null terminator
    char *temp = realloc(str, (length + 1) * sizeof(char));
    if(temp == NULL) {
        printf("Memory allocation failed.\n");
        free(str);
        return 1;
    }
    str = temp;
    str[length] = '\0';

    printf("\nYou entered: %s\n", str);

    free(str); // Free allocated memory
    return 0;
}

