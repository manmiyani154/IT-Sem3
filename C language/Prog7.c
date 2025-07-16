#include <stdio.h>
#include <ctype.h>

int stack[20], top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int main() {

    char exp[100];
    int i = 0, op1, op2;
    scanf("%s", exp);
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
        i++;
    }
    printf("%d\n", pop());
    return 0;
}
