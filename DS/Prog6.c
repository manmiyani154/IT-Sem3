#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char val) {
    stack[++top] = val;
}
char pop() {
    return stack[top--];
}
char peek() {
    return stack[top];
}

int f(char symbol) {
    switch(symbol) {
        case '+': case '-': return 1;
        case '*': case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;
    }
}

int g(char symbol) {
    switch(symbol) {
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        default: return 8;
    }
}

int R(char symbol) {
    if (isalnum(symbol))
        return 1;
    else
        return -1;
}

void infixToPostfix(char* infix) {
    char postfix[SIZE];
    int i = 0, j = 0, rank = 0;
    char temp;

    push('(');
    strcat(infix, ")");

    while(infix[i] != '\0') {
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
                return;
            }
        }

        if (g(peek()) != f(sym)) {
            push(sym);
        } else {
            pop();
        }

        i++;
    }

    postfix[j] = '\0';

    if (top != -1 || rank != 1) {
        printf("Invalid Expression\n");
    } else {
        printf("Postfix: %s\n", postfix);
    }
}

int main() {
    char infix[SIZE];
    printf("Enter infix expression (spaces allowed): ");
    scanf(" %[^\n]", infix);
    infixToPostfix(infix);
    return 0;
}
