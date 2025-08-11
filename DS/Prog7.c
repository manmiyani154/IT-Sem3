#include <stdio.h>    // Standard I/O
#include <stdlib.h>   // For exit()
#include <string.h>   // For strcat()
#include <ctype.h>    // For isalpha(), isalnum()

#define SIZE 100

char stack[SIZE];     // Stack for infix-to-postfix conversion
int top = -1;         // Top pointer for operator stack
char postfix[SIZE];   // Output postfix expression

// Push character onto stack
void push(char val) {
    if (top >= SIZE - 1) { // Check overflow
        printf("Stack Overflow! Cannot push '%c'\n", val);
        exit(1);
    }
    stack[++top] = val;
}

// Pop character from stack
char pop() {
    if (top == -1) { // Check underflow
        printf("Stack Underflow! Cannot pop\n");
        exit(1);
    }
    return stack[top--];
}

// Peek top of stack
char peek() {
    if (top == -1) {
        printf("Stack is Empty! Cannot peek\n");
        exit(1);
    }
    return stack[top];
}

// Incoming precedence function
int f(char sym) {
    switch (sym) {
        case '+':
        case '-': return 1; // Lowest precedence
        case '*':
        case '/': return 3; // Higher precedence
        case '^': return 6; // Highest precedence for incoming
        case '(': return 9; // '(' always has highest incoming precedence
        case ')': return 0; // Lowest for closing parenthesis
        default : return 7; // For operands
    }
}

// In-stack precedence function
int g(char sym) {
    switch (sym) {
        case '+':
        case '-': return 2; // Slightly higher than incoming '+','-'
        case '*':
        case '/': return 4; // Slightly higher than incoming '*','/'
        case '^': return 5; // Slightly lower than incoming '^'
        case '(': return 0; // '(' lowest in stack
        default : return 8; // For operands
    }
}

// Rank check: +1 for operand, -1 for operator
int R(char sym) {
    return isalnum(sym) ? 1 : -1;
}

// Convert infix expression to postfix
void infixToPostfix(char *infix) {
    int i = 0, j = 0, rank = 0;
    char temp;

    push('(');          // Push starting '('
    strcat(infix, ")"); // Append closing ')' to mark end

    while (infix[i] != '\0') {
        char sym = infix[i];

        // Skip spaces
        if (sym == ' ') {
            i++;
            continue;
        }

        // While top of stack has higher precedence, pop to postfix
        while (g(peek()) > f(sym)) {
            temp = pop();
            postfix[j++] = temp;
            rank += R(temp); // Maintain rank balance

            if (rank < 1) {  // Rank rule broken → invalid expression
                printf("Invalid Expression\n");
                exit(1);
            }
        }

        // If precedence not equal, push symbol
        if (g(peek()) != f(sym))
            push(sym);
        else
            pop(); // Matching '(' and ')', discard

        i++;
    }

    postfix[j] = '\0'; // End postfix string

    // Final check: stack empty & rank exactly 1
    if (top != -1 || rank != 1) {
        printf("Invalid Expression\n");
        exit(1);
    } else {
        printf("Postfix: %s\n", postfix);
    }
}

// Evaluate a postfix expression
void evaluatePostfix(char *postfix) {
    float evalStack[SIZE];    // Stack for evaluation
    int evalTop = -1;         // Top of eval stack
    float variables[26] = {0}; // Store values for a-z
    int used[26] = {0};        // Track if variable value already taken

    for (int i = 0; postfix[i] != '\0'; i++) {
        char sym = postfix[i];

        // If operand (a-z), push its value
        if (isalpha(sym)) {
            int index = sym - 'a';
            if (!used[index]) { // Ask value only once
                printf("Enter value of %c: ", sym);
                scanf("%f", &variables[index]);
                used[index] = 1;
            }
            evalStack[++evalTop] = variables[index];
        }
        // If operator, pop two operands and apply operation
        else {
            if (evalTop < 1) { // Not enough operands
                printf("Invalid Expression for Evaluation\n");
                return;
            }
            float b = evalStack[evalTop--]; // Second operand
            float a = evalStack[evalTop--]; // First operand
            float res;

            switch (sym) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Division by zero error!\n");
                        return;
                    }
                    res = a / b;
                    break;
                default:
                    printf("Unknown operator '%c'\n", sym);
                    return;
            }
            evalStack[++evalTop] = res; // Push result back
        }
    }

    // Final result should be only one value
    if (evalTop == 0) {
        printf("Result = %.2f\n", evalStack[evalTop]);
    } else {
        printf("Invalid postfix evaluation\n");
    }
}

int main() {
    char infix[SIZE];
    printf("Enter infix expression: ");
    scanf(" %[^\n]", infix);
    infixToPostfix(infix);
    evaluatePostfix(postfix);
    return 0;
}
