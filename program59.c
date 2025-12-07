#include <stdio.h>
#include <string.h>

int main() {
    int n, low, high, mid, result;
    char arr[100][50], key[50];

    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar(); // clear newline from buffer

    printf("Enter %d strings in sorted order:\n", n);
    int i;
    for ( i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    printf("Enter string to search: ");
    scanf("%s", key);

    low = 0;
    high = n - 1;
    int found = 0;

    // Binary Search logic
    while (low <= high) {
        mid = (low + high) / 2;
        result = strcmp(key, arr[mid]);

        if (result == 0) {
            printf("String \"%s\" found at position %d.\n", key, mid + 1);
            found = 1;
            break;
        } else if (result > 0) {
            low = mid + 1; // search right half
        } else {
            high = mid - 1; // search left half
        }
    }

    if (!found)
        printf("String \"%s\" not found in the array.\n", key);

    return 0;
}

