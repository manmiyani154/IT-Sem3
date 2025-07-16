#include <stdio.h>
#define MAX 10

int stack[MAX], top = -1;

void push() {
    int val;
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &val);
    stack[++top] = val;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

void peep() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top: %d\n", stack[top]);
}

void change() {
    int pos, val;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Enter position (1 to %d): ", top + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > top + 1) {
        printf("Invalid position\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d", &val);
    stack[top - pos + 1] = val;
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {

    int ch;
    do {
        printf("\n1.Push 2.Pop 3.Peep 4.Change 5.Display 6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peep(); break;
            case 4: change(); break;
            case 5: display(); break;
            case 6: break;
            default: printf("Invalid\n");
        }
    } while (ch != 6);

    return 0;
}
