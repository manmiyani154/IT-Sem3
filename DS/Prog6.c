#include <stdio.h>    // For standard input/output functions
#include <stdlib.h>   // For exit() and standard library functions
#include <string.h>   // For string functions like strcat()
#include <ctype.h>    // For character checking functions like isalnum()

#define SIZE 100      // Maximum size for stack and expressions

char stack[SIZE];     // Stack for operators
int top = -1;         // Top pointer for stack
char postfix[SIZE];   // Output postfix expression

// Push an element onto the stack
void push(char val) {
    if (top >= SIZE - 1) {  // Stack overflow check
        printf("Stack Overflow! Cannot push '%c'\n", val);
        exit(1);
    }
    stack[++top] = val;
}

// Pop an element from the stack
char pop() {
    if (top == -1) {  // Stack underflow check
        printf("Stack Underflow! Cannot pop\n");
        exit(1);
    }
    return stack[top--];
}

// Peek at the top element of the stack without removing it
char peek() {
    if (top == -1) {
        printf("Stack is Empty! Cannot peek\n");
        exit(1);
    }
    return stack[top];
}

// Incoming precedence function (f) → precedence of incoming symbol
int f(char sym) {
    switch (sym) {
        case '+':
        case '-': return 1;  // Lowest precedence for addition/subtraction
        case '*':
        case '/': return 3;  // Higher precedence for multiplication/division
        case '^': return 6;  // Highest precedence for exponent
        case '(': return 9;  // Highest incoming precedence for '('
        case ')': return 0;  // Lowest incoming precedence for ')'
        default : return 7;  // For operands (letters/numbers)
    }
}

// In-stack precedence function (g) → precedence of operators already in stack
int g(char sym) {
    switch (sym) {
        case '+':
        case '-': return 2;  // Slightly higher than incoming precedence of '+', '-'
        case '*':
        case '/': return 4;  // Slightly higher than incoming precedence of '*', '/'
        case '^': return 5;  // Slightly lower than incoming precedence of '^'
        case '(': return 0;  // Lowest precedence for '(' in stack
        default : return 8;  // For operands
    }
}

// Rank function → +1 for operand, -1 for operator
int R(char sym) {
    return isalnum(sym) ? 1 : -1; // isalnum() checks if character is a letter or digit
}

// Convert infix expression to postfix using precedence functions
void infixToPostfix(char *infix) {
    int i = 0, j = 0, rank = 0; // i → infix index, j → postfix index, rank → validity check
    char temp;

    push('(');          // Push starting '(' onto stack
    strcat(infix, ")"); // Append ending ')' to the infix expression

    while (infix[i] != '\0') { // Process until end of expression
        char sym = infix[i];

        // Skip spaces
        if (sym == ' ') {
            i++;
            continue;
        }

        // Pop while in-stack precedence > incoming precedence
        while (g(peek()) > f(sym)) {
            temp = pop();
            postfix[j++] = temp; // Add operator to postfix
            rank += R(temp);     // Update rank for validation
            if (rank < 1) {      // Rank rule: must be ≥ 1 during processing
                printf("Invalid Expression\n");
                exit(1);
            }
        }

        // If precedences are not equal, push symbol onto stack
        if (g(peek()) != f(sym)) 
            push(sym);
        else 
            pop(); // Matching '(' and ')', discard both

        i++;
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression

    // Final validation: rank must be exactly 1 and stack should be empty
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
