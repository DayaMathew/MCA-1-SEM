/* Program to read a string and print it in reverse order
   Daya Mathew
   26 July 2025 */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);   // Reads a word (stops at space or newline)

    int len = strlen(str);

    printf("Reversed string: ");
    for (i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    printf("\n");
    return 0;
}

