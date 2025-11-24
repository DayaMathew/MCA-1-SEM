
/*  
   Program to perform stack operations:
   Push alphabets, pop when '*' is encountered
   @Daya Mathew
   Roll no:20
   15-09-2025
*/

#include <stdio.h>
#include <ctype.h>
#define SIZE 100

char stack[SIZE];   // stack array
int top = -1;       // stack top index

// push character onto stack
void push(char ch) {
    if (top < SIZE - 1)
        stack[++top] = ch;
}

// pop character from stack
char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

int main()
 {
    char sequence[SIZE];  // input sequence
    int index;

    printf("Enter the sequence (letters and '*'): ");
    scanf("%[^\n]", sequence);

    printf("Popped values: ");
    for (index = 0; sequence[index] != '\0'; index++) 
{
        if (isalpha(sequence[index])) 
{
            push(sequence[index]);       // push if alphabet
        } else if (sequence[index] == '*') 
{
            char popped = pop();         // pop on '*'
            if (popped != '\0')
                printf("%c ", popped);
        }
    }
    printf("\n");
    return 0;
}
 

