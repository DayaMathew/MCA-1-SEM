/*   
   Program to evaluate an expression using stack 
   by first converting it into postfix and then evaluating it.
   Supports multi-digit numbers.
   
   @Daya Mathew
   Roll no: 20
   15-09-2025
*/

#include <stdio.h>
#include <ctype.h>
#define SIZE 100

// Operator Stack
char stack[SIZE];
int top = -1;

void push(char ch) {
    if (top < SIZE - 1)
        stack[++top] = ch;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Convert INFIX to POSTFIX using stack
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i]) != '\0') {
        // Skip spaces
        if (ch == ' ' || ch == '\t') {
            i++;
            continue;
        }

        // If digit ? copy entire number to postfix
        if (isdigit(ch)) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';  // space as separator
            continue;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            // Pop till matching '('
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            pop(); // remove '('
        }
        else {  
            // Operator ? pop higher or equal precedence
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            push(ch);
        }
        i++;
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
}

// Operand Stack
int valStack[SIZE];
int valTop = -1;

void pushVal(int val) {
    if (valTop < SIZE - 1)
        valStack[++valTop] = val;
}

int popVal() {
    if (valTop >= 0)
        return valStack[valTop--];
    return 0;
}

// Evaluate POSTFIX expression
int evaluatePostfix(char postfix[])
 {
    int i = 0;
    char ch;
    int val1, val2, result;

    while ((ch = postfix[i]) != '\0') {
        // Skip spaces
        if (ch == ' ' || ch == '\t') {
            i++;
            continue;
        }

        // If number ? push to value stack
        if (isdigit(ch)) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            pushVal(num);
        }
        else 
{
            // Operator ? pop 2 operands and apply
            val2 = popVal();
            val1 = popVal();

            switch (ch) 
{
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = (val2 != 0) ? val1 / val2 : 0; break;
                case '^': {
                    result = 1;
                    int k;
                    for ( k = 0; k < val2; k++)
                        result *= val1;
                    break;
                }
                default: result = 0;
            }
            pushVal(result);
            i++;
        }
    }

    return popVal();  // final result
}

int main()
 {
    char infix[SIZE], postfix[SIZE];
    int i = 0;
    char ch;

    printf("Enter infix expression  ");
    while ((ch = getchar()) != '\n' && i < SIZE - 1) {
        infix[i++] = ch;
    }
    infix[i] = '\0';

    top = -1;
    valTop = -1;

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation result: %d\n", result);

    return 0;
}


 

