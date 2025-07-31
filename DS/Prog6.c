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
// Incoming precedence function
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
// In-stack precedence function
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
    push('(');                  // Add starting '('
    strcat(infix, ")");         // Add ending ')'

    while (infix[i] != '\0') {
        char sym = infix[i];
        if (sym == ' ') {
            i++;
            continue;
        }
        // Pop while stack precedence > input precedence
        while (g(peek()) > f(sym)) {
            temp = pop();
            postfix[j++] = temp;
            rank += R(temp);
            if (rank < 1) {
                printf("Invalid Expression\n");
                exit(1);
            }
        }
      // Push if not equal precedence (e.g., '(' vs ')')
        if (g(peek()) != f(sym)) push(sym);
        else pop(); // Matching parenthesis, discard both

        i++;
    }

    postfix[j] = '\0';
    // Final validation
    if (top != -1 || rank != 1) {
        printf("Invalid Expression\n");
        exit(1);
    } else {
        printf("Postfix: %s\n", postfix);
    }
}

int main() {
    char infix[SIZE];
    printf("Enter infix expression: ");
    scanf(" %[^\n]", infix);
    infixToPostfix(infix);
    return 0;
}
