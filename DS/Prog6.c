#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

// Stack and its pointer
char stack[SIZE];
int top = -1;

// Push character onto stack
void push(char val) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow! Cannot push '%c'\n", val);
        exit(1);
    }
    stack[++top] = val;
}

// Pop character from stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop\n");
        exit(1);
    }
    return stack[top--];
}

// Peek top character from stack
char peek() {
    if (top == -1) {
        printf("Stack is Empty! Cannot peek\n");
        exit(1);
    }
    return stack[top];
}

// Incoming precedence of operators
int f(char symbol) {
    switch (symbol) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default : return 7;
    }
}

// In-stack precedence of operators
int g(char symbol) {
    switch (symbol) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        default : return 8;
    }
}

// Returns 1 if symbol is operand (letter or number), else -1
int R(char symbol) {
    return isalnum(symbol) ? 1 : -1;
}

// Buffer to store postfix result
char postfix[SIZE];

// Convert infix expression to postfix
void infixToPostfix(char *infix) {
    int i = 0, j = 0, rank = 0;
    char temp;
    push('('); // Start with '(' on stack
    strcat(infix, ")"); // Add ')' at the end of infix

    while (infix[i] != '\0') {
        char sym = infix[i];
        if (sym == ' ') {
            i++;
            continue;
        }

        // Pop operators from stack if they have higher precedence
        while (g(peek()) > f(sym)) {
            temp = pop();
            postfix[j++] = temp;
            rank += R(temp);
            if (rank < 1) {
                printf("Invalid Expression\n");
                exit(1);
            }
        }

        // Push current symbol if precedence doesn't match
        if (g(peek()) != f(sym)) push(sym);
        else pop(); // Discard matching parenthesis

        i++;
    }

    postfix[j] = '\0';

    // Check for correctness
    if (top != -1 || rank != 1) {
        printf("Invalid Expression\n");
        exit(1);
    } else {
        printf("Postfix: %s\n", postfix);
    }
}

// Evaluate postfix expression
void evaluatePostfix(char *postfix) {
    float evalStack[SIZE];
    int evalTop = -1;
    float variables[26] = {0}; // Stores values of a-z
    int used[26] = {0};        // Track which variables are set

    for (int i = 0; postfix[i] != '\0'; i++) {
        char sym = postfix[i];

        // If operand, ask for its value
        if (isalpha(sym)) {
            int index = sym - 'a';
            if (!used[index]) {
                printf("Enter value of %c: ", sym);
                scanf("%f", &variables[index]);
                used[index] = 1;
            }
            evalStack[++evalTop] = variables[index];
        } else {
            // Perform operation with top two values
            if (evalTop < 1) {
                printf("Invalid Expression for Evaluation\n");
                return;
            }

            float b = evalStack[evalTop--];
            float a = evalStack[evalTop--];
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

            evalStack[++evalTop] = res;
        }
    }

    // Final result should be at top of stack
    if (evalTop == 0) {
        printf("Result = %.2f\n", evalStack[evalTop]);
    } else {
        printf("Invalid postfix evaluation\n");
    }
}

int main() {
    char infix[SIZE];
    printf("Enter infix expression (with spaces if needed): ");
    scanf(" %[^\n]", infix); // Read full line with spaces

    infixToPostfix(infix);  // Convert to postfix
    evaluatePostfix(postfix); // Evaluate result
    return 0;
}
