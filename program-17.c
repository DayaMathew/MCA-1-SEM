 /*  program convert an expression from infix expression to postfix using stack
   @Daya Mathew
    Roll no:20
   15-09-2025*/

#include <stdio.h>
#include <ctype.h>   // for isalnum() function

#define MAX 100

// Stack Declaration 
char stack[MAX];     
int top = -1;        // top points to last pushed element

// Stack Operations 
void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
    else
        printf("Stack Overflow\n");
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0'; // return null if empty
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0'; // return null if empty
}

// Helper Functions

// Precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Check if character is operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

//  Main Conversion Function 
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, k = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            // Operand ? directly add to postfix expression
            postfix[k++] = c;
        } 
        else if (c == '(') {
            // Left parenthesis ? push onto stack
            push(c);
        } 
        else if (c == ')') {
            // Right parenthesis ? pop until '(' is found
            while (peek() != '(' && top != -1) {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        } 
        else if (isOperator(c)) {
            // Operator ? pop operators of higher or equal precedence
            while (isOperator(peek()) && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c); // push current operator
        }
    }

    // Pop any remaining operators from the stack
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; // Null terminate the result string
}

// Main Function 
int main() {
	
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);   // Reads expression without spaces

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

