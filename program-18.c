
 /*  program convert an expression from infix expression to pretfix using stack
   @Daya Mathew
    Roll no:20
   15 -09-2025*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack Implementation 
char stack[MAX];
int top = -1;

// Push element onto stack
void push(char c) 
{
    if (top < MAX - 1)
        stack[++top] = c;
    else
        printf("Stack Overflow!\n");
}

// Pop element from stack
char pop()
 {
    if (top >= 0)
        return stack[top--];
    return '\0';  // return null char if stack empty
}

// Peek top element
char peek()
 {
    if (top >= 0)
        return stack[top];
    return '\0';
}

// Return precedence of operators
int precedence(char op)
 {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Check if character is operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Reverse a string in place
void reverse(char *exp) 
{
    int len = strlen(exp);
    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

// Swap '(' with ')' and vice versa
void swapParentheses(char* exp)
 {
    Int i;
    for ( i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
}

//  Infix ? Postfix 
void infixToPostfix(char* infix, char* postfix)
 {
    int i = 0, k = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            // Operand ? directly add to postfix
            postfix[k++] = c;
        }
        else if (c == '(') {
            // Left parenthesis ? push
            push(c);
        }
        else if (c == ')') {
            // Right parenthesis ? pop until '('
            while (peek() != '(' && top != -1) {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        else if (isOperator(c)) {
            // Operator ? pop higher/equal precedence operators
            while (isOperator(peek()) && 
                  ((precedence(peek()) > precedence(c)) ||
                   (precedence(peek()) == precedence(c) && c != '^'))) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; // Null terminate result
}

// Infix ? Prefix Conversion 
void infixToPrefix(char* infix, char* prefix) {
    char reversedInfix[MAX], postfix[MAX];

    strcpy(reversedInfix, infix);
    reverse(reversedInfix);          // Step 1: Reverse infix
    swapParentheses(reversedInfix);  // Step 2: Swap '(' and ')'
    infixToPostfix(reversedInfix, postfix); // Step 3: Convert reversed infix ? postfix
    reverse(postfix);                // Step 4: Reverse postfix ? prefix
    strcpy(prefix, postfix);
}

// Main Function 
int main() 
{
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);  

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}        

