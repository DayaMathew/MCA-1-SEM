/* Program to reverse a string using stack
   Daya Mathew
   27 July 2025
*/
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
 {
    if (top == MAX - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = ch;
}

char pop() {
    if (top == -1)
        return '\0'; 
    else
        return stack[top--];
}

int main()
 {
    char str[MAX], reversed[MAX];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);  

    for (i = 0; i < strlen(str); i++) 
	{
        push(str[i]);
    }

    for (i = 0; i < strlen(str); i++) 
	{
        reversed[i] = pop();
    }
    reversed[i] = '\0';

    printf("Reversed string: %s\n", reversed);

}
