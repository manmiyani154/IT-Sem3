#include <stdio.h>
#define MAX 10

int stack[MAX], top = -1;

void push() {
    int val;
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &val);
    stack[++top] = val;
    printf("%d pushed to stack.\n", val);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }
    printf("Popped value: %d\n", stack[top--]);
}

void peep() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top of stack: %d\n", stack[top]);
}

void change() {
    int pos, val;
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Enter position from top (1 to %d): ", top + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > top + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &val);

    stack[top - pos + 1] = val;
    printf("Value changed at position %d from top.\n", pos);
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack : ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\n1.Push  2.Pop  3.Peep  4.Change  5.Display Stack  6.Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peep(); break;
            case 4: change(); break;
            case 5: display(); break;
            case 6: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Please select from 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}
