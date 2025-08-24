#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

int stack[SIZE];   
int top = -1;      


void push(int x) {
    if (top >= SIZE - 1) {
        printf("Error: Stack overflow!\n");
        exit(1);
    }
    stack[++top] = x;
}


int pop() {
    if (top == -1) {
        printf("Error: Not enough operands\n");
        exit(1);
    }
    return stack[top--];
}

int main() {
    char exp[SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", exp);  

    int variables[26] = {0};  
    int used[26] = {0};       

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isdigit(c)) {
            push(c - '0');   
        }
        else if (isalpha(c)) {
            int idx = tolower(c) - 'a';
            if (!used[idx]) {
                printf("Enter value of %c: ", c);
                scanf("%d", &variables[idx]);
                used[idx] = 1;
            }
            push(variables[idx]);
        }
        else {
            int b = pop();
            int a = pop();

            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/':
                    if (b == 0) {
                        printf("Division by zero error!\n");
                        return 0;
                    }
                    push(a / b);
                    break;
                default:
                    printf("Unknown operator '%c'\n", c);
                    exit(1);
            }
        }
    }

    if (top == 0) {
        printf("Result = %d\n", pop());
    } else {
        printf("Invalid postfix evaluation\n");
    }

    return 0;
}
