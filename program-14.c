/* Program to read a string and reverse the string in the same array itself
   Daya Mathew
   29 July 2025
*/
#include <stdio.h>
#include <string.h>

int main()
 {
    char str[100];
    int i, j;
    char temp;

    printf("Enter a string: ");
    scanf("%s", str); 

    i = 0;
    j = strlen(str) - 1;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    printf("Reversed string: %s\n", str);
}
