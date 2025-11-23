/* Program to read n strings and sort in ascending order
   Daya Mathew
   27 July 2025
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100][100], temp[100];
    int n, i, j;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++)
	 {
        scanf("%s", str[i]);  // For single-word strings
    }

    // Sort strings using simple bubble sort
    for (i = 0; i < n - 1; i++)
	 {
        for (j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) 
			{
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
    printf("\nStrings in ascending order:\n");
    for (i = 0; i < n; i++)
	 {
        printf("%s\n", str[i]);
    }
}
