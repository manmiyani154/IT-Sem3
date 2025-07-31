#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;
char postfix[SIZE];

void push(char val) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow! Cannot push '%c'\n", val);
        exit(1);
    }
    stack[++top] = val;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop\n");
        exit(1);
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        printf("Stack is Empty! Cannot peek\n");
        exit(1);
    }
    return stack[top];
}

// Incoming precedence
int f(char sym) {
    switch (sym) {
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

// In-stack precedence
int g(char sym) {
    switch (sym) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        default : return 8;
    }
}

// Rank: 1 for operands, -1 for operators
int R(char sym) {
    return isalnum(sym) ? 1 : -1;
}

void infixToPostfix(char *infix) {
    int i = 0, j = 0, rank = 0;
    char temp;
    push('(');
    strcat(infix, ")");

    while (infix[i] != '\0') {
        char sym = infix[i];
        if (sym == ' ') {
            i++;
            continue;
        }
        while (g(peek()) > f(sym)) {
            temp = pop();
            postfix[j++] = temp;
            rank += R(temp);
            if (rank < 1) {
                printf("Invalid Expression\n");
                exit(1);
            }
        }
        if (g(peek()) != f(sym)) push(sym);
        else pop();
        i++;
    }

    postfix[j] = '\0';

    if (top != -1 || rank != 1) {
        printf("Invalid Expression\n");
        exit(1);
    } else {
        printf("Postfix: %s\n", postfix);
    }
}

void evaluatePostfix(char *postfix) {
    float evalStack[SIZE];
    int evalTop = -1;
    float variables[26] = {0}; // For a-z
    int used[26] = {0};        // Track if value already entered

    for (int i = 0; postfix[i] != '\0'; i++) {
        char sym = postfix[i];

        if (isalpha(sym)) {
            int index = sym - 'a';
            if (!used[index]) {
                printf("Enter value of %c: ", sym);
                scanf("%f", &variables[index]);
                used[index] = 1;
            }
            evalStack[++evalTop] = variables[index];
        } else {
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
