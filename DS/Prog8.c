#include <stdio.h>
#include <stdlib.h>

#define N 20

int Q[N];
int F = 0;
int R = 0;

void Enqueue() {
    int Y;
    printf("Enter value to insert: ");
    scanf("%d", &Y);

    if (R >= N) {
        printf("Queue Overflow\n");
        return;
    }
    Q[R] = Y;
    ++R;
    if (F == 0) F = 1;
    printf("Inserted: %d\n", Y);
}

int Dequeue() {
    int Y;
    if (F == 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    Y = Q[F - 1];
    if (F == R) {
        F = 0;
        R = 0;
    } else {
        F = F + 1;
    }
    printf("Deleted: %d\n", Y);
    return Y;
}

void Display() {
    if (F == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = F - 1; i < R; i++) {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: Enqueue(); break;
            case 2: Dequeue(); break;
            case 3: Display(); break;
            case 4: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
