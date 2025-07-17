#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int main() {

    char infix[100], postfix[100];
    int i = 0, j = 0;
    scanf("%s", infix);
    while (infix[i] != '\0') {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
        i++;
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("%s\n", postfix);
    return 0;
}
