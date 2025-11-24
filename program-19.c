
 /*  program evaluate an  infix expression using stack
   @Daya Mathew
    Roll no:20
   15 -09-2025*/

#include <stdio.h>
#include <ctype.h>   // for isdigit()
#define SIZE 100

// Stacks for operands and operators
int operands[SIZE];
int topOperands = -1;

char operators[SIZE];
int topOperators = -1;

//  Operand stack operations 
void pushOperand(int val) {
    if (topOperands < SIZE - 1)
        operands[++topOperands] = val;
    else
        printf("Operand stack overflow!\n");
}

int popOperand() {
    if (topOperands >= 0)
        return operands[topOperands--];
    return 0; // default if empty
}

//  Operator stack operations
void pushOperator(char op) {
    if (topOperators < SIZE - 1)
        operators[++topOperators] = op;
    else
        printf("Operator stack overflow!\n");
}

char popOperator() {
    if (topOperators >= 0)
        return operators[topOperators--];
    return '\0';
}

char peekOperator() {
    if (topOperators >= 0)
        return operators[topOperators];
    return '\0';
}

// ----- Operator precedence -----
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

// ----- Apply operator to two operands -----
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? (a / b) : 0;  // avoid division by zero
    }
    return 0;
}

// Process operator according to precedence 
void processOperator(char op) {
    // Keep applying operators while stack top has >= precedence
    while (topOperators != -1 && peekOperator() != '(' &&
           precedence(peekOperator()) >= precedence(op)) {
        
        char oper = popOperator();
        int val2 = popOperand();
        int val1 = popOperand();
        int res = applyOp(val1, val2, oper);
        pushOperand(res);
    }
    pushOperator(op); // push current operator
}

//  Evaluate Infix Expression 
int evaluate(char expr[]) {
    int i = 0;

    while (expr[i] != '\0') {
        char ch = expr[i];

        // Skip spaces
        if (ch == ' ' || ch == '\t') {
            i++;
            continue;
        }

        // If digit ? handle multi-digit number
        if (isdigit(ch)) {
            int val = 0;
            // Read full number
            while (isdigit(expr[i])) {
                val = (val * 10) + (expr[i] - '0');
                i++;
            }
            pushOperand(val);
            continue; // already advanced i inside loop
        }
        // If '(' ? push to operator stack
        else if (ch == '(') {
            pushOperator(ch);
        }
        // If ')' ? solve until '('
        else if (ch == ')') {
            while (topOperators != -1 && peekOperator() != '(') {
                char oper = popOperator();
                int val2 = popOperand();
                int val1 = popOperand();
                int res = applyOp(val1, val2, oper);
                pushOperand(res);
            }
            popOperator(); // remove '('
        }
        // If operator ? process precedence
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            processOperator(ch);
        }

        i++;
    }

    // Process remaining operators
    while (topOperators != -1) {
        char oper = popOperator();
        int val2 = popOperand();
        int val1 = popOperand();
        int res = applyOp(val1, val2, oper);
        pushOperand(res);
    }

    // Final result
    return popOperand();
}

// Main Function 
int main() {
    char expr[SIZE];
    int i = 0;
    char ch;

    printf("Enter infix expression ");
    
    // Read input (with spaces) until Enter
    while ((ch = getchar()) != '\n' && i < SIZE - 1) {
        expr[i++] = ch;
    }
    expr[i] = '\0';  // Null terminate string

    int result = evaluate(expr);
    printf("Result: %d\n", result);

    return 0;
}

